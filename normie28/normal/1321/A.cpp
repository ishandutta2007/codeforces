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
int n,m,i,j,k,t,t1,a[101],b[101],aad,bad;
int main(){
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n;i++)
    {
        cin>>b[i];
        if (a[i]>b[i]) aad++;
        if (a[i]<b[i]) bad++;
    }
    if (aad==0) {cout<<-1;}
    else if (aad>bad) cout<<1;
    else cout<<1+ceil(double(bad-aad+1)/aad);
}