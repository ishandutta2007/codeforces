/*
	Code was directly taken from https://blog.csdn.net/szh_0808/article/details/80914512
	This is available before the contest
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<map>
#include<vector>
#include<ctime>
#include<stack>
#define pa pair<int,int>
#define INF 0x3f3f3f3f
#define inf 0x3f
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long

using namespace std;

inline ll read()
{
    long long f=1,sum=0;
    char c=getchar();
    while (c<'0' || c>'9')
    {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0' && c<='9')
    {
        sum=sum*10+c-'0';
        c=getchar();
    }
    return sum*f;
}
const int MAXN=400010;
struct node{
    int pos,opt,id;
    node () {}
    node (int pos,int opt,int id):pos(pos),opt(opt),id(id) {}
};
node v[MAXN];
int a[MAXN],b[MAXN];
int seg[MAXN],t[MAXN],num,cnt;
int x[MAXN];
int main()
{
    int n,L;
    scanf("%d%d",&L,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),num++,v[num]=node(a[i],1,i);
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]),num++,v[num]=node(b[i],-1,i);
    sort(v+1,v+1+num,[](node i,node j){return i.pos<j.pos;});
    v[num+1]=v[1],v[num+1].pos+=L;
    ll tot=0,sum=0;
    int opt=0;
    for (int i=1;i<=num;i++)
    {
        opt+=v[i].opt; 
        seg[++cnt]=v[i+1].pos-v[i].pos;
        sum+=seg[cnt]; 
        t[cnt]=opt;
        tot+=(ll)seg[cnt]*t[cnt]; 
    }
    for (int i=1;i<=cnt;i++)
        x[i]=i;
    sort(x+1,x+1+cnt,[](int i,int j){return t[i]<t[j];});
    ll len=0,last=0,ans=1e18,pos;
    for (int i=1;i<=cnt;i++)
    {
        tot+=len*(t[x[i]]-last)-(sum-len)*(t[x[i]]-last);
        if (tot<ans) ans=tot,pos=x[i];
        last=t[x[i]];
        len+=seg[x[i]];
    }
    cout<<ans<<endl;
    stack <node> s;
    int now=pos+1;
    tot=0;
    while (tot<n)
    {
        if (now>num) now=1;
        if (v[now].opt==1)
        {
            if (s.empty() || s.top().opt==1) s.push(v[now++]);
            else x[v[now++].id]=s.top().id,s.pop(),tot++;
        }
        else
        {
            if (s.empty() || s.top().opt==-1) s.push(v[now++]);
            else x[s.top().id]=v[now++].id,s.pop(),tot++;
        }
    } 
    for (int i=1;i<=n;i++)
        printf("%d ",x[i]);
    return 0;
}