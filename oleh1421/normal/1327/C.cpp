//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100050;
int x1[N];
int y1[N];
int x2[N];
int y2[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>x1[i]>>y1[i];
    for (int i=1;i<=k;i++) cin>>x2[i]>>y2[i];
    cout<<n+m+(n-1)+(m-1)*n<<endl;
    for (int i=1;i<=n;i++) cout<<"U";
    for (int i=1;i<=m;i++) cout<<"L";
    for (int i=1;i<=n;i++){
        if (i%2){
            for (int j=2;j<=m;j++) cout<<"R";
        } else {
            for (int j=m-1;j>=1;j--) cout<<"L";
        }
        if (i<n) cout<<"D";
    }

    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}


/*
1
8889
3
333 998 1
*/