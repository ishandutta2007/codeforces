#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int MAXN=10005;
const ll base[2]={31,37};
const ll Mod[2]={998244353,1000000007};
int dp[MAXN],pre[MAXN];
unordered_map<ll,int>mp;
string dic[100005];
void output(int now)
{
    if(now==0)return;
    output(now-(int)dic[pre[now]].length());
    cout<<dic[pre[now]]<<" ";
}
int main()
{
    mp.max_load_factor(0.25);
    mp.reserve(1048576);
    ios::sync_with_stdio(false);
    string str;
    int n,m;
    cin>>n>>str>>m;
    for(int i=0;i<m;i++)
    {
        cin>>dic[i];
        ll now[2]={0,0};
        for(int j=0;j<(int)dic[i].length();j++)
        {
            int t=dic[i][j]-'a'+1;
            if(dic[i][j]>='A' && dic[i][j]<='Z')t+='a'-'A';
            for(int k=0;k<2;k++)
                now[k]=(now[k]*base[k]+t)%Mod[k];
        }
        ll tnow=now[0]*Mod[1]+now[1];
        mp[tnow]=i;
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        ll now[2]={0,0};
        for(int j=i;j>=max(0,i-1000);j--)
        {
            int t=str[j]-'a'+1;
            if(str[j]>='A' && str[j]<='Z')t+='a'-'A';
            for(int k=0;k<2;k++)
                now[k]=(now[k]*base[k]+t)%Mod[k];
            ll tnow=now[0]*Mod[1]+now[1];
            if(dp[j] && mp.find(tnow)!=mp.end())
            {
                dp[i+1]=1;
                pre[i+1]=mp[tnow];
            }
        }
    }
    output(n);
    return 0;
}