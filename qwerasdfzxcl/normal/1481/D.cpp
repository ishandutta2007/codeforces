#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char tmp[1010];
int adj[1010][1010];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    if (n==2){
        for (int i=0;i<n;i++){
            scanf("%s", tmp);
            for (int j=0;j<n;j++){
                if (tmp[j]=='a'){
                    adj[i][j]=1;
                }
                else if (tmp[j]=='b'){
                    adj[i][j]=2;
                }
            }
        }
        if (m&1){
            printf("YES\n");
            printf("2 ");
            for (int k=0;k<m;k++){
                if (k&1) printf("2 ");
                else printf("1 ");
            }
            printf("\n");
            return;
        }
        if (adj[0][1]!=adj[1][0]){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            printf("2 ");
            for (int k=0;k<m;k++){
                if (k&1) printf("2 ");
                else printf("1 ");
            }
            printf("\n");
        }
        return;
    }
    printf("YES\n");
    int c1=0, c2=0;
    for (int i=0;i<n;i++){
        scanf("%s", tmp);
        for (int j=0;j<n;j++){
            if (tmp[j]=='a'){
                adj[i][j]=1;
                c1++;
            }
            else if (tmp[j]=='b'){
                adj[i][j]=2;
                c2++;
            }
        }
    }
    /*if (c1>c2){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (adj[i][j]==1 && adj[j][i]==1){
                    printf("%d ", j+1);
                    for (int k=0;k<m;k++){
                        if (k&1) printf("%d ", j+1);
                        else printf("%d ", i+1);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }
    if (c1<c2){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (adj[i][j]==2 && adj[j][i]==2){
                    printf("%d ", j+1);
                    for (int k=0;k<m;k++){
                        if (k&1) printf("%d ", j+1);
                        else printf("%d ", i+1);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }*/
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (adj[i][j]==adj[j][i] && adj[i][j]!=0){
                printf("%d ", j+1);
                for (int k=0;k<m;k++){
                    if (k&1) printf("%d ", j+1);
                    else printf("%d ", i+1);
                }
                printf("\n");
                return;
            }
        }
    }
    for (int i=0;i<n;i++){
        int a1=-1, b1=-1;
        for (int j=0;j<n;j++){
            if (adj[i][j]==1) a1=j;
            else if (adj[i][j]==2) b1=j;
        }
        if (a1==-1 || b1==-1) continue;
        if (m&1){
            printf("%d ", a1+1);
            for (int k=0;k<m;k++){
                if (k&1) printf("%d ", a1+1);
                else printf("%d ", i+1);
            }
            printf("\n");
            return;
        }
        else if ((m/2)&1){
            printf("%d ", a1+1);
            for (int k=0;k<(m/2);k++){
                if (k&1) printf("%d ", a1+1);
                else printf("%d ", i+1);
            }
            for (int k=(m/2);k<m;k++){
                if (k&1) printf("%d ", b1+1);
                else printf("%d ", i+1);
            }
            printf("\n");
            return;
        }
        else{
            printf("%d ", i+1);
            for (int k=0;k<(m/2);k++){
                if (k&1) printf("%d ", i+1);
                else printf("%d ", a1+1);
            }
            for (int k=(m/2);k<m;k++){
                if (k&1) printf("%d ", i+1);
                else printf("%d ", b1+1);
            }
            printf("\n");
            return;
        }
    }
    m++;
    m/=0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}