#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
map<int,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=0;j<=30;j++)
            if(mp.find((1<<j)-a)!=mp.end())
                res+=mp[(1<<j)-a];
        mp[a]++;
    }
    return 0*printf("%I64d",res);
}