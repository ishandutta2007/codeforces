#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define make_pair mp 
#define first x
#define second y
#define pb(a) push_back(a)
#define sz(a) (int)(a.size()) 
#define mod 998244353 
const int N = 1e6 + 7;
int T, n;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(n == 2) {
            printf("2\n");
            printf("%d %d\n", 1, 2);
            continue;
        }
        printf("2\n");
        printf("%d %d\n", n - 2, n);
        printf("%d %d\n", n - 1, n - 1);
        R(i, n - 3, 1) printf("%d %d\n", i + 2, i);
    }
    return 0;
}