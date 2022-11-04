#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=200005;
int a[MAXN],t[MAXN];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    vector<pair<int,int> > chs[2];
    db res=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]==T)res+=a[i];
        else if(t[i]>T)chs[0].push_back({t[i]-T,a[i]});
        else chs[1].push_back({T-t[i],a[i]});
    }
    for(int i=0;i<2;i++)
        sort(chs[i].begin(),chs[i].end());
    ll sum[2]={0,0};
    for(int i=0;i<2;i++)
        for(int j=0;j<(int)chs[i].size();j++)
            sum[i]+=1LL*chs[i][j].first*chs[i][j].second;
    int go=(sum[0]<sum[1]);
    for(int i=0;i<(int)chs[1-go].size();i++)
        res+=chs[1-go][i].second;
    for(int i=0;i<(int)chs[go].size();i++)
    {
        if(sum[1-go]>1LL*chs[go][i].first*chs[go][i].second)
        {
            res+=chs[go][i].second;
            sum[1-go]-=1LL*chs[go][i].first*chs[go][i].second;
        }
        else
        {
            res+=1.0*sum[1-go]/chs[go][i].first;
            break;
        }
    }
    printf("%.12f\n",res);
    return 0;
}