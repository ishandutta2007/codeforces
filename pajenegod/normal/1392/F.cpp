// Not my code
// https://codeforces.com/contest/1392/submission/90176088
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long int64;
typedef long double ldb;
 
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
 
template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}
 
int main () {
    ios_base::sync_with_stdio(0);
//    cin.tie(NULL);
//  freopen("_input.txt", "rt", stdin);
//  freopen("_output.txt", "wt", stdout);
 
    int n;
    scanf("%d", &n);
 
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    
    sum -= n * (long long) (n - 1) / 2;
    long long x = sum / n;
    int r = sum % n;
 
    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
        if (i < r) {
            res[i] = i + x + 1;
        } else {
            res[i] = i + x;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
 
    return 0;
}