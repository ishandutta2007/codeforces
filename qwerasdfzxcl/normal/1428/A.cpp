#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a==c || b==d) printf("%d\n", abs(a-c)+abs(b-d));
    else printf("%d\n", abs(a-c)+abs(b-d)+2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}