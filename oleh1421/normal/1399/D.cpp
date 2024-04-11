#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1501050;
int a[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    vector<vector<int> >s(2);
    int tot=0;
    for (int i=1;i<=n;i++){
        if (s[a[i]^1].empty()){
            s[a[i]^1].push_back(++tot);
        }
        ans[i]=s[a[i]^1].back();
        s[a[i]^1].pop_back();
        s[a[i]].push_back(ans[i]);
    }
    cout<<tot<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
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
1
7 1 2 1
1110010


1
6 1 2 1
011110
**/