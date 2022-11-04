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
//#define double long long;
typedef long double ld;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long INF = 100000000000000;
const int Y = 200000;
const long long m = 1000000009;
int arr[Y + 1];
int v1[Y + 1];
int v2[Y + 2];
int mxx2[Y + 10];
int mxx[Y + 10];
bool val[Y + 1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>>ViVod;
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            val[i] = false;
            v1[i] = v2[i] = 0;
            mxx[i] = mxx2[i] = 0;
        }
        mxx[n + 1] = mxx2[n + 1] = 0;
        bool fal = true;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if (v1[arr[i]] == 1) {
                fal = false;
            }
            else ++v1[arr[i]];
            if (fal) {
                mxx[i] = max(mxx[i - 1], arr[i]);
                if (mxx[i] == i)val[i] = true;
            }
        }
        for (int i = n; i > 0; --i) {
            if (v2[arr[i]] == 1) {
                break;
            }
            else ++v2[arr[i]];
            mxx2[i] = max(mxx2[i + 1], arr[i]);
            if (mxx2[i] == n - i + 1) {
                if (val[i - 1]) {
                    ViVod.push_back({ i - 1,n - (i - 1) });
                }
            }
        }
        cout << ViVod.size() << "\n";
        for (auto x : ViVod) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}
/* Wed Apr 01 2020 21:05:33 GMT+0300 (MSK) */