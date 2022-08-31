#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 3e5 + 7;
int T, n, m;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        int k = (n | m);
        printf("%d\n", (n ^ k) + (m ^ k));
    }
    return 0;
}