//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//typedef __int128 ll;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
set<pair<int,int> >st[30];
map<pair<int,int>,int>mp;
void solve(){
    int n,m;cin>>n>>m;
    int cnt0=0,cnt=0;
    for (int it=1;it<=m;it++){
        char type;cin>>type;
        if (type=='+'){
            int a,b;cin>>a>>b;
            char ch;cin>>ch;
            int c=ch-'a'+1;
            if (st[c].find({b,a})!=st[c].end()) cnt++;
            st[c].insert({a,b});
            if (st[0].find({b,a})!=st[0].end()) cnt0++;
            st[0].insert({a,b});
            mp[{a,b}]=c;
        } else if (type=='-'){
            int a,b;cin>>a>>b;
            int c=mp[{a,b}];
            mp[{a,b}]=0;
            if (st[c].find({b,a})!=st[c].end()) cnt--;
            st[c].erase({a,b});
            if (st[0].find({b,a})!=st[0].end()) cnt0--;
            st[0].erase({a,b});
        } else {
            int k;cin>>k;
            if (k%2==0){
                if (cnt) cout<<"YES\n";
                else cout<<"NO\n";
            } else {
                if (cnt0) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}