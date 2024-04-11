#include<bits/stdc++.h>
#define N 200010
#define M 2000010
#define mod 1000000007
#define mp make_pair
#define PII pair<int,int>
using namespace std;
int n,m,i,j,x,y,s[5],an[N];
set<PII >st1,st2;
set<PII >::iterator it,it1;
int main()
{
    scanf("%d%d",&n,&m);
    st1.insert(mp(0,0));
    st2.insert(mp(0,0));
    st1.insert(mp(n+1,m+1));
    st2.insert(mp(n+1,m+1));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%s",&x,&y,s+1);
        if(s[1]=='U')
        {
            it=st1.lower_bound(mp(x,0));
            it1=st2.lower_bound(mp(x,0));
            if((*it).first==x||(*it1).first==x)
            {
                puts("0");
                continue;
            }
            if((*it).first<(*it1).first)
                an[i]=an[(*it).second];
            else an[i]=(*it1).first;
            printf("%d\n",an[i]-x);
            st1.insert(mp(x,i));
        }else
        {
            it=--st2.upper_bound(mp(x,m+1));
            it1=--st1.upper_bound(mp(x,m+1));
            if((*it).first==x||(*it1).first==x)
            {
                puts("0");
                continue;
            }
            if((*it).first>(*it1).first)
                an[i]=an[(*it).second];
            else an[i]=(*it1).first;
            printf("%d\n",x-an[i]);
            st2.insert(mp(x,i));
        }
    }
}