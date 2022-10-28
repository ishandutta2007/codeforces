#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int sv[7001];
int mu[7001];

bitset<7001> mt[7001];
vi fac[7001];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    FOR (i, 1, 7000) sv[i] = i;
    FOR (i, 2, 100) if (sv[i] == i) for (int j = i*i; j <= 7000; j+=i) sv[j] = i;

    mu[1] = 1;
    FOR (i, 2, 7000) {
        int x = sv[i], y = i / sv[i];
        if (y % x == 0) mu[i] = 0;
        else mu[i] = mu[y] * -1;
    }


    FOR (i, 1, 7000) {
        for (int j = i; j <= 7000; j += i) {
            if (mu[j/i]) mt[i][j] = 1;
            fac[j].emplace_back(i);
        }
    }    


    int n, q; cin >> n >> q;
    vector<bitset<7001>> bt(n);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v; --x;
            bt[x].reset();
            for (int f: fac[v]) bt[x][f] = 1;
        } else if (t == 2) {
            int x, y, z; cin >> x >> y >> z; --x, --y, --z;
            bt[x] = bt[y] ^ bt[z];
        } else if (t == 3) {
            int x, y, z; cin >> x >> y >> z; --x, --y, --z;
            bt[x] = bt[y] & bt[z];
        } else if (t == 4) {
            int x, v; cin >> x >> v; --x;
            cout << ((bt[x] & mt[v]).count())%2;
        }
    }

    
    return 0;
}