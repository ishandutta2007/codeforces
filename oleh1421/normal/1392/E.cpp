#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=26;
ll a[N][N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int cur=min(n-i,j-1);
            if (cur%2==0) a[i][j]=0;
            else a[i][j]=(1ll<<(i+j-3));
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int tt;cin>>tt;
    while (tt--){
        ll k;cin>>k;
        int x=1,y=1;
        cout<<x<<" "<<y<<endl;
        for (int i=2;i<=n*2-1;i++){
            if (x==n) y++;
            else if (y==n) x++;
            else {
                if (a[x+1][y]){
                    if (k&a[x+1][y]) x++;
                    else y++;
                } else {
                    if (k&a[x][y+1]) y++;
                    else x++;
                }
            }
            cout<<x<<" "<<y<<endl;
        }
    }

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}