#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int ANSMOD=(int)1e9+7;
const int P=37,MOD=(int)1e9+7;
const int N=(int)1e6+10;
int f[N],save[N],h[N],g[N][2],pw[N],n,len[N];
char s[N];
vector<int>a[N],ha[N];
inline void add(int&x,int y){x+=y;if(x>=ANSMOD)x-=ANSMOD;}
int hsh(int id,int len,int x)
{
    if(!x||len<x)return ha[id][len];
    else return (1ll*(ha[id][x-1]-ha[id][x]+MOD)*pw[len-x+1]+ha[id][len+1])%MOD;
}
bool ok(int s1,int x,int s2,int y)
{
    if(x>len[s1])x=0;
    if(y>len[s2])y=0;
    int l=0,r=min(len[s1]+(!x),len[s2]+(!y));
    for(;l<r-1;)
    {
        int mid=(l+r)>>1;
        if(hsh(s1,mid,x)!=hsh(s2,mid,y))r=mid;else l=mid;
    }
    return l+1+(!!x)>len[s1]||(l+1+(!!y)<=len[s2]&&a[s1][!x||l+1<x?l+1:l+2]<=a[s2][!y||l+1<y?l+1:l+2]);
}
void work(int l1,int r1,int x,int F,int l2,int r2,int id)
{
    int len1=r1-l1+1,len2=r2-l2+1;
    if(ok(id-1,x-l1+1,id,0))add(save[id],F);
    int l=0,r=min(len1-1,len2)+1;
    for(;l<r-1;)
    {
        int mid=(l+r)>>1;
        if(hsh(id-1,mid,x-l1+1)!=hsh(id,mid,0))r=mid;else l=mid;
    }
    if(l2+l+1<=r2&&(l1+l+1>r1||a[id-1][l1+l>=x?l+2:l+1]<a[id][l+1]))add(h[l2+l+1],F);
    if(l2+l<=r2&&ok(id-1,x-l1+1,id,l+1))add(f[l2+l],F);
    if(l)add(g[l2+l-1][ok(id-1,x-l1+1,id,l)],F);
}
int main()
{
    scanf("%d",&n);
    pw[0]=1;
    rep(i,1000000)pw[i]=1ll*pw[i-1]*P%MOD;
    rep(i,n)
    {
        scanf("%s",s);
        len[i]=strlen(s);
        a[i].resize(len[i]+1);
        ha[i].resize(len[i]+1);
        rep(j,len[i])a[i][j]=s[j-1]-'a'+1;
        rep(j,len[i])ha[i][j]=(1ll*ha[i][j-1]*P+a[i][j])%MOD;
    }
    int now=1;
    rep(i,n)
    {
        if(i==1){rep(j,len[i])f[j]=1;save[i]=1;}
        else
        {
            for(int j=now+1;j<now+len[i];j++)add(h[j],h[j-1]);
            for(int j=now;j<now+len[i];j++)add(f[j],h[j]);
            int sum=0,ok=0;
            for(int j=now+len[i]-1;j>=now;j--)
            {
                add(sum,g[j][0]);add(sum,g[j][1]);
                add(ok,g[j][1]);
                if(j+1<now+len[i])
                {
                    if(a[i][j-now+1]>a[i][j-now+2])ok=0;
                    else if(a[i][j-now+1]<a[i][j-now+2])ok=sum;
                }
                add(f[j],ok);
            }
        }
        if(i==n)
        {
            int ans=save[i];
            for(int j=now;j<now+len[i];j++)add(ans,f[j]);
            printf("%d\n",ans);
        }
        else
        {
            for(int j=now;j<now+len[i];j++)if(f[j])work(now,now+len[i]-1,j,f[j],now+len[i],now+len[i]+len[i+1]-1,i+1);
            if(save[i])work(now,now+len[i],now+len[i],save[i],now+len[i],now+len[i]+len[i+1]-1,i+1);
        }
        now+=len[i];
    }
    return 0;
}