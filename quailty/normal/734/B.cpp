#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int cnt[4],res=0;
    for(int i=0;i<4;i++)
        scanf("%d",&cnt[i]);
    for(int i=0;i<=5000000;i++)
        if(cnt[0]>=i && cnt[2]>=i && cnt[3]>=i)
            res=max(res,256*i+32*min(cnt[0]-i,cnt[1]));
    return 0*printf("%d",res);
}