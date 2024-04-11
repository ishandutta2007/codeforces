#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=503000;
const ll mod=998244353;
int a[2][N];
int get(vector<int>v){
    int res=0;
    for (int i=0;i<v.size();i++){
        if (v[i]==1){
            if (i+1<v.size() && v[i+1]==0){
                i++;
                res+=2;
            }
        } else {
            if (i+1<v.size() && v[i+1]==1){
                i++;
                res+=2;
            } else res++;
        }
    }
    return res;

}
void solve(){
    int n;cin>>n;
    for (int i=0;i<2;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    vector<int>v;
    int ans=0;
    for (int i=1;i<=n;i++){
        if (a[0][i]!=a[1][i]){
            ans+=2;
            ans+=get(v);
            v.clear();
        } else v.push_back(a[0][i]);
    }
    ans+=get(v);
    cout<<ans<<endl;

}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}