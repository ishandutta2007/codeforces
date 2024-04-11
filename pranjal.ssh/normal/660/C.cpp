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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n); for (int &i : a) cin >> i;
    int ans = -1;
    int pos = -1;
    int i = 0, j = 0, s = 0;
    while (i < n) {
        if (j < n && s + !a[j] <= k) {
            s += !a[j];
            ++j;
        } else {
            if (j - i > ans) {
                ans = j - i;
                pos = i;
            }
            if (j > i) {
                s -= !a[i];
            }
            ++i;
            j = max(j, i);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ((i >= pos && i < pos + ans) ? 1 : a[i]) << " \n"[i + 1 == n];
    }

    return 0;
}