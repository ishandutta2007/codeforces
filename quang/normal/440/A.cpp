#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100001

using namespace std;

int kt[N];
int n;

int main() {
    //fi, fo;
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        kt[x] = 1;
    }
    for(int i = 1; i <= n; i++)
    if(!kt[i]) {
        printf("%d", i);
        return 0;
    }
    return 0;
}