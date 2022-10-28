#include <bits/stdc++.h>
using namespace std;
const int N = 101;
bool b[N][N]={0};
bool a[N][N]={0};
bool markrow[N]={0};
bool markcol[N]={0};
bool row[N];
bool col[N];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1 ; i<=n ; ++i ){
        for(int j=1 ; j<=m ; ++j ){
            scanf("%d",&b[i][j]);
            if(!b[i][j]){
                markrow[i]=1;
                markcol[j]=1;
            }
        }
    }
    for(int i=1 ; i<=n ; ++i ){
        for(int j=1 ; j<=m ; ++j ){
            if(!markrow[i]&&!markcol[j]){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
            row[i]|=a[i][j];
            col[j]|=a[i][j];
        }
    }
    for(int i=1 ; i<=n ; ++i ){
        for(int j=1 ; j<=m ; ++j ){
            if((row[i]|col[j])^b[i][j]){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=1 ; i<=n ; ++i){
        for(int j=1 ; j<=m ; ++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}