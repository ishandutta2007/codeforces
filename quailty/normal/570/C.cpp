#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=300005;
char t[MAXN];
set<int>s;
set<int>::iterator itr,l,r;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",t);
    s.insert(-1);
    s.insert(n);
    int ans=n-1;
    for(int i=0;i<n;i++)
    {
        if(t[i]!='.')
        {
            s.insert(i);
            itr=s.lower_bound(i);
            l=r=itr;
            --l;
            ++r;
            ans-=max(0,*r-*l-2);
            ans+=max(0,*r-*itr-2);
            ans+=max(0,*itr-*l-2);
        }
    }
    int x;
    char c[5];
    while(m--)
    {
        scanf("%d%s",&x,c);
        --x;
        if(c[0]=='.' && t[x]!='.')
        {
            itr=s.lower_bound(x);
            l=r=itr;
            --l;
            ++r;
            ans-=max(0,*r-*itr-2);
            ans-=max(0,*itr-*l-2);
            ans+=max(0,*r-*l-2);
            s.erase(x);
            t[x]='.';
        }
        else if(c[0]!='.' && t[x]=='.')
        {
            s.insert(x);
            itr=s.lower_bound(x);
            l=r=itr;
            --l;
            ++r;
            ans-=max(0,*r-*l-2);
            ans+=max(0,*r-*itr-2);
            ans+=max(0,*itr-*l-2);
            t[x]=c[0];
        }
        printf("%d\n",ans);
    }
    return 0;
}