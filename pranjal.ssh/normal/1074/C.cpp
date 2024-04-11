#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ii> a(n);
    int x = inf, X = -inf, y = inf, Y = -inf;
    FOR (i, 0, n - 1) {
        cin >> a[i].F >> a[i].S;
        x = min(x, a[i].F); X = max(X, a[i].F);
        y = min(y, a[i].S), Y = max(Y, a[i].S);
    }
    vi b(4);
    FOR (i, 0, n - 1) {
        if (a[i].F == x) b[0] = i;
        if (a[i].S == y) b[1] = i;
        if (a[i].F == X) b[2] = i;
        if (a[i].S == Y) b[3] = i;
    }
    int ff = 0, fff = 0;
    FOR (i, 0, 3) {
        fff += abs(a[b[i]].F-a[b[(i+1)%4]].F) + abs(a[b[i]].S-a[b[(i+1)%4]].S);
        FOR (j, i+1, 3) {
            FOR (k, 0, n - 1) if (i != k and j != k) {
                vi yo = {b[i], b[j], k}; sort(all(yo));
                int h = 0;
                FOR (it, 0, 2) h += abs(a[yo[it]].F-a[yo[(it+1)%3]].F)+abs(a[yo[it]].S-a[yo[(it+1)%3]].S);

                ff = max(ff, h);
            }
        }
    }    
    FOR (i, 3, n) {
        cout << ff << " ";
        ff = fff;
    }


    return 0;
}