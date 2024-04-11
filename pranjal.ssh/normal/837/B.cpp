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

    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int no = count(a[0].begin(), a[0].end(), a[0][0]);
    if (no == m) {
        int tot = n*m;
        if (tot % 3) return cout << "NO\n", 0;
        tot /= 3;
        if (tot % m) return cout << "NO\n", 0;
        tot /= m;
        vector<vector<int>> cnt(3, vector<int>(3));
        vector<vector<int>> ans = {{0, 0, n*m/3}, {0, n*m/3, 0}, {n*m/3, 0, 0}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = a[i][j] == 'R' ? 0 : (a[i][j] == 'B' ? 1 : 2);
                cnt[i/tot][val]++;
            }
        }
        sort(cnt.begin(), cnt.end());
        if (cnt == ans) cout << "YES\n";
        else cout << "NO\n";

    } else {
        int tot = n*m;
        if (tot % 3) return cout << "NO\n", 0;
        tot /= 3;
        if (tot % n) return cout << "NO\n", 0;
        tot /= n;
        vector<vector<int>> cnt(3, vector<int>(3));
        vector<vector<int>> ans = {{0, 0, n*m/3}, {0, n*m/3, 0}, {n*m/3, 0, 0}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = a[i][j] == 'R' ? 0 : (a[i][j] == 'B' ? 1 : 2);
                cnt[val][j/tot]++;
            }
        }
        sort(cnt.begin(), cnt.end());
        if (cnt == ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}