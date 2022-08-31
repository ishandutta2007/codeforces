#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 100, SZ = 1e5 + 100;

ll n, q;
map<string, ll> cnt;
map<string, string> mp;

int main() {
    fastInp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        set<string> st;
        for (int j = 0; j < s.size(); j++) {
            string cur;
            for (int t = 0; t <= s.size(); t++) {
                if (j + t >= s.size()) continue;

                cur.push_back(s[j + t]);
                st.insert(cur);
            }
        }

        for (auto cur : st) {
            cnt[cur]++;
            mp[cur] = s;
        }
    }

    cin >> q;

    while (q--) {
        string s;
        cin >> s;
        cout << cnt[s] << " ";
        if (mp.find(s) == mp.end()) {
            cout << "-\n";
            continue;
        }
        cout << mp[s] << "\n";
    }

    return 0;
}