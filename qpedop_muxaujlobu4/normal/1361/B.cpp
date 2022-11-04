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
//#define int long long
using namespace std;
int gcd(int i, int j) {
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
const long long INF = (int)1e7;
const int Y = 1000100;
const long long m = 1000000007;
int ar[Y];
int s[Y];
long long pw(long long et, int b) {
    if (b == 0)return 1;
    long long tmp = pw(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        for (int i = 0; i < n; ++i)cin >> ar[i];
        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }
        sort(ar, ar + n);
        int cs = 0;
        for (int i = 0; i < n; ++i) {
            s[i] = pw(p, ar[i]);
        }
        for (int r = n - 1; r >= 0; --r) {
            stack<pair<int, int>>st;
            bool lw = false;
            for (int l = r - 1; l >= 0; --l) {
                if (st.size() == 0 || st.top().first != ar[l]) {
                    st.push({ ar[l],1 });
                }
                else {
                    st.top().second++;
                }
                while (st.top().second == p) {
                    int ff, ss;
                    tie(ff, ss) = st.top();
                    st.pop();
                    if (st.size() == 0 || st.top().first != ff + 1) {
                        st.push({ ff + 1,1 });
                    }
                    else {
                        st.top().second++;
                    }
                }
                if (st.top().first == ar[r]) {
                    lw = true;
                    r = l;
                    break;
                }
            }
            if (!lw) {
                cs = s[r];
                for (int i = 0; i < r; ++i) {
                    cs = (cs - s[i] + m) % m;
                }
                r = -1;
            }
        }
        cout << cs << endl;
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */