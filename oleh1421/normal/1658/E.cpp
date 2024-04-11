#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
const int SZ=7000010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
int x[N*N],y[N*N];
int a[N][N];
char ans[N][N];
void solve(){
    int n,k;cin>>n>>k;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            x[n*n-a[i][j]+1]=i;
            y[n*n-a[i][j]+1]=j;

        }
    }

    vector<int>W;
    int mx[2][2];
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            mx[i][j]=-1000000001;
        }
    }
    for (int p=1;p<=n*n;p++){
        bool win=true;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if ((2*i-1)*x[p]+(2*j-1)*y[p]+mx[i][j]>k){
                    win=false;
                }
            }
        }

        if (win) {
            W.push_back(p);
            ans[x[p]][y[p]]='M';
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++){
                    mx[i][j]=max(mx[i][j],(1-2*i)*x[p]+(1-2*j)*y[p]);
                }
            }
        } else {
            ans[x[p]][y[p]]='G';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<ans[i][j];
        cout<<endl;
    }



}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
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