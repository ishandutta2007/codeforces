#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        int ans=min(x, y)*2;
        if (x!=y) ans += (max(x, y)-min(x, y))*2-1;
        printf("%d\n", ans);
    }
    return 0;
}