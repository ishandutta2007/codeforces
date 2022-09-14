//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=553010;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<int>v;
    for (int i=1;i<=n;i++) v.push_back(a[i]);
    reverse(v.begin(),v.end());
    int cnt=0;
    while (!v.empty() && v.back()==0){
        v.pop_back();
        cnt++;
    }
    while (v.size()>1){
        vector<int>u;
        for (int i=1;i<v.size();i++) u.push_back(v[i-1]-v[i]);
        if (cnt>0){
            u.push_back(v.back());
            cnt--;
        }
        sort(u.begin(),u.end());
        reverse(u.begin(),u.end());
        v=u;
        while (!v.empty() && v.back()==0){
            v.pop_back();
            cnt++;
        }
    }
    cout<<v[0]<<endl;




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
13 4
5 6 7 8 9 10 11 12 13 1 2 3 4
5 6 7 8 1 10 11 12 13 2 3 4 9

**/