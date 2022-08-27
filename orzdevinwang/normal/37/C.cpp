#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1111;
struct node {
    int val, id;
} a[N];
bool cmp(node aa, node bb) { return aa.val < bb.val; }
int n, m, dy[N], cnt[N], ch[N * N][2], tot = 1, head = 1;
bool s[N][N], used[N * N];
void ins(int &id, int x, int now) {
    if(!id) id = ++tot;
    if(now > a[x].val) return used[id] = 1, void();
    if(!used[ch[id][0]]) s[x][now] = 0, ins(ch[id][0], x, now + 1);
    else s[x][now] = 1, ins(ch[id][1], x, now + 1);
    used[id] = (used[ch[id][0]] & used[ch[id][1]]);
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i].val), a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    L(i, 1, n) dy[a[i].id] = i;
    L(i, 1, n) {
        if(used[1]) printf("NO\n"), exit(0);
        ins(head, i, 1);
    }
    printf("YES\n");
    L(i, 1, n) {
        L(j, 1, a[dy[i]].val) putchar(s[dy[i]][j] + '0');
        puts("");
    }
    return 0;
}