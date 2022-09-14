//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=610;
const ll mod=998244353;
char a[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if (n%3==1){
        for (int i=1;i<=n;i+=3){
            for (int j=1;j<=m;j++) a[i][j]='X';
        }
        for (int i=3;i<=n;i+=3){
            bool con=false;
            for (int j=1;j<=m;j++){
                if (a[i][j]=='X' || a[i-1][j]=='X'){
                    a[i][j]=a[i-1][j]='X';
                    con=true;
                    break;
                }
            }
            if (!con) a[i-1][1]=a[i][1]='X';
        }

    } else {
        for (int i=2;i<=n;i+=3){
            for (int j=1;j<=m;j++) a[i][j]='X';
        }
        for (int i=4;i<=n;i+=3){
            bool con=false;
            for (int j=1;j<=m;j++){
                if (a[i][j]=='X' || a[i-1][j]=='X'){
                    a[i][j]=a[i-1][j]='X';
                    con=true;
                    break;
                }
            }
            if (!con) a[i-1][1]=a[i][1]='X';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<a[i][j];
        cout<<endl;
    }

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