#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    int c[4]={0};
    for (int i=0;s[i];i++){
        if (s[i]=='R') c[0]++;
        if (s[i]=='U') c[1]++;
        if (s[i]=='L') c[2]++;
        if (s[i]=='D') c[3]++;
    }
    int w1=0, w2=0;
    if (n<0 ) w1=2;
    if (m<0) w2=2;
    if (c[0+w1]>=abs(n) && c[1+w2]>=abs(m)) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}