#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
char s[N];
int n;
int main() {
    scanf("%s", s);
    n = strlen(s);
    printf("3\n");
    printf("L 2\n");
    printf("R 2\n");
    printf("R %d\n", 2 * n - 1);
    return 0;
}