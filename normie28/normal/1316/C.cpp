#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "petrol.inp"
#define FILE_OUT "petrol.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define endl "\n"
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
int n,m,i,j,k,t,t1,p,aad,bad,bruh[30],cnt=0,maxx=0;
int a[1000002],b[1000002];
bitset <10001> gud;
string s,md[5001];
vector<int> v;
int cmp(int a, int b)
{
    if (md[a]==md[b]) return (a<b);
    return (md[a]<md[b]);
}
int main(){
 //   ofile;
    fio;
    cin>>n>>m>>p;
    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<m;i++) cin>>b[i];
    i=0;
    while ((a[i]%p==0)and(b[i]%p==0)) i++;
    
    if ((a[i]%p)and(b[i]%p)) cout<<2*i;
    else if (a[i]%p==0) for (j=i+1;j<n;j++)
    {
        if (a[j]%p) {cout<<2*i+j-i; return 0;}
    }
    else for (j=i+1;j<m;j++)
    {
        if (b[j]%p) {cout<<2*i+j-i; return 0;}
    }
    
}