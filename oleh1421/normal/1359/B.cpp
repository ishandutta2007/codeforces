//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int a[N][N];
int n,m,x,y;
int f(int len){
    return (len/2)*y+(len%2)*x;
}
void solve(){
    cin>>n>>m>>x>>y;
    y=min(y,x+x);
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            a[i][j]=1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            if (c=='.') a[i][j]=0;
        }
    }
    int res=0;
    for (int i=1;i<=n;i++){
        int len=0;
        for (int j=1;j<=m+1;j++){
            if (!a[i][j]) len++;
            else{
                res+=f(len);
                len=0;
            }
        }
    }
    cout<<res<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
0100
1110
0101
0111
*/