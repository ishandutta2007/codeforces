#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define make_pair mp 
#define first x
#define second y
#define pb(a) push_back(a)
#define sz(a) (int)(a.size()) 
#define mod 998244353 
const int N = 1e6 + 7;
int T, n, now, lis[N], g[N], tot, head, ftot;
char s[N];
int main() {
    scanf("%d", &T);
    while(T--) {
        int ans = 0;
        scanf("%d", &n);
        scanf("%s", s + 1);
        s[0] = s[1];
        now = tot = ftot = 0, head = 1;
        L(i, 1, n) {
            if(s[i] != s[i - 1]) {
                lis[++tot] = now;
                if(now != 1) g[++ftot] = tot;
                now = 1;
            }
            else now++;
        }
        lis[++tot] = now;
        if(now != 1) g[++ftot] = tot;
        L(i, 1, tot) {
            if(lis[i] == 1) {
                if(head > ftot) i++;
                else {
                    lis[g[head]]--;
                    if(lis[g[head]] == 1) ++head;
                }
            }
            else ++head;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}