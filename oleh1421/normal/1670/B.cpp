#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=(1<<19);
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    set<char>st;
    int k;cin>>k;
    for (int i=1;i<=k;i++){
        char c;cin>>c;
        st.insert(c);
    }
    vector<int>v;
    for (int i=0;i<n;i++){
        if (st.find(s[i])==st.end()) v.push_back(0);
        else v.push_back(1);
    }
    int last=-1;
    int res=0;
    for (int i=(int)v.size()-1;i>=0;i--){
        res=max(res,last-i);
        if (v[i]) last=i;
    }
    cout<<res<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
3 3
30 10 40
20 50 60
60 60 50

1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/