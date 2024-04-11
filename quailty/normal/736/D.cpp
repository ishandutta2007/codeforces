#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=2000;
const int MAXM=500000;
bitset<MAXN>a[MAXN],b[MAXN];
int l[MAXM],r[MAXM];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        l[i]--,r[i]--;
        a[l[i]][r[i]]=1;
    }
    for(int i=0;i<n;i++)
        b[i][i]=1;
    for(int i=0,j;i<n;i++)
    {
        for(int k=i;k<n;k++)
            if(a[k][i])j=k;
        swap(a[i],a[j]);
        swap(b[i],b[j]);
        for(int k=0;k<n;k++)
            if(k!=i && a[k][i]==1)
                a[k]^=a[i],b[k]^=b[i];
    }
    for(int i=0;i<m;i++)
        printf("%s\n",(b[r[i]][l[i]] ? "NO" : "YES"));
    return 0;
}