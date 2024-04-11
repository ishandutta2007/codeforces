#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
multiset<int>s;
multiset<int>::iterator itr;
int c[5],tot;
int get_ty(int x)
{
    if(c[2]>=x)return 1;
    else if(c[1]+c[2]>=x)return 2;
    else if(c[0]+c[1]+c[2]>=x)return 3;
    else return 4;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<3;i++)
        tot+=c[i];
    sort(c,c+3);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        s.insert(t);
    }
    int res=0;
    bool isok=0,flag=0;
    while(!s.empty())
    {
        int mm=*(--s.end());
        if(!flag)
        {
            int ty=get_ty(mm);
            if(ty==4)break;
            if(ty==3)s.erase(--s.end());
            else if(ty==2)
            {
                s.erase(--s.end());
                int loc=0;
                for(int i=0;i<3;i++)
                    if(tot-c[i]>=mm)
                        loc=i;
                itr=s.upper_bound(c[loc]);
                if(itr!=s.begin())s.erase(--itr);
            }
            else if(ty==1)flag=1;
        }
        if(flag)
        {
            int loc=0;
            for(int i=2;i>=0;i--)
                if(c[i]>=mm)
                    loc=i;
            s.erase(--s.end());
            itr=s.upper_bound(c[loc==0]);
            bool dbk=1;
            if(itr==s.begin())dbk=0;
            else
            {
                int tt=*(--itr);
                s.erase(itr);
                itr=s.upper_bound(c[1+(loc<=1)]);
                if(itr==s.begin())
                {
                    s.insert(tt);
                    dbk=0;
                }
            }
            if(dbk)s.erase(--itr);
            else
            {
                itr=s.upper_bound(tot-c[loc]);
                if(itr!=s.begin())s.erase(--itr);
            }
        }
        isok=1;
        res++;
    }
    if(!isok)printf("-1\n");
    else printf("%d\n",res);
    return 0;
}