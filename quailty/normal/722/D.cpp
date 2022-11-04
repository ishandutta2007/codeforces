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
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        int y;
        scanf("%d",&y);
        s.insert(y);
    }
    while(1)
    {
        int t=*(--s.end()),ok=0;
        while(t>1)
        {
            t/=2;
            if(s.find(t)==s.end())
            {
                s.erase(--s.end());
                s.insert(t);
                ok=1;
                break;
            }
        }
        if(!ok)break;
    }
    for(auto itr=s.begin();itr!=s.end();itr++)
        printf("%d ",*itr);
    return 0;
}