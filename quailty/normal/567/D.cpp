#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
const int MAXN=200005;
set<int>st;
set<int>::iterator itr,l,r;
int x[MAXN];
int main()
{
    int n,k,a,m;
    scanf("%d%d%d%d",&n,&k,&a,&m);
    for(int i=1;i<=m;i++)scanf("%d",&x[i]);
    st.insert(0);
    st.insert(n+1);
    int now=(n+1)/(a+1);
    int ans=-1;
    for(int i=1;i<=m;i++)
    {
        //if(st.find(x[i])!=st.end())continue;
        st.insert(x[i]);
        itr=st.lower_bound(x[i]);
        l=itr;
        r=itr;
        l--;
        r++;
        now-=(*r-*l)/(a+1);
        now+=(*itr-*l)/(a+1);
        now+=(*r-*itr)/(a+1);
        if(now<k)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}