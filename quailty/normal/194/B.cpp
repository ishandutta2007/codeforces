#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%I64d",&n);
        if(n%2==0){
            printf("%I64d\n",4*n+1);
        }
        else if(n%4==1){
            printf("%I64d\n",2*n+1);
        }
        else if(n%4==3){
            printf("%I64d\n",n+1);
        }
    }
    return 0;
}