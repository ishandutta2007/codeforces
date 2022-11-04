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
using namespace std;
int gcd(int i, int j) {
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
const long long INF = 1e17;
const long long m = 1000000007;
const int Y = 200100;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    multiset<long long>ba;
    multiset<long long>b;
    multiset<long long>a;
    for (int i = 0; i < n; ++i) {
        int aa, bb;
        long long tmp;
        cin >> tmp >> aa >> bb;
        if (aa == 0) {
            if (bb == 0) {
            }
            else {
                b.insert(tmp);
            }
        }
        else {
            if (bb == 0) {
                a.insert(tmp);
            }
            else {
                ba.insert(tmp);
            }
        }
    }
    if (a.size() + ba.size() < k) {
        cout << -1;
        return 0;
    }
    if (b.size() + ba.size() < k) {
        cout << -1;
        return 0;
    }
    if (k - (int)ba.size() + k > n) {
        cout << -1;
        return 0;
    }
    long long ans = 0;
    stack<long long>aa, bb;
    while (true) {
        if (n == k)break;
        if (a.empty()||b.empty()||k==0)break;
        aa.push(*(a.begin()));
        bb.push(*(b.begin()));
        ans += bb.top() + aa.top();
        a.erase(a.begin());
        b.erase(b.begin());
        n -= 2;
        --k;
    }
    for (; k; --k, --n) {
        ans += *(ba.begin());
        ba.erase(ba.begin());
    }
    while (aa.size()>0&&bb.size()>0&&ba.size()>0) {
        if (aa.top() + bb.top() > *(ba.begin())) {
            ans -= aa.top();
            ans -= bb.top();
            aa.pop();
            bb.pop();
            ans += *(ba.begin());
            ba.erase(ba.begin());
        }
        else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */