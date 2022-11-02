#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

const int N = 205;
int dp[N][N][N]; //p1, p2, balance

struct pos {
    int p1 = -1, p2 = -1, balance;
    pos() {}
    pos(int p1, int p2, int balance) {
        this->p1 = p1;
        this->p2 = p2;
        this->balance = balance;
    }
};

pos p[N][N][N];


signed main() {
    FAST; FIXED; RANDOM;
    string s, t;
    cin >> s >> t;
    s = '0' + s;
    t = '0' + t;
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    for (int k = 0; k < N; ++k)
        dp[i][j][k] = mod;
    for (int balance = 0; balance < N; ++balance)
        dp[0][0][balance] = balance;
    for (int p1 = 0; p1 < sz(s); ++p1)
        for (int p2 = 0; p2 < sz(t); ++p2)
            if (p1 > 0 || p2 > 0) {
                for (int balance = 0; balance < N; ++balance) {
                    pos& past = p[p1][p2][balance];
                    if (balance > 0) {
                        if (s[p1] == '(') {
                            if (ifmin(dp[p1][p2][balance], dp[p1 - 1][p2][balance - 1] + 1))
                                past = {p1 - 1, p2, balance - 1};
                        }
                        if (t[p2] == '(') {
                            if (ifmin(dp[p1][p2][balance], dp[p1][p2 - 1][balance - 1] + 1))
                                past = {p1, p2 - 1, balance - 1};
                        }
                        if (s[p1] == '(' && t[p2] == '(') {
                            if (ifmin(dp[p1][p2][balance], dp[p1 - 1][p2 - 1][balance - 1] + 1))
                                past = {p1 - 1, p2 - 1, balance - 1};
                        }
                    }

                    if (s[p1] == ')') {
                        if (ifmin(dp[p1][p2][balance], dp[p1 - 1][p2][balance + 1] + 1))
                            past = {p1 - 1, p2, balance + 1};
                    }
                    if (t[p2] == ')') {
                        if (ifmin(dp[p1][p2][balance], dp[p1][p2 - 1][balance + 1] + 1))
                            past = {p1, p2 - 1, balance + 1};
                    }
                    if (s[p1] == ')' && t[p2] == ')') {
                        if (ifmin(dp[p1][p2][balance], dp[p1 - 1][p2 - 1][balance + 1] + 1))
                            past = {p1 - 1, p2 - 1, balance + 1};
                    }
                }
            }


    pair<int, pos> ans;
    ans.f = mod;
    for (int balance = 0; balance < N; ++balance)
        if (ifmin(ans.f, dp[sz(s) - 1][sz(t) - 1][balance] + balance))
            ans.s = pos(sz(s) - 1, sz(t) - 1, balance);

    pos curr = ans.s;
    string answer(curr.balance, ')');

    pos check = p[1][2][0];

    while (curr.p1 > 0 || curr.p2 > 0) {
        if (curr.balance > p[curr.p1][curr.p2][curr.balance].balance) answer = '(' + answer;
        else answer = ')' + answer;
        curr = p[curr.p1][curr.p2][curr.balance];
    }   

    while (curr.balance) answer = '(' + answer, --curr.balance;

    cout << answer;
    
    return 0;
}