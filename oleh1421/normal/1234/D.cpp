#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
set<int>st[31];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    for (int i=0;i<s.size();i++){
        st[s[i]-'a'].insert(i);
    }
    int tt;cin>>tt;
    while (tt--){
        int type;cin>>type;
        if (type==1){
            int pos;cin>>pos;pos--;
            char c;cin>>c;
            st[s[pos]-'a'].erase(pos);
            s[pos]=c;
            st[s[pos]-'a'].insert(pos);

        } else {
            int l,r;cin>>l>>r;
            l--;
            r--;
            int cnt=0;
            for (int i=0;i<='z'-'a';i++){
                auto it=st[i].lower_bound(l);
                if (it!=st[i].end() && (*it)<=r) {
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}