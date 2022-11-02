#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[55],cnt,apos[55],n,q;
int get(int x)
{
    int pos=0;
    rep(i,cnt)if(a[i]==x){pos=i;break;}
    if(pos)
    {
        for(int i=pos;i>1;i--)a[i]=a[i-1];
        a[1]=x;
        return pos;
    }
    int res=apos[x];
    rep(i,cnt)if(apos[a[i]]>apos[x])res++;
    for(int i=cnt+1;i>1;i--)a[i]=a[i-1];
    a[1]=x;cnt++;
    return res;
}
int main()
{
    scanf("%d%d",&n,&q);
    rep(i,n){int x;scanf("%d",&x);if(!apos[x])apos[x]=i;}
    rep(i,q)
    {
        int x;scanf("%d",&x);
        printf("%d%c",get(x)," \n"[i==q]);
    }
    return 0;
}