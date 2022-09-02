#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

struct node{
    node *next,*back,*prev;
    int to,from,w;
};

node* g[110000];
node* gt[110000];

void add(int a,int b,int w){
    node* tmp=new node;
    node* tmp2=new node;
    tmp->to=b;
    tmp2->to=a;
    tmp->from=a;
    tmp2->from=b;
    tmp->back=tmp2;
    tmp2->back=tmp;
    tmp->w=tmp2->w=w;
    tmp->next=g[a];
    tmp->prev=0;
    if (g[a])
        g[a]->prev=tmp;
    g[a]=tmp;
    tmp2->next=gt[b];
    tmp2->prev=0;
    if (gt[b])
        gt[b]->prev=tmp2;   
    gt[b]=tmp2;
}

void del(node* tmp){
    if (gt[tmp->from]==tmp){
        gt[tmp->from]=tmp->next;
        if (tmp->next)
            tmp->next->prev=0;
    }
    else {
        tmp->prev->next=tmp->next;
        if (tmp->next)
            tmp->next->prev=tmp->prev;
    }
    tmp=tmp->back;
    if (g[tmp->from]==tmp){
        g[tmp->from]=tmp->next;
        if (tmp->next)
            tmp->next->prev=0;  
    }
    else {
        tmp->prev->next=tmp->next;
        if (tmp->next)
            tmp->next->prev=tmp->prev;
    }   
}

const int inf=1<<28;

int d[110000];
set<pair<int,int> > s;
vector<int> today;
int used[110000];
int cnt;
int n;

int obrob(int v){
    if (used[v]==0)
        return v;
    if (used[v]==2)
        return -1;      
    if (!g[v]){
        for (node* it=gt[v];it;){
            node* tmp=it->next;
            del(it);
            it=tmp;
        }
        used[v]=3;
        return -1;
    }
    used[v]=2;
    int tmp=obrob(g[v]->to);
    if (tmp==-1){
        for (node* it=gt[v];it;){
            node* tmp=it->next;
            del(it);
            it=tmp;
        }
        if (g[v])
            del(g[v]->back);
        used[v]=3;
        return -1;
    }   
    for (node* it=gt[v];it;){
        node* Tmp=it->next;
        int p=it->to;
        int w=it->w;
        del(it);
        if (p!=tmp)
            add(p,tmp,w+g[v]->w);
        it=Tmp;
    }   
    used[v]=3;
    return tmp;
}

void solve(int a,int b){
    s.clear();
    d[a]=0;
    s.insert(mp(0,a));
    cnt=0;
    if (used[a]==3)
        cnt--;
    for (;!s.empty();){
        int v=s.begin()->second;
        cnt++;
        used[v]=1;
        s.erase(s.begin());
        for (node* it=g[v];it;it=it->next){
            if (d[v]+(it->w) <b && d[it->to]>d[v]+(it->w)){
                s.erase(mp(d[it->to],it->to));
                d[it->to]=d[v]+(it->w);
                s.insert(mp(d[it->to],it->to));
            }
        }
    }
    
    obrob(a);
    
    printf("%d\n",cnt);
}

int v[110000];




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0;i<n;i++){
        int tmp=0;
        scanf("%d",&tmp);
        add(i,tmp-1,1);
    }
    for (int i=0;i<m;i++)
        scanf("%d",&v[i]);
    for (int i=0;i<n;i++)
        d[i]=(1<<29);

    int last=0;
    for (int i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        last=(last+v[i]-1+n)%n;
        solve(last,b);
        last=cnt;
    }       
    return 0;
}