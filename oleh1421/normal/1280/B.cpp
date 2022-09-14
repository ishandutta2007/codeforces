#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
bool a[155][155];
void solve(){
    int n,m;cin>>n>>m;
    bool ok=false;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='A');
            ok|=a[i][j];
        }
    }
    if (!ok){
        cout<<"MORTAL\n";
        return;
    }
    ok=true;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ok&=a[i][j];
        }
    }
    if (ok){
        cout<<"0\n";
        return;
    }
    ok=true;
    for (int i=1;i<=n;i++){
        ok&=a[i][1];
    }
    if (ok){
        cout<<"1\n";
        return;
    }
    ok=true;
    for (int i=1;i<=n;i++){
        ok&=a[i][m];
    }
    if (ok){
        cout<<"1\n";
        return;
    }
    ok=true;
    for (int i=1;i<=m;i++){
        ok&=a[1][i];
    }
    if (ok){
        cout<<"1\n";
        return;
    }
    ok=true;
    for (int i=1;i<=m;i++){
        ok&=a[n][i];
    }
    if (ok){
        cout<<"1\n";
        return;
    }

    ok=false;
    for (int i=1;i<=n;i++){
        ok|=a[i][1];
    }
    for (int i=1;i<=n;i++){
        ok|=a[i][m];
    }
    for (int i=1;i<=m;i++){
        ok|=a[1][i];
    }
    for (int i=1;i<=m;i++){
        ok|=a[n][i];
    }
    if (!ok){
        cout<<"4\n";
        return;
    }
    if (a[1][1] || a[1][m] || a[n][1] || a[n][m]){
        cout<<"2\n";
        return;
    }
    for (int i=1;i<=n;i++){
        bool ok=true;
        for (int j=1;j<=m;j++) ok&=a[i][j];
        if (ok){
            cout<<"2\n";
            return;
        }
    }
    for (int i=1;i<=m;++i){
        bool ok=true;
        for (int j=1;j<=n;j++) ok&=a[j][i];
        if (ok){
            cout<<"2\n";
            return;
        }
    }
    cout<<"3\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}