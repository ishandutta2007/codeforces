#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define endl '\n'
const int N=50010;
vector<int>g[31];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    for (int i=0;i<s.size();i++) g[s[i]-'a'].push_back(i);
    int tt;cin>>tt;
    for (int i=1;i<=tt;i++){
        int l,r;cin>>l>>r;
        l--;
        r--;
        int cnt=0;
        for (int j=0;j<26;j++){
            cnt+=(upper_bound(g[j].begin(),g[j].end(),r)!=lower_bound(g[j].begin(),g[j].end(),l));
        }
        if (r>l && s[l]==s[r] && cnt<3) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}