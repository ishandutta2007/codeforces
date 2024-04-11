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
long long INF = 1e17;
//const long long m = 1000000007;
const int Y = 200100;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, inv = 0;
        cin >> n;
        bool same = false;
        vector < pair<int, int> > a(n);
        vector<int>ans;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j].first > a[i].first)++inv;
                if (a[j].first == a[i].first)same = true;
            }
        }
        if (!same && inv % 2 == 1) {
            cout << "-1\n";
            continue;
        }
        vector < pair<int, int> > ch = a;
        sort(ch.begin(), ch.end());
        for (int i = 0; i < n - 2; ++i) {
            vector < pair<int, int> > id;
            for (int j = i; j < n; ++j)if (ch[i].first == a[j].first)id.push_back({ a[j].second,j });
            sort(id.begin(), id.end());
            if (inv % 2 == 1 && id.size() >= 2) {
                inv = 0;
                int j = id[1].second;
                while (i + 1 < j) {
                    pair<int,int> t1 = a[j - 2], t2 = a[j - 1], t3 = a[j];
                    ans.push_back(j - 1);
                    a[j] = t2;
                    a[j - 1] = t1;
                    a[j - 2] = t3;
                    j -= 2;
                }
                if (i + 1 == j) {
                    ans.push_back(j);
                    ans.push_back(j);
                    pair<int, int> t1 = a[j - 1], t2 = a[j], t3 = a[j + 1];
                    a[j - 1] = t2;
                    a[j] = t3;
                    a[j + 1] = t1;
                }
            }
            else {
                int j = id[0].second;
                while (i + 1 < j) {
                    pair<int, int> t1 = a[j - 2], t2 = a[j - 1], t3 = a[j];
                    ans.push_back(j - 1);
                    a[j] = t2;
                    a[j - 1] = t1;
                    a[j - 2] = t3;
                    j -= 2;
                }
                if (i + 1 == j) {
                    ans.push_back(j);
                    ans.push_back(j);
                    pair<int,int> t1 = a[j - 1], t2 = a[j], t3 = a[j + 1];
                    a[j - 1] = t2;
                    a[j] = t3;
                    a[j + 1] = t1;
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto x : ans)cout << x << " ";
        cout << "\n";
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