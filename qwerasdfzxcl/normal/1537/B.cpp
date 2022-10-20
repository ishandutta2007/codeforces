#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int x1, x2;
    if (n==1) x1 = x2 = 1;
    else if (x==1) x1 = n, x2 = 2;
    else if (x==n) x1 = 1, x2 = n-1;
    else x1 = n, x2 = 1;
    int y1, y2;
    if (m==1) y1 = y2 = 1;
    else if (y==1) y1 = m, y2 = 2;
    else if (y==m) y1 = 1, y2 = m-1;
    else y1 = m, y2 = 1;
    printf("%d %d %d %d\n", x1, y1, x2, y2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}