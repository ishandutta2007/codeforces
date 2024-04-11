#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int short
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 2e17;
const long long mod = 1000000009, mod1 = 1000000007;
const double eps = 1e-13, pi = acos(-1);
const int maxN = 200101;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;

    vector<vector<long long>>a(n, vector<long long>(n, 0));
    vector<vector<long long>>l(n, vector<long long>(n, 0));
    vector<vector<long long>>r(n, vector<long long>(n, 0));
    for (int i = 1; i <= (n - 1) * 2; ++i){
        if (i < n) {
            pair<int, int>st = { i,0 };
            a[i][0] = 0;
            long long mx = 0;
            for (int j = 0; j < i; ++j) {
                st.first--;
                st.second++;
                l[st.first][st.second] = l[st.first][st.second - 1];
                if (st.first) {
                    r[st.first][st.second] = r[st.first - 1][st.second];
                }
                else {
                    r[st.first][st.second] = r[st.first][st.second - 1];
                }
                long long pl = mx + 1 - l[st.first][st.second];
                a[st.first][st.second] += pl;
                l[st.first][st.second] += pl;
                r[st.first][st.second] += pl;
                mx = r[st.first][st.second];
            }
        }
        else {
            int tmp = i - n + 1;
            a[n - 1][tmp] = 0;
            pair<int, int>st = { n - 1,tmp };
            l[st.first][st.second] = l[st.first][st.second - 1];
            r[st.first][st.second] = r[st.first - 1][st.second];
            long long mx = r[st.first][st.second];
            while (true) {
                st.first--;
                st.second++;
                if (st.first < 0 || st.second >= n)break;
                l[st.first][st.second] = l[st.first][st.second - 1];
                r[st.first][st.second] = r[st.first - 1][st.second];
                long long pl = mx + 1 - l[st.first][st.second];
                a[st.first][st.second] += pl;
                l[st.first][st.second] += pl;
                r[st.first][st.second] += pl;
                mx = r[st.first][st.second];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)cout << a[i][j] << " ";
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        long long s;
        cin >> s;
        vector<pair<int, int>>mv;
        mv.push_back({ n - 1,n - 1 });
        int i = n - 1, j = n - 1;
        while (i > 0 || j > 0) {
            s -= a[i][j];
            if (i == 0) {
                --j;
            }
            else {
                if (j == 0) {
                    --i;
                }
                else {
                    if (l[i][j - 1] <= s && s <= r[i][j - 1]) --j;
                    else --i;
                }
            }
            mv.push_back({ i,j });
        }
        reverse(mv.begin(), mv.end());
        for (auto x : mv)cout << x.first + 1 << " " << x.second + 1 << endl;
    }
    return 0;
}