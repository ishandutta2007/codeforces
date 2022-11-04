#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int v,a[10],dig=1;
    scanf("%d",&v);
    for(int i=1;i<=9;i++)
    {
        scanf("%d",&a[i]);
        if(a[dig]>=a[i])dig=i;
    }
    int len=v/a[dig];
    if(!len)return 0*printf("-1");
    string res(len,dig+'0');
    v-=len*a[dig];
    for(int i=0;i<len;i++)
        for(int j=9;j>=dig;j--)
            if(v>=a[j]-a[dig])
            {
                res[i]=j+'0';
                v-=a[j]-a[dig];
                break;
            }
    return 0*printf("%s",res.c_str());
}