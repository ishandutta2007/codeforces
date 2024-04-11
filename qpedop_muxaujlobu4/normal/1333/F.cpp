
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
#include<bitset>
#include<random>
#include<iostream>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
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
//const long long INF = 100000000000000;
const int Y = 500000;
const int INF = 1000000;

int arr[Y + 10];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    fill(begin(arr), end(arr), 1);
    vector<int>ans;
    ans.reserve(n);
    for (int i = 2; i <= n; ++i) {
        ans.push_back(arr[i]);
        for (int j = i + i; j <= n; j += i) {
            arr[j] = i;
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)cout << x << " ";
    return 0;
}