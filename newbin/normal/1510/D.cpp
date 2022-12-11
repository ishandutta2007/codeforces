#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) (vec).begin(),(vec).end()
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int n,d;
vector<int>fac[10];
double sum[10][5];
int ans[10],now[10];
double mx=-1;
int len[]={0,0,3,3,1,0,0,3,3,1};
void dfs(int num)
{
    //cout<<num<<endl;
    if(num==10)
    {
        double ss=0;
        int bs=-1;
        for(int i=0;i<10;i++)
        {
            if(now[i]==-1) continue;
            if(bs==-1) bs=1;
            for(int j=0;j<=now[i];j++) bs=bs*i%10;
            ss+=sum[i][now[i]];
        }
        if(ss>mx&&bs==d) memcpy(ans,now,sizeof(ans)),mx=ss;
        return;
    }
    for(int i=-1;i<=len[num]&&i<(int)fac[num].size();i++)
    {
        now[num]=i;
        dfs(num+1);
    }
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        fac[a[i]%10].pb(a[i]);
    }
    for(int i=0;i<10;i++) sort(all(fac[i]),greater<int>());
    for(int i=0;i<10;i++)
    {
        int p=0;
        int zz=len[i]+1;
        for(auto x:fac[i])
        {
            sum[i][p]=log(x)+sum[i][(p-1+zz)%zz];
            p++;
            p%=zz;
        }
    }
    dfs(0);
    if(mx==-1) {puts("-1"); exit(0);}
    vector<int>res;
    for(int i=0;i<10;i++)
    {
        if(ans[i]==-1) continue;
        if(fac[i].empty()) continue;
        while((fac[i].size()-ans[i]-1)%(len[i]+1)) fac[i].pop_back();
        for(auto x:fac[i]) res.pb(x);
    }
    sort(all(res));
    cout<<res.size()<<endl;
    for(auto x:res) printf("%d ",x);
	return 0;
}
/*
10 6
2 2 2 2 2 2 2 2 2 2
*/