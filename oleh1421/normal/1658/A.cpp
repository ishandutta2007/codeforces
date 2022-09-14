#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=c-'0';
    }
    int last=-100000001;
    int res=0;
    for (int i=1;i<=n;i++){
        if (a[i]==0) {
            res+=max(0,last-i+3);
            last=i;
        }
    }
    cout<<res<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2


//
//1 2

/**

**/