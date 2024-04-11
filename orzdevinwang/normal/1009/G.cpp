#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
int n, m, p[N], cnt[N], suma[64], sumb[64], ans[N]; // suma : 6 ; sumb : 
char s[N], t[10];
int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    L(i, 1, n) p[i] = 63, suma[1 << (s[i] - 'a')]++;
    L(i, 1, 63) suma[i] = suma[i & -i] + suma[i - (i & -i)];
    scanf("%d", &m);
    while(m--) {
        int wz, g, tp = 0; scanf("%d%s", &wz, t + 1), g = strlen(t + 1);
        L(i, 1, g) tp |= (1 << (t[i] - 'a')); 
        p[wz] &= tp;
    }
    L(i, 0, 63) L(j, 1, n) if(p[j] & i) sumb[i]++;
    L(d, 1, n) {
        bool flag = 1;
        L(i, 0, 5) if(((1 << i) & p[d]) && suma[1 << i] > 0){
            bool iff = 0; int np = (p[d] ^ (1 << i));
            L(j, 0, 63) if(suma[j] > sumb[j] - !!(!(j & (1 << i)) && (j & np)) ) iff = 1;
            if(!iff) {
                flag = 0, ans[d] = i;
                L(j, 0, 63) sumb[j] -= !!(!(j & (1 << i)) && (j & np));
                break;
            }
        }
        // cout << d << endl;
        if(flag) return printf("Impossible\n"), 0;
    }
    L(i, 1, n) putchar(ans[i] + 'a');
    puts("");
    return 0;
}