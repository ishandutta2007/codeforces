#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, k, p;
ll h[N], a[N], ans[N], ad[N];
bool check(ll x) {
    priority_queue< pair<int, int> > q;
    L(i, 1, n) {
        ad[i] = 0;
        if(a[i] * m > ad[i] + x) q.push(mkp(m - (x + ad[i] + a[i]) / a[i] + 1, i));
        else if(a[i] * m + h[i] > ad[i] + x) q.push(mkp(0, i));
    } 
    R(i, m, 1) L(j, 1, k) {
        if(q.empty()) return 1;
        int now = q.top().second;
        if(q.top().first >= i) return 0;
        q.pop(); 
        ad[now] += p;
        if(a[now] * m > ad[now] + x) q.push(mkp(m - (x + ad[now] + a[now]) / a[now] + 1, now));
        else if(a[now] * m + h[now] > ad[now] + x) q.push(mkp(0, now));
    }
    if(q.empty()) return 1;
    return 0;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &p);
    L(i, 1, n) scanf("%lld%lld", &h[i], &a[i]);
    ll L = 0, R = 1e13, ans = 0;
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    printf("%lld\n", ans);
	return 0;
}