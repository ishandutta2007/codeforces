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
//#define int long long
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
const int Y = 200100;
vector<int>Ed[Y];
//const long long m = 1000000007;
int mx;
int ans[Y];
int n, k;
int qw(int l, int r) {
    vector<int>q;
    for (int j = l; j <= r; ++j) {
        for (auto x : Ed[j])q.push_back(x);
    }
    sort(q.begin(), q.end());
    cout << "? " << q.size() << " ";
    for (auto x : q)cout << x << " ";
    cout << endl;
    int x;
    cin >> x;
    return x;
}
void Mrec(int l, int r) {
    if (l > r)return;
    if (r == l) {
        set<int>q;
        for (int j = 0; j < n; ++j) {
            q.insert(j + 1);
        }
        for (auto x : Ed[l]) {
            q.erase(q.find(x));
        }
        cout << "? " << q.size() << " ";
        for (auto x : q)cout << x << " ";
        cout << endl;
        cin >> ans[l];
        return;
    }
    int len = (r - l + 1) / 2;
    int mid = l + len - 1;
    int r1 = qw(l, mid);
    if (r1 == mx) {
        for (int j = mid + 1; j <= r; ++j)ans[j] = mx;
        if (len == 1 || l==r) {
            set<int>q;
            for (int j = 0; j < n; ++j) {
                q.insert(j + 1);
            }
            for (auto x : Ed[l]) {
                q.erase(q.find(x));
            }
            cout << "? " << q.size() << " ";
            for (auto x : q)cout << x << " ";
            cout << endl;
            cin >> ans[l];
            return;
        }
        else {
            Mrec(l, mid);
        }
    }
    else {
        for (int j = l; j <= mid; ++j)ans[j] = mx;
        ++mid;
        if (r == mid || l==r) {
            set<int>q;
            for (int j = 0; j < n; ++j) {
                q.insert(j + 1);
            }
            for (auto x : Ed[r]) {
                q.erase(q.find(x));
            }
            cout << "? " << q.size() << " ";
            for (auto x : q)cout << x << " ";
            cout << endl;
            cin >> ans[r];
            return;
        }
        else {
            Mrec(mid, r);
        }
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < k; ++i)ans[i] = 0;
        for (int i = 0; i < k; ++i) {
            Ed[i].clear();
            int tt;
            cin >> tt;
            for (int j = 0; j < tt; ++j) {
                int tmp;
                cin >> tmp;
                Ed[i].push_back(tmp);
            }
        }
        
        cout << "? " << n;
        for (int i = 1; i <= n; ++i)cout << " " << i;
        cout << endl;
        cin >> mx;
        Mrec(0, k - 1);
        cout << "! ";
        for (int i = 0; i < k; ++i)cout << ans[i] << " ";
        cout << endl;
        string s;
        cin >> s;
        if (s == "Incorrect") {
            return 0;
        }
    }
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