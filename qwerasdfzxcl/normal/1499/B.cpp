#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[1010];

void solve(){
    scanf("%s", s);
    int n=1;
    for (int i=1;s[i];i++) n++;
    int idx=-1;
    for (int i=1;i<n;i++){
        if (s[i]=='1' && s[i-1]=='1'){
            idx=i;
            break;
        }
    }
    if (idx==-1){
        printf("YES\n");
        return;
    }
    for (int i=idx+2;i<n;i++){
        if (s[i]=='0' && s[i-1]=='0'){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}