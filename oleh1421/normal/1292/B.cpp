#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
const long long mod=1000000007;
const int N=100010;
ll x[101];
ll y[101];
ll a[101];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll ax,ay,bx,by;cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
    ll xs,ys,t;cin>>xs>>ys>>t;
    int cnt=0;
    for (int i=1;i<=100;i++){
        cnt++;
        if ((x[i-1]*ax+bx)<=t+xs && (y[i-1]*ay+by)<=t+ys){
            x[i]=x[i-1];
            y[i]=y[i-1];
            x[i]*=ax;
            x[i]+=bx;
            y[i]*=ay;
            y[i]+=by;

        } else break;
    }
    for (int i=0;i<cnt;i++) a[i]=x[i]+y[i];
    int j=1;
    int maxx=0;
    //cout<<cnt<<endl;
    for (int i=0;i<cnt;i++){
        ll cur=abs(x[i]-xs)+abs(y[i]-ys);
        if (cur>t) continue;
        int pos1=lower_bound(a,a+cnt,a[i]-t+cur)-a;
        maxx=max(maxx,(i-pos1+1));
        int pos2=upper_bound(a,a+cnt,a[i]+t-cur)-a;
        pos2--;
        maxx=max(maxx,(pos2-i+1));
    }
    cout<<maxx;
    return 0;

}