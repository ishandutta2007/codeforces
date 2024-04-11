#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[1<<18];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char ty[5],buf[25];
        scanf("%s%s",ty,buf);
        int tmp=0;
        for(int i=0;buf[i];i++)
            tmp=tmp*2+(buf[i]-'0')%2;
        if(*ty=='?')printf("%d\n",cnt[tmp]);
        else cnt[tmp]+=(*ty=='+' ? 1 : -1);
    }
    return 0;
}