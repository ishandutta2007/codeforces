#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define db double 
#define ll long long
using namespace std;
const int N = 1e3;
int n, m;
char s[N][N];
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) L(j, 1, m) {
        s[i][j] = '.';
    }
    for(int i = 1; i <= n; i += 2) {
        L(j, 1, m) s[i][j] = '#';
        if(i % 4 == 1) {
            s[i + 1][m] = '#';
        }
        else {
            s[i + 1][1] = '#';
        }
    }
    L(i, 1, n) {
        L(j, 1, m) printf("%c", s[i][j]);
        puts("");
    }
    return 0;
}