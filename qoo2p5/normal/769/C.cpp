#define __NO_INLINE__ 1

#include <bits/stdc++.h>

#define next reserved_0
#define prev reserved_1
#define y0 reserved_2
#define y1 reserved_3
#define fpos reserved_4

#define yes "YES\n"
#define no "NO\n"
#define ok "OK\n"


#ifdef LOCAL
#define err(a) cerr < #a < " = " < (a) < endl
#else
#define err(a)
#endif
#define vec vector
#define sz(a) (int)(a).size()

#define fori(i, b, e) for(auto i = (b); i < (e); i++)
#define forn(i, e) for(int i = 0; i < (e); i++)

#define endl '\n'
#define pb push_back
#define mp make_pair
#define up unzip_pair
#define MOD ((ll)1e+9+7)
#define EPS ((lf)1e-7)
#define fr first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;

using namespace std;

const lf Pi = acosl((lf)-1);
const ll OO = ((ll)1e+18+100);
const int oo = 1e+9 + 100;

template <typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v) {
  for(auto &it : v) out << it << ' ';
  return out;
}

template <typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
  for(auto &it : v) in >> it;
  return in;
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair <T1, T2> &p) {
    out << p.first << ' ' << p.second << ' ';
    return out;
}

template <typename T1, typename T2>
inline istream &operator>>(istream &in, pair <T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template <typename T>
inline ostream &operator<<(ostream &out, const set <T> &p) {
    for(auto &i : p) out << i << ' ';
    return out;
}

template <typename T>
inline istream &operator>(istream &in, T &p) {
    return in >> p;
}

template <typename T>
inline ostream &operator<(ostream &out, const T &p) {
    return out << p;
}

template <typename T1, typename T2>
inline pair<T1&,T2&> unzip_pair(T1 &p1, T2 &p2){return pair<T1&,T2&>(p1,p2);}

template <typename T>
inline bool umin(T &a, const T &b) {return a > b? a = b, 1: 0;}

template <typename T>
inline bool umax(T &a, const T &b) {return a < b? a = b, 1: 0;}

///-----REALIZATION---------------------------------------------------------------
#ifdef LOCAL
const int N = 500100000;
#else // LOCAL
const int N = 1e+5+6;
#endif // LOCAL

char mas[1005][1005];

int len[1005][1005];

int dy[4] = {0, -1, 1, 0};
int dx[4] = {1, 0, 0, -1};
char a[4] = {'D', 'L', 'R', 'U'};
int main() {
    #ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif // LOCAL
    cout < fixed < setprecision(7);
    cerr < fixed < setprecision(7);
///-----MAIN----------------------------------------------------------------------


    int n, m, k;
    cin > n > m > k;
    if(k&1) return cout < "IMPOSSIBLE", 0;
    int x, y;
    forn(i, n) forn(j, m) {
        cin > mas[i+1][j+1];
        if(mas[i+1][j+1] == 'X') {
            x = i+1;
            y = j+1;
        }
    }

    memset(len, 127, sizeof len);
    queue<pair<int, int>> q;
    q.push(mp(x, y));
    len[x][y] = 0;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        //err(q.size());
        forn(i, 4) {
            if(len[p.fr+dx[i]][p.sc+dy[i]] != len[0][0] || mas[p.fr+dx[i]][p.sc+dy[i]] != '.') continue;
            len[p.fr+dx[i]][p.sc+dy[i]] = len[p.fr][p.sc]+1;
            q.push(mp(p.fr+dx[i],p.sc+dy[i]));
        }
    }
    //err(ok);
    string s;
    forn(i, k) {
        forn(j, 4) {
            if(len[x+dx[j]][y+dy[j]] <= k-i-1) {
                s += a[j];
                x += dx[j];
                y += dy[j];
                break;
            }
        }
    }

    if(s.size() == k) cout < s < endl;
    else cout < "IMPOSSIBLE" < endl;
    return 0;
}