//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
mt19937 rnd(time(nullptr));
int val[N];
int suf[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>val[i];
        a[i]=val[i];
        val[i]-=val[i-1];
    }
    suf[n+1]=1000000001;
    suf[n+2]=1000000001;
    for (int i=n;i>=1;i--){
        suf[i]=min(suf[i+2],val[i]);
    }
    if (min(suf[1],suf[2])>=0 && val[n]==0){
        cout<<"YES\n";
        return;
    }
    for (int i=1;i<n;i++){
        int d=a[i+1]-a[i];
        if (i%2==n%2){
            if (val[n]+d*2==0 && min({val[i]+d,suf[i+1]-2*d,suf[i+2]+2*d})>=0){
                cout<<"YES\n";
                return;
            }
        } else {
            if (val[n]-d*2==0 && min({val[i]+d,suf[i+1]-2*d,suf[i+2]+2*d})>=0){
                cout<<"YES\n";
                return;
            }
        }
        if (val[i]<0) break;
    }
    cout<<"NO\n";
}
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

//4 1 2 3
//3 1 2 4
//2 1 3 4
//1 2 3 4
//2 3 1
//a[i]-a[i-1]+a[i-2]-a[i-3]+...