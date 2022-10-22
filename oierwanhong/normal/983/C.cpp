#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(int& a,int t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}

#define MAXN 2011
int f[2][11][11][11][11],s[MAXN],t[MAXN],a[6],b[6];
int main()
{
    memset(f,0x3f,sizeof f);
    int n=read();int k=9;
    for(int i=1;i<=n;++i)s[i]=read(),t[i]=read();
    f[0][0][0][0][1]=0;
    for(int i=0;i<n;++i)
    {
        int now=i&1,nxt=!now;
        memset(f[nxt],0x3f,sizeof f[nxt]);
        for(a[1]=k;a[1]>=0;--a[1])
            for(a[2]=a[1];a[2]>=0;--a[2])
                for(a[3]=a[2];a[3]>=0;--a[3])
                    for(int pos=1;pos<=k;++pos)
                    {
                        int cur=f[now][a[1]][a[2]][a[3]][pos];
                        if(cur>int(1e8))continue;
                        // printf("f[%d][%d][%d][%d][%d]=%d\n",i,a[1],a[2],a[3],pos,cur);
                        memset(b,0,sizeof b);
                        for(int i=1;i<=3;++i)b[i]=a[i];
                        if(a[1])umin(f[now][a[2]][a[3]][0][a[1]],cur+abs(pos-a[1]));
                        if(a[2])umin(f[now][a[1]][a[3]][0][a[2]],cur+abs(pos-a[2]));
                        if(a[3])
                        {
                            umin(f[now][a[1]][a[2]][0][a[3]],cur+abs(pos-a[3]));
                            cur+=abs(pos-s[i+1]);
                            b[4]=t[i+1];
                            std::sort(b+1,b+5),std::reverse(b+1,b+5);
                            umin(f[nxt][b[2]][b[3]][b[4]][b[1]],cur+abs(s[i+1]-b[1]));
                            umin(f[nxt][b[1]][b[3]][b[4]][b[2]],cur+abs(s[i+1]-b[2]));
                            umin(f[nxt][b[1]][b[2]][b[4]][b[3]],cur+abs(s[i+1]-b[3]));
                            umin(f[nxt][b[1]][b[2]][b[3]][b[4]],cur+abs(s[i+1]-b[4]));
                        }
                        else
                        {
                            memset(b,0,sizeof b);
                            for(int x=1;x<=3;b[x]=a[x], ++x)
                                if(!a[x])
                                {
                                    b[x]=t[i+1],std::sort(b+1,b+5),std::reverse(b+1,b+5);
                                    umin(f[nxt][b[1]][b[2]][b[3]][s[i+1]],cur+abs(pos-s[i+1]));
                                    break;
                                }
                        }
                        
                    }
    }
    int ans=1e9;
    for(a[1]=k;a[1]>=0;--a[1])
        for(a[2]=a[1];a[2]>=0;--a[2])
            for(a[3]=a[2];a[3]>=0;--a[3])
                for(int pos=1;pos<=k;++pos)
                {
                    int cur=f[n&1][a[1]][a[2]][a[3]][pos];
                    if(cur>int(1e8))continue;
                    // printf("f[%d][%d][%d][%d][%d]=%d\n",n,a[1],a[2],a[3],pos,cur);
                    
                    if(a[1])umin(f[n&1][a[2]][a[3]][0][a[1]],cur+abs(pos-a[1]));
                    else umin(ans,cur);
                    if(a[2])umin(f[n&1][a[1]][a[3]][0][a[2]],cur+abs(pos-a[2]));
                    if(a[3])umin(f[n&1][a[1]][a[2]][0][a[3]],cur+abs(pos-a[3]));
                }
    printf("%d",ans+n*2);
    return 0;
}