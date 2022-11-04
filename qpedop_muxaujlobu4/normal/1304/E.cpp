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
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 100000;
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
int tree[9*Y];
int IDX[Y + 1];
int sz = 1, L=-1;
vector<int>Ed[Y + 1];
int dpt[Y + 1];
void dfs(int i, int p) {
    tree[sz + ++L] = dpt[i];
    IDX[i] = L;
    for (auto x : Ed[i]) {
        if (x == p)continue;
        dpt[x] = dpt[i] + 1;
        dfs(x,i);
        tree[sz + ++L] = dpt[i];
    }
}
void build() {
    for (int i = sz - 1; i > 0; --i)tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
int get(int ql, int qr, int v = 1, int tl = 0, int tr = sz - 1) {
    if (ql <= tl && tr <= qr) {
        return tree[v];
    }
    int mid = (tr + tl) / 2;
    int res = 100000000;
    if (ql <= mid)res = min(res, get(ql, qr, 2 * v, tl, mid));
    if (qr > mid)res = min(res, get(ql, qr, 2 * v + 1, mid + 1, tr));
    return res;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (sz <= 2 * n)sz <<= 1;
    for (int i = 1; i < n; ++i) {
        int a= getint<int>(), b=getint<int>();
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    dfs(1, -1);
    build();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        bool ans = false;
        int x= getint<int>(), y= getint<int>(), a= getint<int>(), b= getint<int>(), k= getint<int>();
        int tmpx = IDX[x];
        int tmpy = IDX[y];
        int tmpa = IDX[a];
        int tmpb = IDX[b];
        int tmp = get(min(tmpa, tmpb),max(tmpa,tmpb));
        int dis = dpt[a] + dpt[b] - 2 * tmp;
        //cout << k << " " << dis << endl;
        if (dis <= k && (k - dis) % 2 == 0)ans = true;
        else {
            dis = 0;
            tmp = get(min(tmpa, tmpx), max(tmpa, tmpx));
            dis = dpt[a] + dpt[x] - 2 * tmp;
           // cout << dis << endl;
            tmp = get(min(tmpb, tmpy), max(tmpb, tmpy));
            dis += dpt[b] + dpt[y] - 2 * tmp + 1;
            //cout << dis <<" "<< dpt[b]<<" "<<dpt[y]<<" "<<tmp<< endl;
            if (dis <= k && (k - dis) % 2 == 0)ans = true;
            else {
                dis = 0;
                tmp = get(min(tmpb, tmpx), max(tmpb, tmpx));
                dis = dpt[b] + dpt[x] - 2 * tmp;
                tmp = get(min(tmpa, tmpy), max(tmpa, tmpy));
                dis += dpt[a] + dpt[y] - 2 * tmp + 1;
                if (dis <= k && (k - dis) % 2 == 0)ans = true;
            }
        }
        if (ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */