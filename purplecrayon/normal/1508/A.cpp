#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<string> _a(3);
    for (auto& s : _a) cin >> s;

    for (int rep = 0; rep < 2; rep++) {
        sort(_a.begin(), _a.end());
        do {
            string a = _a[0], b = _a[1];
            if (count(a.begin(), a.end(), '1') < count(b.begin(), b.end(), '1')) {
                swap(a, b);
            }
            //cerr << a << ' ' << b << endl;
            vector<int> pos;
            for (int i = 0; i < 2*n; i++) if (a[i] == '1') pos.push_back(i);
            pos.push_back(2*n);

            vector<ar<int, 2>> v;
            int last=-1, ptr = 0;
            for (int i = 0; i < 2*n; i++) if (b[i] == '1') {
                int cnt_z = i-1-last;
                if (cnt_z)
                    v.push_back({cnt_z, pos[ptr]});
                last = i, ptr++;
            }
            {
                int cnt_z = 2*n-1-last;
                if (cnt_z)
                    v.push_back({cnt_z, pos[ptr]});
                last = n, ptr++;
            }

            //for (auto& it : v) cerr << it[0] << ' ' << it[1] << endl;

            vector<char> ans;
            int p1 = 0, p2 = 0;
            while (p1 < 2*n || p2 < sz(v)) {
                if (p1 < 2*n && a[p1] == '0') ans.push_back('0'), p1++;
                else if (p1 < 2*n && a[p1] == '1') {
                    if (p2 < sz(v) && v[p2][1] == p1) {
                        int cnt=v[p2][0];
                        while (sz(ans) && ans.back() == '0' && cnt) ans.pop_back(), cnt--;
                        while (v[p2][0]--) ans.push_back('0');
                        p2++;
                    } else {
                        ans.push_back('1');
                        p1++;
                    }
                } else {
                    assert(v[p2][1] == p1);
                    int cnt=v[p2][0];
                    while (sz(ans) && ans.back() == '0' && cnt) ans.pop_back(), cnt--;
                    while (v[p2][0]--) ans.push_back('0');
                    p2++;
                }
            }
            if (sz(ans) <= 3*n){
                for (auto c : ans) cout << (rep?char(c^'0'^'1'):c);
                cout << '\n';
                return;
            }
        } while (next_permutation(_a.begin(), _a.end()));
        for (int j = 0; j < 3; j++) for (int i = 0; i < 2*n; i++) _a[j][i] ^= '0'^'1';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}