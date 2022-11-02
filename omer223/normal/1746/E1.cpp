#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
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
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

bool ask(vector<int> v) {
    cout << "? ";
    cout << v.size() << ' ';
    for (int x : v)cout << x << ' ';
    cout << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return (ans == "YES");
}

bool answer(int x) {
    cout << "! " << x << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return (ans == ":)");
}

int main() {
    fast;
    int n;
    cin >> n; //N<=4
    vector<int> cand;
    int totq = 0;
    for (int i = 1; i <= n; i++)cand.push_back(i);
    while (n >= 4) {
        int qua = n / 4, rem = n % 4;
        pair<vector<int>, vector<int>> ab[2];
        int idx = 0;
        int ctr = 0;
        while (ctr < qua) {
            ab[0].ff.push_back(cand[idx++]);
            ctr++;
        }
        ctr = 0;
        while (ctr < qua + (rem>=3)) {
            ab[0].ss.push_back(cand[idx++]);
            ctr++;
        }
        ctr = 0;
        while (ctr < qua + (rem>=2)) {
            ab[1].ff.push_back(cand[idx++]);
            ctr++;
        }
        ctr = 0;
        while (ctr < qua + (rem>=1)) {
            ab[1].ss.push_back(cand[idx++]);
            ctr++;
        }




        vector<int> abv[2];
        foru(i, 0, 2) {
            for (int x : ab[i].ff)abv[i].push_back(x);
            for (int x : ab[i].ss)abv[i].push_back(x);
        }
        bool as = ask(abv[0]);
        if (!as) {
            swap(ab[0], ab[1]);
            swap(abv[0], abv[1]);
        }
        vector<int> u;
        foru(i, 0, 2) {
            for (int x : ab[i].ff)u.push_back(x);
        }
        bool as2 = ask(u);
        if (!as2) {
            swap(ab[0].ff, ab[0].ss);
            swap(ab[1].ff, ab[1].ss);
        }
        cand.clear();
        for (int x : ab[0].ff)cand.push_back(x);
        for (int x : ab[1].ff)cand.push_back(x);
        for (int x : ab[0].ss)cand.push_back(x);
        n = cand.size();
    }
    if (cand.size() <= 2) {
        for (int x : cand) {
            if (answer(x))break;
        }
        return 0;
    }
    else { //cand.size() == 3
        vector<int> fcand;
        bool as = ask({ cand[0] });
        if (as) {
            fcand.push_back(cand[0]);
            bool as2 = ask({ cand[1] });
            if (as2) {
                fcand.push_back(cand[1]);
            }
            else {
                fcand.push_back(cand[2]);
            }
        }
        else {
            bool ass2 = ask({ cand[0] });
            if (ass2) {
                fcand.push_back(cand[0]);
                bool as2 = ask({ cand[1] });
                if (as2) {
                    fcand.push_back(cand[1]);
                }
                else {
                    fcand.push_back(cand[2]);
                }
            }
            else {
                fcand = vector<int>{ cand[0],cand[1] };
            }
        }
        for (int x : fcand) {
            if (answer(x))break;
        }
    }
    return 0;
}