#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int a[3]={1234567,123456,1234};
int main()
{
    int n;
    scanf("%d",&n);
    bool isok=0;
    for(int i=0;i*a[0]<=n;i++)
        for(int j=0;j*a[1]<=n-i*a[0];j++)
            if((n-i*a[0]-j*a[1])%a[2]==0)
                isok=1;
    return 0*printf("%s",(isok ? "YES" : "NO"));
}