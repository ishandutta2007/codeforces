#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 2e5 + 7;
int T, n;
char s[N];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        int cnt = 0;
        L(i, 2, n) if(s[i] == s[i - 1]) cnt++;
        printf("%d\n", (cnt + 1) / 2);
    }
	return 0;
}