#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300000, maxT = 2001;
pair<int, int> get(int i, int j) {
    ++i;
    ++j;
    cout << "? " << i << " " << j << endl;
    int v1;
    cin >> v1;
    cout << "? " << j << " " << i << endl;
    int v2;
    cin >> v2;
    if (v1 > v2) {
        return { i - 1,v1 };
    }
    else {
        return { j - 1,v2 };
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    vector<int>a(n);
    int id = 0;
    for (int j = 1; j < n; ++j) {
        pair<int, int>tmp = get(id, j);
        a[tmp.first] = tmp.second;
        if (tmp.first == id)id = j;
    }
    a[id] = n;
    cout << "! ";
    for (auto x : a)cout << x << " ";
    cout << endl;
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/