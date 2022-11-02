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

    map<string, int> a{{"C", 0}, {"C#", 1}, {"D", 2}, {"D#", 3}, {"E", 4},
{"F", 5}, {"F#", 6}, {"G", 7}, {"G#", 8}, {"A", 9}, {"B", 10}, {"H", 11}};
    
    bool minor = false, major = false;

    vector<string> b(3);
    cin >> b[0] >> b[1] >> b[2];
    for(int i = 0;i < 6;i++) {
        next_permutation(b.begin(), b.end());
        int num1 = (a[b[1]] - a[b[0]] + 12) % 12;
        int num2 = (a[b[2]] - a[b[1]] + 12) % 12;

        if (num1 == 3 && num2 == 4) minor = true;
        else if (num1 == 4 && num2 == 3) major = true;
    }

    if (minor) cout << "minor";
    else if (major) cout << "major";
    else cout << "strange";
}