#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=35;
const int MAXL=100005;
const int CNT=2;
int bas[CNT],mod[CNT];
bool isPrime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
void build()
{
    srand(time(NULL));
    int la=128;
    for(int i=0;i<CNT;i++)
    {
        bas[i]=la+rand()%64;
        while(!isPrime(bas[i]))bas[i]++;
        la=bas[i]+1;
    }
    random_shuffle(bas,bas+CNT);
    la=1000000000;
    for(int i=0;i<CNT;i++)
    {
        mod[i]=la+rand()%32768;
        while(!isPrime(mod[i]))mod[i]++;
        la=mod[i]+1;
    }
    random_shuffle(mod,mod+CNT);
}
char str[MAXL];
int p[MAXN],in[MAXL],h[CNT][MAXL],pw[CNT][MAXL];
void buildHash(int len)
{
    for(int _=0;_<CNT;_++)
        for(int i=(pw[_][0]=1);i<=len;i++)
        {
            h[_][i]=(1LL*h[_][i-1]*bas[_]+str[i])%mod[_];
            pw[_][i]=1LL*pw[_][i-1]*bas[_]%mod[_];
        }
}
long long getHash(int l,int r)
{
    long long now[2];
    for(int _=0;_<CNT;_++)
        now[_]=(h[_][r]-1LL*h[_][l-1]*pw[_][r-l+1]%mod[_]+mod[_])%mod[_];
    return now[0]*mod[1]+now[1];
}
vector<int>e[MAXL];
bool solve(int l,int r)
{
    for(int i=p[l];i<=p[r+1];i++)
        e[i].clear(),in[i]=0;
    for(int i=l;i<=r;i++)
    {
        e[p[r+1]].push_back(p[i]);
        for(int j=p[i];j<p[i+1];j++)
            for(int k=l;k<=r;k++)
            {
                if(p[k+1]-p[k]<p[i+1]-j)
                {
                    if(getHash(j,j+p[k+1]-p[k]-1)==getHash(p[k],p[k+1]-1))
                        e[j].push_back(j+p[k+1]-p[k]);
                }
                else if(p[k+1]-p[k]>p[i+1]-j)
                {
                    if(getHash(j,p[i+1]-1)==getHash(p[k],p[k]+p[i+1]-j-1))
                        e[j].push_back(p[k]+p[i+1]-j);
                }
                else
                {
                    if(j==p[i])continue;
                    if(getHash(j,p[i+1]-1)==getHash(p[k],p[k+1]-1))
                        e[j].push_back(p[r+1]);
                }
            }
    }
    for(int i=p[l];i<=p[r+1];i++)
        for(int j=0;j<(int)e[i].size();j++)
            in[e[i][j]]++;
    queue<int>q;
    for(int i=p[l];i<=p[r+1];i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
            if(--in[e[u][i]]==0)q.push(e[u][i]);
    }
    for(int i=p[l];i<=p[r+1];i++)
        if(in[i])return 0;
    return 1;
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    for(int i=(p[1]=1);i<=n;i++)
    {
        scanf("%s",str+p[i]);
        p[i+1]=p[i]+strlen(str+p[i]);
    }
    buildHash(p[n+1]-1);
    int res=0;
    for(int l=1,r=1;l<=n;l++)
    {
        while(r<=n && solve(l,r))r++;
        res+=r-l;
    }
    return 0*printf("%d",res);
}