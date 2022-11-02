#include <bits/stdc++.h>
#define ll long long
#define maxn 1010
using namespace std;

int ans[maxn][maxn];
int n;
void pr(){
    printf("YES\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d",ans[i][j]);
        printf("\n");
    }        
}

main(){
    int a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a > 1 && b > 1){
        printf("NO\n");
        return 0;
    }
    if(a == 1 && b == 1){
        if(n == 2 || n == 3){
            printf("NO\n");
            return 0;
        }
        for(int i=0;i<n-1;i++)
            ans[i][i+1] = ans[i+1][i] = 1;
        pr();
        return 0;
    }
    if(b == 1){
        for(int i=a-1;i<n-1;i++)
            ans[i][i+1] = ans[i+1][i] = 1;
        pr();
        return 0;
    }
    if(a == 1){
        for(int i=b-1;i<n-1;i++)
            ans[i][i+1] = ans[i+1][i] = 1;
        for(int i=0;i<n;i++) ans[i][i] = 1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans[i][j] ^= 1;
        pr();
    }
    
}