#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    set<char> a{'a', 'e', 'i', 'o', 'u'};

    string s;

    int id = 0;
    vector<int> cnt(3);
    while(getline(cin, s)) {
        for(char i : s) {
            if (a.find(i) != a.end()) cnt[id]++;
        }
        id++;
    }

    if (cnt[0] == 5 && cnt[1] == 7 && cnt[2] == 5) cout << "YES";
    else cout << "NO";
}