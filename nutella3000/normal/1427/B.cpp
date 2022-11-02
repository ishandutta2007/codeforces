#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;

bool check(vector<int> a) {
    int sum = 0;
    for(int i : a) {
        sum += i;
        if (sum == 0) return false;
    }
    return true;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;


    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a;
        int l = 0, cnt = 0;
        int res = 0;

        for(int i = 0;i <= s.size();i++) {
            if (i != 0 && (i == s.size() || s[i] != s[i - 1])) {
                if (s[i - 1] == 'W') {
                    res += 2 * l - 1;
                }else{
                    cnt += l;
                    if (i != s.size() && l != i) a.emplace_back(l);
                }
                l = 1;
            }else if (i != s.size()) {  
                l++;
            }
        }

        if (cnt == n && k != 0) {
            res++;
            cnt--;
            k--;
        }
        res += 2 * min(k, cnt);

        sort(all(a));

        for(int i : a) {
            if (i > k) break;
            res++;
            k -= i;
        }
        cout << res << endl;
    }
}