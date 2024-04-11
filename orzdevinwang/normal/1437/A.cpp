#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
int T, l, r;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &l, &r);
        if(l * 2 >= r + 1) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}