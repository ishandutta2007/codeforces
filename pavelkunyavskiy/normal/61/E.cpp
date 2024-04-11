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


const int MAXN=int(1e6)+1000;

int64 fen1[MAXN];
int64 fen2[MAXN];
int n;


void update(int64* fen,int pos,int val){
    for (;pos<n;pos=pos|(pos+1))
        fen[pos]+=val;
}

int64 sum(int64* fen,int pos){
    int64 ans=0;
    for (;pos!=-1;pos=(pos&(pos+1))-1)
        ans+=fen[pos];
    return ans;
}

pair<int,int> a[MAXN];


bool cmpsec(const pair<int,int>& a,const pair<int,int>& b){
    return a.second < b.second;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i=0;i<n;i++)
        a[i].first=n-i-1;
    sort(a,a+n,cmpsec);
    
    int64 ans=0;
    
    for (int i=0;i<n;i++){
        ans+=sum(fen2,a[i].first-1);
        update(fen2,a[i].first,sum(fen1,a[i].first-1));
        update(fen1,a[i].first,1);
    }
    
    cout<< ans << endl;
    
    return 0;
}