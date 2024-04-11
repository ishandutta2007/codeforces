#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,cnt[3]={0,0,0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==25)cnt[0]+=1;
        if(a==50)cnt[0]-=1,cnt[1]+=1;
        if(a==100)
        {
            if(cnt[1])cnt[0]-=1,cnt[1]-=1,cnt[2]+=1;
            else cnt[0]-=3,cnt[2]+=1;
        }
        for(int j=0;j<3;j++)
            if(cnt[j]<0)return 0*printf("NO");
    }
    return 0*printf("YES");
}