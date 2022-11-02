#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

struct suffix {
public:
    string s;
    vector<int> arr, sufarr;
    int n;

    suffix(string s) {
        n = s.length();
        arr.resize(n);
        vector<pair<char, int>> tmpv;
        foru(i, 0, n)tmpv.pb({ s[i], i });
        sort(tmpv.begin(), tmpv.end());//try counting
        int cur = -1;
        foru(i, 0, n) {
            if (i && tmpv[i].first == tmpv[i - 1].first)
                arr[tmpv[i].second] = cur;
            else arr[tmpv[i].second] = ++cur;
        }
        int curLen = 1;
        vector<pair<pii, int>> myvec(n);
        vector<vector<pair<pii, int>>> buckets(n);
        do {
            cur = 0;
            foru(i, 0, n) {
                buckets[arr[i ^ curLen]].pb({ {arr[i], arr[i ^ curLen]}, i });
            }
            foru(i, 0, n) {
                for (pair<pii, int> x : buckets[i])myvec[cur++] = x;
                buckets[i].clear();
            }
            cur = 0;
            foru(i, 0, n)buckets[myvec[i].first.first].pb({ myvec[i].first, myvec[i].second });
            foru(i, 0, n) {
                for (pair<pii, int> x : buckets[i])myvec[cur++] = x;
                buckets[i].clear();
            }
            cur = -1;
            foru(i, 0, n) {
                if (i && myvec[i].first == myvec[i - 1].first)
                    arr[myvec[i].second] = cur;
                else arr[myvec[i].second] = ++cur;
            }
            curLen <<= 1;
        } while (curLen < n);
        sufarr.resize(n);
        foru(i, 0, n)sufarr[arr[i]] = i;
    }
};

int n, N;
string s;


int main() { //CHECK ALL As
    fast;
    cin >> n >> s;
    N = (1 << n);
    suffix suf(s);
    int bst = suf.sufarr[0];
    foru(i, 0, N)cout << s[i ^ bst];
    return 0;
}