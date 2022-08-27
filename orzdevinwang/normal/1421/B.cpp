#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 200 + 7;
int T, n, m;
char s[N][N];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        L(i, 1, n) scanf("%s", s[i] + 1);
        int cnt = 0;
        if(s[1][2] == '1') cnt++;
        if(s[2][1] == '1') cnt++;
        if(s[n][n - 1] == '0') cnt++;
        if(s[n - 1][n] == '0') cnt++;
        if(cnt <= 2) {
            printf("%d\n", cnt);
            if(s[1][2] == '1') printf("%d %d\n", 1, 2);
            if(s[2][1] == '1') printf("%d %d\n", 2, 1);
            if(s[n][n - 1] == '0') printf("%d %d\n", n, n - 1);
            if(s[n - 1][n] == '0') printf("%d %d\n", n - 1, n);
        }
        else {
            printf("%d\n", 4 - cnt);
            if(s[1][2] == '0') printf("%d %d\n", 1, 2);
            if(s[2][1] == '0') printf("%d %d\n", 2, 1);
            if(s[n][n - 1] == '1') printf("%d %d\n", n, n - 1);
            if(s[n - 1][n] == '1') printf("%d %d\n", n - 1, n);
        }
    }
    return 0;
}