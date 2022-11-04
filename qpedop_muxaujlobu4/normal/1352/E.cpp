#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
using namespace std;
//const unsigned long long INF = 1e17;
const int INF = 2e7;
const int Y = 5000;
const long long m = 1000000007;
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
int a[8000];
int pref[8001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t = getint<int>();
    while (t--) {
        int n = getint<int>();
        for (int i = 0; i < n; ++i) {
            a[i] = getint<int>();
            pref[i + 1] = pref[i] + a[i];
        }
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + a[i];
        }
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            int l = 0;
            for (int r = 1; r <= n; ++r) {
                while (pref[r] - pref[l] > a[j])++l;
                if (l == r || l + 1 == r) {
                    continue;
                }
                if (pref[r] - pref[l] == a[j]) {
                    ++cnt;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}