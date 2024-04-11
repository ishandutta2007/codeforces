#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
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
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
typedef long long ll;
ll n,m,i,j,k,t,t1,a[200001],diff[200001], sum[200001],nxt[200001],used[200001],aad,bad;
vector<ll> nused,nused2;
int cmp(int a, int b)
{
    return (diff[a]<diff[b]);
}
int main(){
    cin>>n;
    for (i=0;i<n;i++)
    {
     cin>>a[i];   
    diff[i]=a[i]-i;
        nused.push_back(i);
    }
    sort(nused.begin(),nused.end(),cmp);
    sum[k]+=a[nused[0]];
    for (i=1;i<n;i++) 
    {
       if (diff[nused[i]]-diff[nused[i-1]]) k++;
       sum[k]+=a[nused[i]];
    }
    k++;
    t=0;
    for (i=0;i<k;i++) t=max(t,sum[i]);
    cout<<t;
}