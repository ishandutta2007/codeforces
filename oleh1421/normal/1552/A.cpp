//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int res=s.size();
    string t=s;
    sort(t.begin(),t.end());
    for (int i=0;i<s.size();i++){
        res-=(s[i]==t[i]);
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//5 10 5 9
/**
1
10 4 2 5 3
**/