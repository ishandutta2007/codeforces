#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int now=0,ovt=0,cnt=0;
    vector<int> spd;
    for(int i=1;i<=n;i++)
    {
        int t,s;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&s);
            now=s;
            while(!spd.empty() && now>spd.back())
                spd.pop_back(),cnt++;
        }
        if(t==2)cnt+=ovt,ovt=0;
        if(t==3)
        {
            scanf("%d",&s);
            spd.push_back(s);
            while(!spd.empty() && now>spd.back())
                spd.pop_back(),cnt++;
        }
        if(t==4)ovt=0;
        if(t==5)spd.clear();
        if(t==6)ovt++;
    }
    return 0*printf("%d\n",cnt);
}