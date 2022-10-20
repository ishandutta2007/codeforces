#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int tmp=n+m+k;
        if (tmp%9){
            printf("NO\n");
            continue;
        }
        if (min(n, min(m, k))<tmp/9) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}