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
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e16; 

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    string s1, s2;
    cin >> s1 >> s2;
    int time1 = (s1[0] - '0') * 600 + (s1[1] - '0') * 60 + (s1[3] - '0') * 10 + (s1[4] - '0');
    int time2 = (s2[0] - '0') * 600 + (s2[1] - '0') * 60 + (s2[3] - '0') * 10 + (s2[4] - '0');

    int time = (time1 + time2) / 2;
    cout << time / 600 << time / 60 % 10 << ":" << time / 10 % 6 << time % 10;
}