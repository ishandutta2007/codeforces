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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>vi;
        if (n % 2 == 1 && k % 2 == 0 || k > n) {
            cout << "NO\n";
            continue;
        }
        if (n % 2 == 0) {
            if (k % 2 == 1) {
                while (k > 1) {
                    vi.push_back(2);
                    n -= 2;
                    --k;
                }
                vi.push_back(n);
                if (n <= 0) {
                    cout << "NO\n";
                    continue;
                }
            }
            else {
                while (k > 1) {
                    vi.push_back(1);
                    --n;
                    --k;
                }
                vi.push_back(n);
            }
        }
        else {
            while (k > 1) {
                vi.push_back(1);
                --n;
                --k;
            }
            vi.push_back(n);
        }
        cout << "YES\n";
        for (auto x : vi)cout << x << " ";
        cout << "\n";
    }
    return 0;
}