#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 1007;
int T, n;
char s[N][N];
bool worka() {
    L(i, 1, n) {
        bool flag = 0;
        L(j, 1, n) if(s[i][j] != 'E') flag = 1;
        if(!flag) return 0;
    }
    L(i, 1, n) {
        L(j, 1, n) if(s[i][j] != 'E') {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 1;
}
bool workb() {
    L(j, 1, n) {
        bool flag = 0;
        L(i, 1, n) if(s[i][j] != 'E') flag = 1;
        if(!flag) return 0;
    }
    L(j, 1, n) {
        L(i, 1, n) if(s[i][j] != 'E') {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%s", s[i] + 1);
    if(!worka() && !workb()) printf("-1\n");
    return 0;
}