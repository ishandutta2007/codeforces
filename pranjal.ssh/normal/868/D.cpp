#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int MAGIC = 10;

struct HugeString {
    bitset<1 << MAGIC> bst[MAGIC + 1];
    string prefix, suffix;
};
HugeString hs[201];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    FOR (it, 1, n) {
        string s; cin >> s;
        hs[it].prefix = s.substr(0, min(sz(s), MAGIC));
        hs[it].suffix = s.substr(max(0, sz(s) - MAGIC));
        FOR (i, 0, sz(s) - 1) {
            int x = 0;
            FOR (j, i, min(i + MAGIC - 1, sz(s) - 1)) {
                x <<= 1;
                x |= (s[j] - '0');
                hs[it].bst[j - i + 1].set(x);
            }
        }
    }


    int m; cin >> m; FOR (cur, n + 1, n + m) {
        int a, b; cin >> a >> b;
        FOR (i, 0, MAGIC) {
            hs[cur].bst[i] = hs[a].bst[i];
            hs[cur].bst[i] |= hs[b].bst[i];
        }
        string t = hs[a].suffix + hs[b].prefix;
        FOR (i, 0, sz(t) - 1) {
            int x = 0;
            FOR (j, i, sz(t) - 1) {
                if (j - i + 1 > MAGIC) break;
                x <<= 1;
                x |= (t[j] - '0');
                hs[cur].bst[j - i + 1].set(x);
            }
        }
        hs[cur].prefix = hs[a].prefix;
        if (hs[cur].prefix.length() < MAGIC) {
            hs[cur].prefix += hs[b].prefix.substr(0, MAGIC - hs[cur].prefix.length());
        }
        hs[cur].suffix = hs[b].suffix;
        if (hs[cur].suffix.length() < MAGIC) {
            int len = MAGIC - hs[cur].suffix.length();
            hs[cur].suffix = hs[a].suffix.substr(max(0, sz(hs[a].suffix) - len)) + hs[cur].suffix;
        }
        int ans = 0;
        FOR (i, 1, MAGIC) {
            if (hs[cur].bst[i].count() == (1 << i)) {
                ++ans;
            } else {
                break;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}