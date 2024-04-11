//
// Created by Ormlis on 05.11.2019.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

ll MOD = 12345;
ll MOD2 = 23456;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;
int n, count = 0;

struct Node {
    int upd = 0;
    int min = 0;
    int max = 0;
};

Node tree[5000000];
int arr[1000001];


void push(int v, int L, int R) {
    tree[v * 2].min += tree[v].upd;
    tree[v * 2 + 1].min += tree[v].upd;
    tree[v * 2].max += tree[v].upd;
    tree[v * 2 + 1].max += tree[v].upd;
    tree[v * 2].upd += tree[v].upd;
    tree[v * 2 + 1].upd += tree[v].upd;
    tree[v].upd = 0;
}


pair<int, int> get(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) {
        return {INF2, -INF2};
    }
    if (l <= L && R <= r) {
        return {tree[v].min, tree[v].max};
    }
    push(v, L, R);
    auto a = get(v * 2, l, r, L, (R + L) / 2);
    auto b = get(v * 2 + 1, l, r, (R + L) / 2, R);
    return {min(a.first, b.first), max(a.second, b.second)};
}

void update(int v, int L, int R, int l, int r, int x) {
    if (L >= r || R <= l) {
        return;
    }
    if (l <= L && R <= r) {
        tree[v].min += x;
        tree[v].max += x;
        tree[v].upd += x;
        return;
    }
    push(v, L, R);
    update(v * 2, L, (R + L) / 2, l, r, x);
    update(v * 2 + 1, (R + L) / 2, R, l, r, x);
    tree[v].min = min(tree[v * 2 + 1].min, tree[v * 2].min);
    tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin("bridges.in");
    //ofstream cout("bridges.out");
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    char a;
    int pos = 0;
    int b = 0;
    range(i, n) {
        cin >> a;
        if (a == ')') {
            if (arr[pos] == 1) {
                update(1, 0, n, pos, n, -2);
                b -= 2;
            } else if (arr[pos] == 0) {
                update(1, 0, n, pos, n, -1);
                b -= 1;
            }
            arr[pos] = -1;
        } else if (a == '(') {
            if (arr[pos] == -1) {
                update(1, 0, n, pos, n, 2);
                b += 2;
            } else if (arr[pos] == 0) {
                update(1, 0, n, pos, n, 1);
                b += 1;
            }
            arr[pos] = 1;
        } else if (a == 'L') {
            pos = max(pos - 1, 0);
        } else if (a == 'R') {
            pos++;
        } else {
            if (arr[pos] == -1) {
                update(1, 0, n, pos, n, 1);
                b += 1;
            } else if (arr[pos] == 1) {
                update(1, 0, n, pos, n, -1);
                b -= 1;
            }
            arr[pos] = 0;
        }
        if (b == 0 && tree[1].min == 0) {
            cout << tree[1].max << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    return 0;
}