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
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>

void boostIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

template<typename T> T getint() {
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

int main()
{
    boostIO();
    int t;
    cin >> t;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        vector<long long>a;
        vector<long long>pw;
        for (long long tmp = 1; tmp <= 1e16; tmp *= k) {
            a.push_back(0);
            pw.push_back(tmp);
        }
        bool res = true;
        for (int i = 0; i < n; ++i) {
            long long d = 1;
            long long tmp;
            cin >> tmp;
            for (int j = a.size()-1; j >=0 && tmp; --j) {
                if (tmp >= pw[j]) {
                    long long tt = tmp % pw[j];
                    a[j] += (tmp - tt) / pw[j];
                    tmp %= pw[j];
                }
            }
        }
        for (auto x : a)res &= x <= 1;
        if (res)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}