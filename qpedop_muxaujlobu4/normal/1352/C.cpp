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
        long long n, k;
        cin >> n >> k;
        long long ct = n - 1;
        long long tmp = k / ct;
        long long st = n * tmp;
        k -= ct * tmp;
        if (k == 0) {
            cout << st - 1 << "\n";
        }
        else {
            cout << st + k << "\n";
        }
    }
    return 0;
}