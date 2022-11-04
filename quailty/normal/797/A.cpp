#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> p;
    for(int i=2;i*i<=n;i++)
        while(n%i==0)
        {
            p.push_back(i);
            n/=i;
        }
    if(n>1)p.push_back(n);
    if((int)p.size()<k)printf("-1\n");
    else
    {
        while((int)p.size()>k)
        {
            int t=p.back();
            p.pop_back();
            p.back()*=t;
        }
        for(int i=0;i<(int)p.size();i++)
            printf("%d ",p[i]);
    }
    return 0;
}