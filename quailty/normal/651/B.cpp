#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        mp[a]++;
    }
    int res=n;
    while(!mp.empty())
    {
        for(auto itr=mp.begin();itr!=mp.end();)
        {
            if(--itr->second==0)mp.erase(itr++);
            else itr++;
        }
        res--;
    }
    printf("%d\n",res);
    return 0;
}