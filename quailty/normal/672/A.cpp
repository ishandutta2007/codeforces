#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int s[1005],stk[15],top;
void build()
{
    int tot=0,now=1;
    while(tot<=1000)
    {
        int tmp=now++;
        while(tmp)stk[top++]=tmp%10,tmp/=10;
        while(top)s[++tot]=stk[--top];
    }
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    printf("%d",s[n]);
    return 0;
}