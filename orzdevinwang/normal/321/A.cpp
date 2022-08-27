#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e3 + 7;
int T, n, x, y, X, Y;
int a, b;
char s[N];
int main() {
    scanf("%d%d", &a, &b);
    scanf("%s", s + 1), n = strlen(s + 1);
    x = 0, y = 0;
    if(a == 0 && b == 0) printf("Yes\n"), exit(0);
    L(i, 1, n) {
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
        if(s[i] == 'R') x++;
        if(s[i] == 'L') x--;
    }
    X = x, Y = y;
    x = y = 0;
    L(i, 0, n) {
        if(i != 0) {
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(s[i] == 'R') x++;
            if(s[i] == 'L') x--;
        }
        if(!X && !Y) {
            if(x == a && y == b) printf("Yes\n"), exit(0);
        }
        else if(!Y) {
            if((a - x) % X == 0 && (a - x) / X >= 0 && y == b) printf("Yes\n"), exit(0);
        }
        else if(!X) {
            if((b - y) % Y == 0 && (b - y) / Y >= 0 && x == a) printf("Yes\n"), exit(0);
        }
        else {
            int pa = (a - x) / X, pb = (b - y) / Y;
            if((a - x) % X == 0 && (b - y) % Y == 0 && pa == pb && pa >= 0) printf("Yes\n"), exit(0);
        }
    }
    printf("No\n");
    return 0;
}