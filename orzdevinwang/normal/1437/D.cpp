#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 2e5 + 7;
const int inf = 1e9;
int T, n, a[N], len, las, now;
int main() {
    scanf("%d", &T);
    while(T--) {
        int ans = 0;
        scanf("%d%d", &n, &a[1]);
        ans = 1, len = 0, las = 1, now = 0;
        L(i, 2, n) {
            scanf("%d", &a[i]);
            if(now < a[i]) now = a[i];
            else {
                las--;
                if(las == 0) ans ++, las = len, len = 0;
                now = a[i];
            }
            ++len;
        }
        printf("%d\n", ans);
    }
	return 0;
}