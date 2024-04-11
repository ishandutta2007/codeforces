#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

<<<<<<< HEAD
bool done(int i, int j) {
    cout << i << ' ' << j << endl;
    string s; cin >> s;
    return s == "Done";
}
void solve(){
    for (int rep = 0; rep < 2; rep++) {
        for (int i = 1; i <= 8; i++) {
            if (i&1) {
                for (int j = 1; j <= 8; j++) {
                    if (done(i, j)) return;
                }
            } else {
                for (int j = 8; j >= 1; j--) {
                    if (done(i, j)) return;
                }
            }
        }
    }
=======
int cnt_queries = 0;
bool done(string c) {
    return c == "Done";
}
bool down(string c) {
    return c.substr(0, 4) == "Down";
}
bool up(string c) {
    return c.substr(0, 2) == "Up";
}
bool left(string c) {
    return c.substr(sz(c)-4, 4) == "Left";
}
string move(int r, int c) {
    r++, c++;
    cnt_queries++;

    // while (cnt_queries > 130);

    cout << r << ' ' << c << endl;
    string s; cin >> s;
    return s;
}
void sweep(int r, int c, bool move_row) { //sweep some row
    if (move_row) {
        string cur = move(r, c);
        if (done(cur)) return;
        if (down(cur)) {
            sweep(r+1, c, 1);
            return;
        }
    }
    if (c) {
        string cur = move(r, 0); c = 0;
        if (done(cur)) return;

        if (down(cur)) {
            sweep(r+1, c, 1);
            return;
        }
    }
    for (int i = 1; i < 8; i++) {
        string cur = move(r, i); c = i;
        if (done(cur)) {
            return;
        }
        if (down(cur)) {
            sweep(r+1, c, 1);
            return;
        }
        if (up(cur)) {
            sweep(r, c, 0);
            return;
        }
    }
    sweep(r+1, c, 1);
}
void solve(){
    cnt_queries = 0;
    if (done(move(0, 1))) {
        return;
    }
    sweep(0, 0, 1);
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}