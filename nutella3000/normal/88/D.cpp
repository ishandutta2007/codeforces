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


string f(int num) {
    string s = "";
    for(int i = 0;i < num;i++)
        s += '*';

    return s;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    map<string, int> a;
    a["void"] = 0;

    int n;  
    cin >> n;
    while(n--) {
        string type, st, to;
        cin >> type >> st;

        int l = st.find_first_not_of("&");
        int r = st.find_last_not_of("*");
        int cnt = st.size() - r - 1 - l;
        string temp = st.substr(l, r - l + 1);

        if (type == "typeof") {

            if (a.find(temp) == a.end() || a[temp] + min(0ll, cnt) < 0) cout << "errtype" << endl;
            else cout << "void" << f(a[temp] + cnt) << endl;
        }else {
            cin >> to;

            if (a.find(temp) == a.end() || a[temp] < 0) a[to] = -1;
            else a[to] = a[temp] + cnt;
        }
    }
}