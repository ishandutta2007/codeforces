#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
using namespace std;
const int N = 3007;
const int M = 9e6 + 7;
int n, m, k, a[N][N];
int gz[N][N << 1];
int f[M << 1];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int P(int x, int y) { return (x - 1) * m * 2 + y; }
bitset<M << 1> mp;
bool check(int t, int p) {
    bool ans = 1;
    L(i, -1, 1) L(j, -1, 1) {
        int nowx = i + t, nowy = j + p;
        if(nowy > m * 2) nowy -= m * 2;
        if(nowy <= 0) nowy += m * 2;
        if(nowx <= 0 || nowx > n || !gz[nowx][nowy]) continue;
        mp[find(P(nowx, nowy))] = 1;
    }
    L(i, -1, 1) L(j, -1, 1) {
        int nowx = i + t, nowy = j + p + m;
        if(nowy > m * 2) nowy -= m * 2;
        if(nowy <= 0) nowy += m * 2;
        if(nowx <= 0 || nowx > n || !gz[nowx][nowy]) continue;
        if(mp[find(P(nowx, nowy))]) ans = 0;
    }
    L(i, -1, 1) L(j, -1, 1) {
        int nowx = i + t, nowy = j + p;
        if(nowy > m * 2) nowy -= m * 2;
        if(nowy <= 0) nowy += m * 2;
        if(nowx <= 0 || nowx > n || !gz[nowx][nowy]) continue;
        mp[find(P(nowx, nowy))] = 0;
    }
    return ans;
}
void merge(int x, int y) { f[find(x)] = find(y); }
void add(int t, int p) {
    L(i, -1, 1) L(j, -1, 1) {
        int nowx = i + t, nowy = j + p;
        if(nowy > m * 2) nowy -= m * 2;
        if(nowy <= 0) nowy += m * 2;
        if(nowx <= 0 || nowx > n || !gz[nowx][nowy]) continue;
        merge(P(t, p), P(nowx, nowy));
    }
    gz[t][p] = 1;
}
int main(){
    int ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    L(i, 1, n * m * 2) f[i] = i;
    L(i, 1, k) {
        int t, p;
        scanf("%d%d", &t, &p);
        if(check(t, p)) add(t, p), add(t, p + m), ans++;
    }
    if(m == 1) printf("0\n");
    else printf("%d\n", ans);
    return 0;
}