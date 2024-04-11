#include <cstdio>
int sum[5000001]={0} , t , a , b;
int main(){
    for (int i = 2 ; i < 5000001 ; sum[i] += sum[i-1] , ++i)
        if (!sum[i])
            for (long long j = i ; j < 5000001 ; j *= i)
                for (int k = j ; k < 5000001 ; sum[k] ++ , k += j);
    scanf("%d",&t);
    while(~scanf("%d %d",&a,&b))
        printf("%d\n",sum[a] - sum[b]);
}