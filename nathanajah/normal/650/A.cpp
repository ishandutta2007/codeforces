#include <bits/stdc++.h>
using namespace std;

map <int,int> cntx;
map <int, int> cnty;
map <pair<int, int>, int> tot;
long long result = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        cntx[x] = cntx[x] + 1;
        cnty[y] = cnty[y] + 1;
        tot[make_pair(x, y)] = tot[make_pair(x, y)] + 1;
    }

    for (pair<int,int> z : cntx) {
        long long cnt = z.second;
        result = result + (cnt * (cnt-1)) / 2;
    }
    for (pair<int,int> z : cnty) {
        long long cnt = z.second;
        result = result + (cnt * (cnt-1)) / 2;
    }
    for (pair<pair<int, int>,int> z : tot) {
        long long cnt = z.second;
        result = result - (cnt * (cnt-1)) / 2;
    }
    printf("%lld\n", result);
}