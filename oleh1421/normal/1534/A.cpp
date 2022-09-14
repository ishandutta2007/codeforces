#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=3010;
const ll mod=1000000007;
char a[N][N];
char c[2];
void solve(){
    int n,m;cin>>n>>m;
    c[0]=c[1]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];

        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]=='W'){
                if (c[(i+j)%2]!=0 && c[(i+j)%2]!='W'){
                    cout<<"NO\n";
                    return;
                }
                c[(i+j)%2]='W';
            } else if (a[i][j]=='R'){
                if (c[(i+j)%2]!=0 && c[(i+j)%2]!='R'){
                    cout<<"NO\n";
                    return;
                }
                c[(i+j)%2]='R';
            }
        }
    }
    if (!c[0] && !c[1]){
        c[0]='R';
        c[1]='W';
    } else if (!c[0]){
        if (c[1]=='W') c[0]='R';
        else c[0]='W';
    } else if (!c[1]){
        if (c[0]=='W') c[1]='R';
        else c[1]='W';
    } else if (c[0]==c[1]){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<c[(i+j)%2];
        cout<<endl;
    }

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}