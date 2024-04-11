#include<bits/stdc++.h>
using namespace std;
const int N = 100002;
const int LN = 31;
int mark[LN][N]={0};
int arr[N];
int sum[LN][N]={0};
int l[N];
int r[N];
int val[N];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= m ; ++i ){
        scanf("%d %d %d",&l[i] , &r[i] , &val[i]);
    }
    for(int j = 0 ; j < LN ; ++j ){
        for(int i = 1 ; i <= m ; ++i ){
            if(val[i]&(1<<j)){
                mark[j][l[i]]++;
                mark[j][r[i]+1]--;
            }
        }
        for(int i = 1 ; i <=n ; ++i ){
            mark[j][i] += mark[j][i-1];
            sum[j][i] = sum[j][i-1];
            if(mark[j][i]){
                sum[j][i]++;
                arr[i]|=1<<j;
            }
        }
        for(int i = 1 ; i <= m ;++i){
            if(!(val[i]&(1<<j))){
                if(sum[j][r[i]] - sum[j][l[i]-1]==r[i]-l[i]+1){
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    for(int i = 1 ; i <= n ; ++i ){
        printf("%d ",arr[i]);
    }
}