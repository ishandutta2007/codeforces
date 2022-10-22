#include<cstdio>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
  
int a[200001],b[200001],n,k,sum;  
  
int main()   
{
    scanf("%d%d",&n,&k);
    sum=0;  
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   
    {  
        scanf("%d",&b[i]);
        sum+=b[i];  
        b[i]=a[i]-b[i];  
    }  
    sort(b+1,b+n+1);   
    for(int i=1;k>0||b[i]<0;i++)  
        k--,sum+=b[i];  
    printf("%d",sum);
}