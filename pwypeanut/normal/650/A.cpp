#include <bits/stdc++.h>
using namespace std;

map< pair<int, int>, int > M;
map<int, int> mx, my;
int N;

int main() {
    scanf("%d", &N);
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        mx[x]++;
        my[y]++;
        M[make_pair(x, y)]++;
    }
    long long ans = 0;
    for (map<int, int>::iterator it = mx.begin(); it != mx.end(); it++) ans += (long long)it->second * (it->second - 1) / 2;
    for (map<int, int>::iterator it = my.begin(); it != my.end(); it++) ans += (long long)it->second * (it->second - 1) / 2;
    for (map< pair<int, int>, int>::iterator it = M.begin(); it != M.end(); it++) ans -= (long long)it->second * (it->second - 1) / 2;
    cout << ans << endl;
}