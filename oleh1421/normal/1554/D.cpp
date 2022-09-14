//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=500010;
ll a[N];
void solve(){
    int n;cin>>n;
    if (n==1){
        cout<<'a'<<endl;
        return;
    } else if (n%2==0){
        int k=(n-2)/2;
        for (int i=1;i<=k;i++) cout<<'a';
        cout<<'b';
        for (int i=1;i<=k+1;i++) cout<<'a';
        cout<<endl;
    } else {
        int k=(n-3)/2;
        for (int i=1;i<=k;i++) cout<<'a';
        cout<<'b'<<'c';
        for (int i=1;i<=k+1;i++) cout<<'a';
        cout<<endl;
    }
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}