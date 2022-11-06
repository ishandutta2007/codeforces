#include <cstdio>

int data[100010];
int ans[100010];
int n,i;

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",data+i);
    int last=data[n-1];
    for(i=n-2;0<=i;--i){
        ans[i]=max(0,last+1-data[i]);
        last=max(last,data[i]);
    }
    for(i=0;i<n;++i)printf("%d ",ans[i]);
    return 0;
}