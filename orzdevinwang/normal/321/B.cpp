#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e3 + 7;
int n, m, p[N], flag[N];
int a[N], b[N], tota, totb;
int ans, nowa;
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) {
        char s[15]; int g;
        scanf("%s%d", s, &g);
        if(s[0] == 'A') a[++tota] = g;
        else b[++totb] = g;
    }
    sort(a + 1, a + tota + 1);
    sort(b + 1, b + totb + 1);
    L(i, 1, m) scanf("%d", &p[i]);
    sort(p + 1, p + m + 1);
    bool tt = 1;
    R(i, totb, 1) {
        bool now = 0;
        L(j, 1, m) if(b[i] < p[j] && flag[j] == 0) {
                now = 1, flag[j] = 1;
                break;
            }
        tt &= now;
    }
    R(i, tota, 1) {
        bool now = 0;
        L(j, 1, m) if(a[i] <= p[j] && flag[j] == 0) {
                now = 1, flag[j] = 1;
                break;
            }
        tt &= now;
    }
    L(i, 1, m) flag[i] = 0;
    L(i, 1, tota) R(j, m, 1) if(a[i] <= p[j] && flag[j] == 0) {
        flag[j] = 1, nowa += p[j] - a[i];
        break;
    }
    if(tt) {
        L(i, 1, m) flag[i] = 0;
        L(i, 1, totb) L(j, 1, m) if(b[i] < p[j] && flag[j] == 0) {
            flag[j] = 1;
            break;
        }
        L(i, 1, tota) L(j, 1, m) if(a[i] <= p[j] && flag[j] == 0) {
            flag[j] = 1, ans += p[j] - a[i];
            break;
        }
        L(i, 1, m) if(flag[i] == 0) ans += p[i];
        nowa = max(nowa, ans);
    }
    printf("%d\n", nowa);
    return 0;
}