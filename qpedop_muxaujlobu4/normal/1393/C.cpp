#include<iostream>
#include<vector>
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
#define double long double
//#define int short
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
const long long INF = 2e17;
const long long m = 1000000007;
const int Y = 200101;
int arr[Y];
bool f(vector<int>cl, int ln) {
    priority_queue<pair<int, int>>q;
    for (int i = 0; i < cl.size(); ++i) {
        if (cl[i])q.push({ cl[i],i });
    }
    vector<vector<pair<int, int>>>way((int)cl.size() - 1);
    for (int i = 0; i < way.size(); ++i) {
        for (auto x : way[i])q.push(x);
        if (q.empty())return false;
        pair<int, int>tt = q.top();
        q.pop();
        --tt.first;
        if (tt.first == 0)continue;
        if (i + ln + 1 >= (int)way.size())return false;
        way[i + ln + 1].push_back(tt);
    }
    return true;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int b = 0, e = n + 1;
        vector<int>cl(n + 1);
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            ++cl[tmp];
        }
        while (b + 1 != e) {
            int m = (b + e) / 2;
            if (f(cl, m))b = m;
            else e = m;
        }
        cout << b << "\n";
    }
    return 0;
}