#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

int n;
string s, t;
vector<int> a;

string sorted(string s) {
    sort(s.begin(), s.end());
    return s;
}
void solve(){
    cin >> n >> s >> t;
    if (sorted(s) != sorted(t)) {
        cout << "-1\n";
        return;
    }
    if (s == t) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) if (s[i] != t[i]) {
        a.push_back(s[i]-'0');
    }
    int cnt[2]={};
    cnt[a[0]^1] = 1; 
    for (auto x : a) {
        if (cnt[x^1]) {
            cnt[x^1]--;
            cnt[x]++;
        } else {
            cnt[x]++;
        }
    }
    cout << cnt[0]+cnt[1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}

//given a sequence of 0's and 1's
//partition it into the minimum number of alternating sequences
//