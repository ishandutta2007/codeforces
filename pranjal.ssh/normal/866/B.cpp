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

    int N, S; cin >> N >> S;
    vi s(N), a(N), b(N);
    ll sum = 0;
    ll ans = 0;
    priority_queue<pair<int, int>> pq;
    FOR (i, 0, N - 1) cin >> s[i] >> a[i] >> b[i], sum += s[i], ans += s[i] * 1LL * a[i], pq.emplace(b[i] - a[i], s[i]);
    pq.emplace(0, (S - sum % S) % S);
    sum += (S - sum % S) % S;
    while (sum) {
        ll profit = 0;
        ll now = 0;
        if (pq.top().F > 0 && pq.top().S > S) {
            auto it = pq.top(); pq.pop();
            ans += (it.S - it.S % S) * 1LL * it.F;
            sum -= (it.S / S) * S;
            it.S = it.S % S;
            if (it.S) pq.push(it);
            continue;
        }
        while (now < S) {
            auto it = pq.top(); pq.pop();
            profit += (min(S+0LL, now + it.S) - now) * 1LL * it.F;
            now += it.S;
            if (now > S) {
                pq.emplace(it.F, now - S);
                now = S;
            }
        }
        if (profit <= 0) break;
        ans += profit;
        sum -= S;
    }
    cout << ans;

    return 0;
}