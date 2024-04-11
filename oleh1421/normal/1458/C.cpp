//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1019,L=20;
int a[N][N];
int x[N*N][3];
pair<int,int> val[3];
void solve(){
    int n,m;cin>>n>>m;
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int A;cin>>A;
            A--;
            cnt++;
            x[cnt][0]=i-1,x[cnt][1]=j-1,x[cnt][2]=A;
        }
    }
    for (int i=0;i<3;i++) val[i]={0,i};
    for (int it=1;it<=m;it++){
        char c;cin>>c;
        if (c=='L'){
            val[1].first--;
        } else if (c=='R'){
            val[1].first++;
        } else if (c=='D'){
            val[0].first++;
        } else if (c=='U'){
            val[0].first--;
        } else if (c=='I'){
            swap(val[1],val[2]);
        } else if (c=='C'){
            swap(val[0],val[2]);
        } else exit(1);
    }
    for (int i=1;i<=cnt;i++){
        int nx=val[0].first+x[i][val[0].second];
        nx=(nx%n+n)%n;
        int ny=val[1].first+x[i][val[1].second];
        ny=(ny%n+n)%n;
        int nz=val[2].first+x[i][val[2].second];
        nz=(nz%n+n)%n;
        a[nx+1][ny+1]=nz+1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

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
1
3 2
1 2 3
2 3 1
3 1 2
IC


1 2 3
3 1 2
2 3 1
*/