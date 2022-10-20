#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char matrix[505][505], ans[505][505];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %c", &matrix[i][j]);
            ans[i][j]=matrix[i][j];
        }
    }
    int val=0;
    if (n%3==0) val=1;
    for (int i=0;i<n;i++){
        if (i%3==val){
            for (int j=0;j<m;j++) ans[i][j]='X';
        }
    }
    for (int i=0;i<n;i++) if (i%3!=val && matrix[i][1]=='X'){
        if (i==0) continue;
        if ((i-1)%3==val && i+1<n) ans[i+1][1]='X';
        else ans[i-1][1]='X';
    }
    for (int i=val;i<n;i+=3){
        bool chk=0;
        for (int j=i+1;j<min(i+3, n);j++) if (ans[j][1]=='X') chk=1;
        if (chk) continue;
        else{
            for (int j=i+1;j<min(i+3, n);j++) ans[j][0]='X';
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) printf("%c", ans[i][j]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}