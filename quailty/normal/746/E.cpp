#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int a[200005];
set<int>st;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt[2]={0,0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(st.find(a[i])==st.end())
        {
            cnt[a[i]&1]++;
            st.insert(a[i]);
        }
        else a[i]=0;
    }
    for(int _=0;_<2;_++)
        for(int i=0;i<n;i++)if(a[i])
        {
            int k=a[i]&1;
            if((_ ? 1 : (a[i]<=m)) && cnt[k]>n/2)
            {
                a[i]=0;
                cnt[k]--;
                st.erase(a[i]);
            }
        }
    int res=0;
    for(int i=0;i<n;i++)
        res+=(a[i]==0);
    for(int _=0;_<2;_++)
        for(int i=0,r=n/2-cnt[_],t=2-_;i<n && r;i++)if(!a[i])
        {
            while(st.find(t)!=st.end())t+=2;
            if(t>m)break;
            a[i]=t;
            st.insert(t);
            r--;
        }
    for(int i=0;i<n;i++)
        if(!a[i])return 0*printf("-1");
    printf("%d\n",res);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}