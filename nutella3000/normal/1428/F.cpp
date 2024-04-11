#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
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
#define ld long double
 
const int inf = 1e9;

int n;
deque<pii> a;
int res = 0, sum = 0, len = 0;
string s;

void add(int id) {
    len++;
    if (a.empty()) {
        sum += id + 1;
        return;
    }
    pii& temp = a.back();
    sum += id - temp.fi;
    //cout << "temp.fi " << temp.fi << endl;
    temp.fi--; temp.se--;

    if (temp.se == 0) a.pop_back();
}


void solve() {

    cin >> n >> s;
    for(int i = 0;i < n;i++) {
        if (s[i] == '0') {
            if (len != 0) {
                a.emplace_back(i - 1, len);
                len = 0;
            }
        }else {
            add(i);
        }
        res += sum;
        //cout << sum << " ";
    }

    //cout << endl;

    cout << res;
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}