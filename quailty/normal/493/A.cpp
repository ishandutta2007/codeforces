#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char str[2][25];
int cnt[2][105];
int main()
{
    scanf("%s%s",str[0],str[1]);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t,p;
        char h[5],c[5];
        scanf("%d%s%d%s",&t,h,&p,c);
        if(cnt[*h=='a'][p]>=0)
            cnt[*h=='a'][p]+=(*c=='y' ? 1 : 2);
        if(cnt[*h=='a'][p]>1)
        {
            printf("%s %d %d\n",str[*h=='a'],p,t);
            cnt[*h=='a'][p]=-1;
        }
    }
    return 0;
}