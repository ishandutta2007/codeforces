#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ans=0;
        if (n%2==1) ans=min(n-1, 3);
        else ans=min(n-1, 2);
        printf("%d\n", ans);
    }
    return 0;
}