//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
ll x[N],y[N];
void solve(){
    int n;cin>>n;
    int n1=0,n2=0;
    for (int i=1;i<=n*2;i++){
        int a,b;cin>>a>>b;
        if (a) x[++n1]=abs(a);
        else y[++n2]=abs(b);
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    double res=0.0;
    for (int i=1;i<=n;i++){
        res+=sqrtl(x[i]*x[i]+y[i]*y[i]);
    }
    cout<<setprecision(10)<<fixed<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
1 2 2 2
*/