#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define siz(bit) (int)bit.size()
#define all(bit) begin(bit), end(bit)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& bit, int b){ if(bit > b){ bit = b; return 1; } return 0; }
bool chmax(int& bit, int b){ if(bit < b){ bit = b; return 1; } return 0; }
   
   
   
mt19937 Rand(time(0));
int rnd(int bit) { return Rand() % bit; }
int rnd(int bit, int b) { return Rand() % (b - bit + 1) + bit; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }
   
const int inf = 1e15 + 7, mod = 1e9 + 7;
const int N = 3e3 + 3;

bool run() {
    string s, c; cin >> s >> c;
    for (int i = 0; i < siz(s); ++i) {
        if (s[i] == c[0]) {
            if (i % 2 == 0) return true;
        }
    }
    return false;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        cout << (run() ? "YES" : "NO") << endl;
    }
}