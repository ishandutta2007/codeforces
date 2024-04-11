#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=200005;
int a[MAXN],id[MAXN];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=max(0,a[i]-i);
        id[i]=i;
    }
    sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
    int res=0;
    set<int> st;
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        st.insert(i);
        while(!st.empty() && *(--st.end())>T-1-a[i])
            st.erase(--st.end());
        res=max(res,(int)st.size());
    }
    printf("%d\n",res);
    return 0;
}