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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

const int MAXN=110000;

int64 sum[MAXN];
int cnt[MAXN];

int key[MAXN];
int l[MAXN];
int r[MAXN];
int p[MAXN];
int minv[MAXN],maxv[MAXN];
int n;

int k;
pair<int,int> _need[MAXN];
int need[MAXN];
ld ans[MAXN];


void calcmax(int v){
    if (l[v] == -1){
        maxv[v] = key[v];
        return;
    }
    calcmax(l[v]);
    calcmax(r[v]);
    maxv[v] = maxv[r[v]];   
}

void calcmin(int v){
    if (l[v] == -1){
        minv[v] = key[v];
        return;
    }
    calcmin(l[v]);
    calcmin(r[v]);
    minv[v] = minv[l[v]];   
}

template<typename T>
void update(T* arr,int l,int r,int val){
    arr[l] += val;
    arr[r] -= val;
}

void calc(int v,int lf,int rg){
    if (lf == rg)
        return;
    if (l[v] == -1)
        return;
    int mid = lower_bound(need+lf,need+rg,key[v]) - need;
    calc(l[v],lf,mid);
    calc(r[v],mid,rg);
    update(sum,mid,rg,maxv[l[v]]);
    update(cnt,mid,rg,1);
    update(sum,lf,mid,minv[r[v]]);
    update(cnt,lf,mid,1);
}



void solve(int root){
    calcmin(root);
    calcmax(root);
    calc(root,0,k);
    for (int i=1;i<k;i++){
        sum[i] += sum[i-1];
        cnt[i] += cnt[i-1];
    }       
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d",&p[i],&key[i]);   
        if (p[i] != -1)
            --p[i];
    }
    for (int i=0;i<n;i++)
        if (p[i] !=-1){
            if (key[i] < key[p[i]])
                l[p[i]] = i;
            else
                r[p[i]] = i;
        }

    scanf("%d",&k);
    for (int i=0;i<k;i++){
        scanf("%d",&_need[i].first);
        _need[i].second = i;
    }
    sort(_need,_need+k);
    for (int i=0;i<k;i++)
        need[i] = _need[i].first;
    
    
    for (int i=0;i<n;i++)
        if (p[i] == -1) 
            solve(i);

    for (int i=0;i<k;i++)
        ans[_need[i].second] = (sum[i] / cnt[i]) + ((sum[i] % cnt[i]) * 1.0/cnt[i]);
    
    for (int i=0;i<k;i++)
        printf("%.10lf\n",(double)ans[i]);
    return 0;
}