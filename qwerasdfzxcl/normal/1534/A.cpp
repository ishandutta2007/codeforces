#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[60][60], b[60][60];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++){
        scanf("%s", a[i]);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if ((i+j)&1) b[i][j] = 'W';
            else b[i][j] = 'R';
        }
    }
    bool chk = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) if (a[i][j]!='.'){
            chk &= (a[i][j]==b[i][j]);
        }
    }
    if (chk){
        printf("YES\n");
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("%c", b[i][j]);
            printf("\n");
        }
        return;
    }
    chk = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if ((i+j)&1) b[i][j] = 'R';
            else b[i][j] = 'W';
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) if (a[i][j]!='.'){
            chk &= (a[i][j]==b[i][j]);
        }
    }
    if (chk){
        printf("YES\n");
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("%c", b[i][j]);
            printf("\n");
        }
        return;
    }
    printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}