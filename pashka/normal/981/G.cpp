#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

#define MOD 998244353LL

typedef pair<long, long> item;
item zeroAdd = {1, 0};
item zeroSum = {0, 0};

item add(item a, item b) {
    return {(a.first * b.first) % MOD, (a.second * b.first + b.second) % MOD};
}

item sum(item a, item b) {
    return {0, (a.second + b.second) % MOD};
}

vector<item> sums;
vector<item> adds;

int size;

void propagate(int n, int len) {
    adds[2 * n + 1] = add(adds[2 * n + 1], adds[n]);
    sums[2 * n + 1] = add(sums[2 * n + 1], {adds[n].first, adds[n].second * (len / 2) % MOD});
    adds[2 * n + 2] = add(adds[2 * n + 2], adds[n]);
    sums[2 * n + 2] = add(sums[2 * n + 2], {adds[n].first, adds[n].second * (len - len / 2) % MOD});
    adds[n] = zeroAdd;
}

void add(int l, int r, item x, int n, int L, int R) {
    if (l >= R || L >= r) return;
    if (L >= l && R <= r) {
        adds[n] = add(adds[n], x);
        sums[n] = add(sums[n], {x.first, x.second * (R - L) % MOD});
//        cout << "add " << L << " " << R << " " << x.first << "," << x.second << " " << sums[n].first << "," << sums[n].second << "\n";
        return;
    }
    int M = (L + R) >> 1;
    propagate(n, R - L);
    add(l, r, x, 2 * n + 1, L, M);
    add(l, r, x, 2 * n + 2, M, R);
    sums[n] = sum(sums[2 * n + 1], sums[2 * n + 2]);
}

item sum(int l, int r, int n, int L, int R) {
    if (l >= R || L >= r) return zeroSum;
    if (L >= l && R <= r) {
//        cout << L << "-" << R << ":" << sums[n].first << "," << sums[n].second << "\n";
        return sums[n];
    }
    int M = (L + R) >> 1;
    propagate(n, R - L);
    item res = sum(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
    return res;
}

void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, zeroSum);
    adds.assign(2 * size, zeroAdd);
}

void add(int l, int r, item x) {
//    cout << l << "-" << r << ": *" << x.first << "+" << x.second << "\n";
    add(l, r, x, 0, 0, size);
}

item sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    init(n);

    vector<set<pair<int, int>>> s(n, {{n, 0}});

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            x--;
            auto &ss = s[x];
            while (l < r) {
                auto it = ss.lower_bound({l + 1,  -1});
                if (it == ss.end()) {
                    add(l, r, {2, 0});
                    break;
                }
                auto p = *it;
                int ll = p.second;
                int rr = p.first;
                if (ll > l) {
                    add(l, std::min(r, ll), {2, 0});
                    l = std::min(r, ll);
                } else {
                    int r2 = std::min(r, rr);
                    if (r2 <= l) break;
                    add(l, r2, {1, 1});
                    ss.erase(p);
                    if (l > ll) {
                        ss.insert({l, ll});
                    }
                    if (r2 < rr) {
                        ss.insert({rr, r2});
                    }
                    l = r2;
                }
            }
//            for (int i = 0; i < n; i++) {
//                cout << sum(i, i + 1).first<< "," << sum(i, i + 1).second << " ";
//            }
//            cout << "\n";
//            auto s = sum(0, n);
//            cout << "! " << s.first << "," << s.second << "\n";
//            cout << sum(0, n).first << "," << sum(0, n).second << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << sum(l, r).second << "\n";
        }
    }


    return 0;
}