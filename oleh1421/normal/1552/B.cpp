//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
int a[N][5];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<5;j++) cin>>a[i][j];
    }
    int ans=1;
    for (int i=2;i<=n;i++){
        int cnt=0;
        for (int j=0;j<5;j++) cnt+=(a[ans][j]<a[i][j]);
        if (cnt<3) ans=i;
    }
//    cout<<ans<<endl;
    for (int i=1;i<=n;i++){
        if (i==ans) continue;
        int cnt=0;
        for (int j=0;j<5;j++) cnt+=(a[ans][j]<a[i][j]);
        if (cnt<3){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;

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
//5 10 5 9
/**
1
10 4 2 5 3
**/