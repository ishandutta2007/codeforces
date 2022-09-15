#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
int cnt1[400001];
int cnt2[400001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,m;cin>>n>>m;
        for (int i=0;i<n;i++) cnt1[i]=0;
        for (int i=0;i<m;i++) cnt2[i]=0;
        vector<vector<int> >v(n);
        for (int i=0;i<n;i++){
            v[i].resize(m);
            for (int j=0;j<m;j++){
                char c;cin>>c;
                v[i][j]=0;
                if (c=='*'){
                    v[i][j]=1;
                    cnt1[i]++;
                    cnt2[j]++;
                }
            }
        }
        int res=n*m;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                res=min(res,n+m-cnt1[i]-cnt2[j]-(v[i][j]==0));
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
//2 6 -2 -6  2