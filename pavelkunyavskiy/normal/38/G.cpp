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

const int MAXN=110000;
const int MAXSQRT=350;

vector<int> q[MAXSQRT*10];
int kol;
int maxv[MAXSQRT];
int v[MAXN];

void split(int pos){
    int sz=q[pos].size();
    if (sz<2*MAXSQRT)
        return;
    ++kol;
    for (int i=kol-1;i>pos+1;i--){
        q[i]=q[i-1];
        maxv[i]=maxv[i-1];
    }
    q[pos+1].clear();
    q[pos+1]=vector<int>(q[pos].begin()+sz/2,q[pos].end());
    q[pos].erase(q[pos].begin()+sz/2,q[pos].end());
    maxv[pos]=0;
    sz=q[pos].size();
    for (int i=0;i<sz;i++)
        maxv[pos]=max(maxv[pos],v[q[pos][i]]);
    maxv[pos+1]=0;
    sz=q[pos+1].size();
    for (int i=0;i<sz;i++)
        maxv[pos+1]=max(maxv[pos+1],v[q[pos+1][i]]);
}

void push(int pos,int nag){
    int ptr=q[pos].size();
    maxv[pos]=max(maxv[pos],v[q[pos].back()]);
    --ptr;
    for (;nag>0 && ptr>0;--nag){
        if (v[q[pos][ptr]]>v[q[pos][ptr-1]])
            swap(q[pos][ptr],q[pos][ptr-1]),ptr--;
        else
            break;
    }
    split(pos);
}

void add(int v,int nag,int num){
    ::v[num]=v;
    int ptr=kol-1;
    for (;ptr>=0;--ptr){
        assert(num==0 || q[ptr].size()>0);
        if (ptr==0 || nag<q[ptr].size() || maxv[ptr]>v){
            q[ptr].pb(num);
            push(ptr,nag);
            return;
        }
        nag-=q[ptr].size();
    }
    assert(false);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    kol=1;
    for (int i=0;i<n;i++){
        int nag,v;
        scanf("%d %d",&v,&nag);
        add(v,nag,i);
        assert(kol<=MAXSQRT*5);
    }
    for (int i=0;i<kol;i++){
        int sz=q[i].size();
        for (int j=0;j<sz;j++)
            printf("%d ",q[i][j]+1);            
    }
    printf("\n");
    return 0;
}