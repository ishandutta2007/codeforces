#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=300100;
const int Q=3000100;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N];

vector<int>g[N];
int ans[N];
void solve(){
    int n,m;cin>>n>>m;
    string s="";
    for (int i=0;i<m;i++) s+="B";
    for (int i=1;i<=n;i++){
        int pos;cin>>pos;
        pos--;
        pos=min(pos,m-pos-1);
        if (s[pos]=='A') s[m-pos-1]='A';
        else s[pos]='A';
    }
    cout<<s<<'\n';





}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

5 5 5
1 2
1 3
2 4
3 4
3 5

1 4
3 4
2 2
2 5
3 5


**/