#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) forn(i, a, (b) + 1)
#define NFOR(i, a, b) for (int i = a; i >= b; --i)

#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

#define foreach(c, it) for (auto it = (c).begin(); it != (c).end(); ++it)

template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
void debug(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}

const int N = 101, oo = 1e9;

int dp[N][N][N*N];
int n, volume[N], liquid[N], k, vsum = 0, lsum = 0;

int f(int idx, int bottlesUsed, int sum)    {
    if(bottlesUsed == k and sum >= lsum)    {
        return 0;
    }
    if(idx == n + 1)    {
        return -oo;
    }    

    int & ans = dp[idx][bottlesUsed][sum];
    if(~ans)    {
        return ans;
    }

    ans = f(idx + 1, bottlesUsed, sum);
    if(bottlesUsed < k) {
        ans = max(ans, liquid[idx] + f(idx + 1, bottlesUsed + 1, sum + volume[idx]));
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> volumes;
    for(int i = 1; i <= n; i++) {
        cin >> liquid[i];
        lsum += liquid[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> volume[i];
        volumes.push_back(volume[i]);
        vsum += volume[i];
    }

    sort(volumes.begin(), volumes.end());
    int tot = 0;
    k = 0;
    for(int i = n - 1; i >= 0; i--) {
        tot += volumes[i];
        k++;
        if(tot >= lsum) {
            break;
        }
    }
    
    memset(dp, -1, sizeof dp);
    int ans = lsum - f(1, 0, 0);
    cout << k << " " << ans << "\n";
    return 0;
}