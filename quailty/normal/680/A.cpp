#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>mp;
int main()
{
    int sum=0;
    for(int i=0;i<5;i++)
    {
        int t;
        scanf("%d",&t);
        mp[t]++;
        sum+=t;
    }
    int res=sum;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        if(itr->second >=2)res=min(res,sum-itr->first*min(3,itr->second));
    return 0*printf("%d\n",res);
}