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

#define norm(x) if (x >= MOD) x -= MOD;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

const int MOD = 1000000009;



int number[255];


struct _node;
typedef _node* node;

struct _node{
    node next[4],lnk,p;
    int len;
    int c;
    int termlen;
    int lastiter;
    int *t,*t1;
    _node(){
        memset(next,0,sizeof(next));
        lnk=p=0;
        len=0;
        c = 0;
        t = new int[12];
        t1 = new int[12];
        memset(t,0,sizeof(int)*12);
        memset(t1,0,sizeof(int)*12);
        termlen = lastiter = 0;
    }   
};

node root;

void add(){
    string s;
    cin>>s;
    node t = root;
    for (int i=0;i<(int)s.size();i++){
        if (t->next[number[(int)s[i]]] == 0){
            node tmp = new _node;
            tmp->p = t;
            t->next[number[(int)s[i]]]=tmp;
            tmp->c = number[(int)s[i]];
            tmp->len = t->len + 1;
        //  cerr<<t<<" -"<<s[i]<<"> "<<tmp<<endl;
        }
        t=t->next[number[(int)s[i]]];
    }
    t->termlen = max(t->termlen,(int)s.size());
}

void doauto(){
    queue<node> q;
    q.push(root);
    for (;!q.empty();){
        node v = q.front();q.pop();
        if (v == root){
            v->lnk = v;
            for (int i=0;i<4;i++)
                if (!v->next[i])
                    v->next[i]=v;
                else
                    q.push(v->next[i]);
        }
        else {
            if (v->p == root)
                v->lnk = v->p;
            else
                v->lnk = v->p->lnk->next[v->c];
            for (int i=0;i<4;i++)
                if (v->next[i])
                    q.push(v->next[i]);
                else
                    v->next[i] = v->lnk->next[i];           
        }
        v->termlen = max(v->termlen,v->lnk->termlen);
    }

}

int n,m;

int ITER;

void go(node v){
    if (v->lastiter == ITER)
        return;
    v->lastiter = ITER;
    for (int i=0;i<=v->len;i++)
        for (int j=0;j<4;j++){
            v->next[j]->t1[i+1] += v->t[i];
            norm(v->next[j]->t1[i+1]);
        }       
    for (int j=0;j<4;j++)
        go(v->next[j]);
}


void doswap(node v){
    if (v->lastiter == ITER)
        return;
    v->lastiter = ITER;
    swap(v->t,v->t1);
    memset(v->t1,0,sizeof(int)*12);
    for (int i=1;i<=v->termlen;i++){
        v->t[0] += v->t[i];
        v->t[i] = 0;
        norm(v->t[0]);
    }
    for (int i=v->len+1;i<12;i++)
        v->t[i] = 0;    
    for (int j=0;j<4;j++)
        doswap(v->next[j]);
}

int result;

void calcres(node v){
    if (v->lastiter == ITER)
        return;
    v->lastiter = ITER;
    result += v->t[0];
    norm(result);
    for (int j=0;j<4;j++)
        calcres(v->next[j]);

}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    number[(int)'A'] = 0;number[(int)'C'] = 1;number[(int)'G'] = 2;number[(int)'T'] = 3;
    scanf("%d %d",&n,&m);
    
    root = new _node;
    
    for (int i=0;i<m;i++)
        add();
    doauto();
    
    root->t[0] = 1;
    
    for (int i=0;i<n;i++){
        ++ITER;
        go(root);
        ++ITER;
        doswap(root);       
    }
    
    ++ITER;
    calcres(root);
    
    cout << result << endl;
    
    
    return 0;
}