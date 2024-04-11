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
        int n, k, c=0;
        cin >> n >> k;
        vector<int>Vi;
        for (int i = 1; i <= n; ++i)vis[i] = false;
        for (int i = 1; i <= n; ++i) {
            int tmp;
            cin >> tmp;
            if (!vis[tmp]) {
                vis[tmp] = true;
                ++c;
                Vi.push_back(tmp);
            }
        }
        if (c > k) {
            cout << "-1\n";
            continue;
        }
        if (c < k) {
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    ++c;
                    Vi.push_back(i);
                    if (c == k)break;
                }
            }
        }
        cout << Vi.size() * n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (auto x : Vi)cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}