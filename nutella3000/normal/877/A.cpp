#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    string s;
    cin >> s;
    vector<string> a = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

    int cnt = 0;
    for(string b : a) {
        int sz = b.size();
        for(int i = 0;i < s.size() - sz + 1;i++) {
            string q = s.substr(i, sz);
            //cout << q << " " << b << endl;
            if (q == b) cnt++;
        }
    }
    cout << (cnt == 1 ? "YES" : "NO");
}