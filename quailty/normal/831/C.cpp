#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=2005;
int a[MAXN],b[MAXN];
set<int> st,res;
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=k;i++)
    {
        int f=b[1];
        for(int j=1;j<=i;j++)
            f-=a[j];
        for(int j=1;j<=n;j++)
            st.insert(b[j]);
        for(int j=1;j<=k;j++)
            f+=a[j],st.erase(f);
        if(st.empty())res.insert(f);
    }
    return 0*printf("%d",(int)res.size());
}