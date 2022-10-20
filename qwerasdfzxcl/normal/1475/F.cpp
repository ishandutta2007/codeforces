#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[1010][1010];
char tmp[1010];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%s", tmp);
        for (int j=0;j<n;j++) matrix[i][j]=tmp[j]-'0';
    }
    for (int i=0;i<n;i++){
        scanf("%s", tmp);
        for (int j=0;j<n;j++) matrix[i][j]=(tmp[j]-'0')^matrix[i][j];
    }
    bool ans=1;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1;j++){
            int tmp=matrix[i][j]+matrix[i][j+1]+matrix[i+1][j]+matrix[i+1][j+1];
            if (tmp%2){
                ans=0;
                break;
            }
        }
    }
    if (ans) printf("YES\n");
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