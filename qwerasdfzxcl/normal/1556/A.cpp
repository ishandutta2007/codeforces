#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x+y)%2==1) {printf("-1\n"); return;}
    if (x==0 && y==0) printf("0\n");
    else if (x==y || x==-y) printf("1\n");
    else printf("2\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}