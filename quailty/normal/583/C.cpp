#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>mp;
map<int,int>::iterator itr;
int a[505];
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int in;
    for(int i=1;i<=n*n;i++)
    {
        scanf("%d",&in);
        mp[in]++;
    }
    int tot=0;
    while(!mp.empty())
    {
        itr=mp.end();
        --itr;
        int num=itr->first;
        for(int i=0;i<tot;i++)
        {
            int g=gcd(num,a[i]);
            mp[g]-=2;
            if(mp[g]==0)mp.erase(g);
        }
        mp[num]--;
        if(mp[num]==0)mp.erase(num);
        a[tot++]=num;
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}