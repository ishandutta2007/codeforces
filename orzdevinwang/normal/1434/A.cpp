#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
const int M = 1e6 + 7;
int n, a[10], b[N], tot, ans = 2e9;
int sum, cnt[N];
struct node { int val, id; } f[M];
bool operator < (node aa, node bb) { return aa.val < bb.val; }
int j = 0;
int main() {
    L(i, 1, 6) scanf("%d", &a[i]);
    scanf("%d", &n);
    L(i, 1, n) {
        scanf("%d", &b[i]);
        L(j, 1, 6) ++tot, f[tot].val = b[i] - a[j], f[tot].id = i;
    }
    sort(f + 1, f + tot + 1);
    L(i, 1, tot) {
        while(sum < n && j < tot) {
            j++;
            if(cnt[f[j].id] == 0) sum++;
            cnt[f[j].id] ++;
        }
        if(sum != n) continue;
        ans = min(ans, f[j].val - f[i].val);
        if(cnt[f[i].id] == 1) sum--;
        cnt[f[i].id]--;
    }
    printf("%d\n", ans);
	return 0;
}