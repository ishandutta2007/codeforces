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
using namespace std;
const unsigned long long INF = 1e17;
const int INFi = 2e7;
const int Y = 200100;
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
long long arr[Y];
bool vis[101];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long hv = 1;
        long long ans = 1;
        vector<long long>Vi;
        while (ans != n) {
            if (n == ans + 2 * hv) {
                Vi.push_back(hv);
                ans += 2 * hv;
            }
            else {
                long long df = n - ans;
                if (df > 2 * hv) {
                    if (df >= 4 * hv) {
                        Vi.push_back(hv);
                        hv *= 2;
                        ans += hv;
                    }
                    else {
                        long long tmp = df / 2;
                        Vi.push_back(tmp - hv);
                        ans += tmp;
                        hv = tmp;
                    }
                }
                else {
                    Vi.push_back(df - hv);
                    ans = n;
                }
            }
        }
        cout << Vi.size() << "\n";
        for (auto x : Vi)cout << x << " ";
        cout << "\n";
    }
    return 0;
}