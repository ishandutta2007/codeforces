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

    string s;
    string new_s;

    bool s_have = false;

    while(getline (cin, new_s)) {
        //cout << "what " << new_s << endl;

        int id = new_s.find_first_not_of(" ");
        if (id >= new_s.size() || new_s[id] != '#') {
            s_have = true;
            id = 0;
            while(true) {
                id = min(new_s.size(), new_s.find_first_not_of(" ", id));
                if (id == new_s.size()) break;

                int new_id =  min(new_s.size(), new_s.find_first_of(" ", id)) - 1;

                s += new_s.substr(id, new_id - id + 1);

                id = new_id + 1;
            }
        }else {
            if (s_have) cout << s << endl;
            
            s = "";
            s_have = false;

            cout << new_s << endl;
            //cout << "what" << endl;
        }
    }

    if (s_have) cout << s << endl;
}