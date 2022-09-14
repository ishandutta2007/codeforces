#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int dp[N][6][2];
int a[N];
void solve(){
    string s;cin>>s;
    int n=s.size();
    for (int i=1;i<=n;i++){
        a[i]=(s[i-1]-'0');
    }
    int res=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            int cnt=0;
            for (int t=1;t<=n;t++){
                if (cnt%2==0 && a[t]==i) cnt++;
                else if (cnt%2==1 && a[t]==j) cnt++;
            }
            res=max(res,cnt-(i!=j)*cnt%2);
        }
    }
    cout<<n-res<<endl;
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