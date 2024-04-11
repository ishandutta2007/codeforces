#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

const int N = 1e8;
bitset < N + 1 > B;
int n;
unsigned int a, b, c, d;

inline unsigned int f(unsigned int p) {
    return d + p * (c + p * (b + p * a));
}

inline unsigned int get(int i) {
    unsigned int x = n / i, ans = 0;

    while (x) {
        ans += x;
        x /= i;
    }
    return ans;
}
vi p;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    p = {2};
    for (int i = 3; i <= 17320; i += 2) if (B[i] == 0) {
        p.push_back(i);
        for (int j = i * i; j <= N; j += i) B[j] = 1;
    }

    cin >> n;
    cin >> a >> b >> c >> d;
    unsigned int ans = f(2) * get(2);
    for (int i = 3; i <= min(n, N); i += 2) if (B[i] == 0) {
            ans += f(i) * get(i);
        }

    if (n > N) {
        B.reset();
        for (int i : p) {
            for (int j = ((N+i)/i)*i; j <= N + N; j += i) {B[j - N] = 1;}
        }


        for (int i = N+1; i <= min(n, N+N); i += 2) if (B[i-N] == 0) {
            ans += f(i) * get(i);
        }

        if (n > N + N) {
            B.reset();
            for (int i : p) {
                for (int j = ((N+N+i)/i)*i; j <= N + N + N; j += i) B[j - N - N] = 1;
            }
            for (int i = N+N+1; i <= min(n, N+N+N); i += 2) if (B[i-N-N] == 0) {
                ans += f(i) * get(i);
            }
        }
    }
    cout << ans;


    return 0;
}