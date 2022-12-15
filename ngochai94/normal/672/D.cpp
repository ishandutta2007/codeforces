#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,k,lis[500005],l,r,need,s;

int main( ){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    if(n==1) {
        cout<<0;return 0;
    }
    For(i,0,n) {
        cin>>lis[i];
        s+=lis[i];
    }
    sort(lis,lis+n);
    need = 0;
    l=lis[n-1];
    For(i,1,n) {
        need+=(lis[i]-lis[i-1])*i;
        if(need>k) {
            need-=(lis[i]-lis[i-1])*i;
            l = lis[i-1] + (k-need)/i;
            // cout<<i<<' '<<need<<' '<<l<<endl;
            break;
        }
    }
    r=lis[0];
    need=0;
    for(int i=n-2;i>=0;i--) {
        need+=(lis[i+1]-lis[i])*(n-1-i);
        if(need>k) {
            need-=(lis[i+1]-lis[i])*(n-1-i);
            r = lis[i+1] - (k-need)/(n-1-i);
            // cout<<i<<' '<<need<<' '<<r<<endl;
            break;
        }
    }
    // cout<<l<<' '<<r<<endl;
    if(r-l>0) cout<<r-l;
    else {
        if(s%n==0) cout<<0;
        else cout<<1;
    }
    cout<<endl;
}