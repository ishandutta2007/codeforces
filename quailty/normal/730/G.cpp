#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<pair<int,int> >c;
bool check(int s,int d)
{
    auto itr=c.lower_bound(make_pair(s,0));
    return (itr==c.end() || itr->first>=s+d) && (--itr)->second<s;
}
int main()
{
    int n;
    scanf("%d",&n);
    c.insert(make_pair(0,0));
    for(int i=1;i<=n;i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        if(check(s,d))
        {
            printf("%d %d\n",s,s+d-1);
            c.insert(make_pair(s,s+d-1));
        }
        else for(auto itr=c.begin();itr!=c.end();itr++)
            if(check(itr->second+1,d))
            {
                printf("%d %d\n",itr->second+1,itr->second+d);
                c.insert(make_pair(itr->second+1,itr->second+d));
                break;
            }
    }
    return 0;
}