#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int t[105];
int main()
{
    int a,n;
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]);
    int l=a,r=a,res=0;
    t[0]=t[n+1]=1;
    while(l>=1 || r<=n)
    {
        if(t[l]&&t[r])res+=1+(l>=1 && r<=n && l!=r);
        if(l>=1)l--;
        if(r<=n)r++;
    }
    return 0*printf("%d",res);
}