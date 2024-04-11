//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int a[N][N];
vector<int>order;
int h[N];

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            if (i!=j) a[i][j]=(c-'a');
            else a[i][j]=-1;
        }
    }
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[i][j]==a[j][i] || m%2){
                cout<<"YES\n";
                for (int t=1;t<=m+1;t++){
                    if (t%2) cout<<i<<" ";
                    else cout<<j<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    for (int i=1;i<=n;i++){
        int inA=0,inB=0,outA=0,outB=0;
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            if (a[i][j]==0) outA=j;
            else outB=j;
            if (a[j][i]==0) inA=j;
            else inB=j;
        }
        if (inA && outA){
            cout<<"YES\n";
            for (int t=1;t<=m/2+1;t++){
                if (t%2==(m/2+1)%2) cout<<i<<" ";
                else cout<<inA<<" ";
            }
            for (int t=1;t<=m/2;t++){
                if (t%2) cout<<outA<<" ";
                else cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        if (inB && outB){
            cout<<"YES\n";
            for (int t=1;t<=m/2+1;t++){
                if (t%2==(m/2+1)%2) cout<<i<<" ";
                else cout<<inB<<" ";
            }
            for (int t=1;t<=m/2;t++){
                if (t%2) cout<<outB<<" ";
                else cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<"NO\n";
    return;


}

int32_t main()
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
3 4
*aa
b*a
bb*
*/