#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1500100;
int p[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) p[i]=0;
    for (int i=1;i<=n;i++){
        if (p[i]) continue;
        vector<int>v;
        cout<<"? "<<i<<endl;
        int f;cin>>f;
        v.push_back(f);
        while (true){
            cout<<"? "<<i<<endl;
            int ans;cin>>ans;
            v.push_back(ans);
            if (ans==f) break;
        }
        for (int i=1;i<v.size();i++){
            p[v[i-1]]=v[i];
        }
    }
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
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
/**


**/