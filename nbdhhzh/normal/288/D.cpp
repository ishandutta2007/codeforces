#include<cstdio>
#include<iostream>
using namespace std;
int n,v[200010],ne[200010],s[200010],l,head[200010],i,x,y;
unsigned long long ans,tt;
void add(int x,int y){v[++l]=y;ne[l]=head[x];head[x]=l;}
void dfs(int x,int y)
{
    unsigned long long ss=0;s[x]=1;
    for(int i=head[x];i;i=ne[i])
    if(v[i]!=y)
    {
        dfs(v[i],x);ss+=1llu*s[v[i]]*s[x];
        s[x]+=s[v[i]];
    }ans-=ss*ss+s[x]*(n-s[x])*ss*2;
}
int main()
{
    scanf("%d",&n);tt=1llu*n*(n-1)/2;ans=tt*tt;
    for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,0);cout<<ans<<endl;
}