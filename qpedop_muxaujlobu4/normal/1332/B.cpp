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
const long long INF = 100000000000000;
const int Y = 1000;
pair<int,int> arr[Y + 1];
int ans[Y + 1];
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
int del[1001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    cout.precision(15);
    int t;
    cin >> t;
    vector<int>simple;
    for (int i = 2; i <= 500; ++i) {
        if (simple.size() == 11)break;
        if (del[i] != -1) {
            simple.push_back(i);
            for (int j = i + i; j <= 500; j += i) {
                del[j] = -1;
            }
        }
    }
    arr[0] = { 0,0 };
    while (t--) {
        int n;
        cin >> n;
        int col = 0;
        for (auto x : simple)del[x] = 0;
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            cin >> arr[i].second;
            for (auto x : simple) {
                if (arr[i].second % x == 0) {
                    arr[i].first = x;
                    break;
                }
            }
            if (del[arr[i].first] == 0) {
                del[arr[i].first] = ++col;
            }
            ans[i] = del[arr[i].first];
        }
        cout << col << "\n";
        for (int i = 1; i <= n; ++i)cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}