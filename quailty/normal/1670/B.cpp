#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
char s[MAXN];
int solve()
{
    int n,k;
    scanf("%d%s%d",&n,s,&k);
    int sp[26]={0};
    for(int i=1;i<=k;i++)
    {
        char buf[3];
        scanf("%s",buf);
        sp[*buf-'a']=1;
    }
    list<int> sp_idx;
    for(int i=0;i<n;i++)
        if(sp[s[i]-'a'])
            sp_idx.push_back(i);
    int res=0;
    while(!sp_idx.empty())
    {
        int cnt=0;
        for(auto& idx : sp_idx)
            if(idx>0)idx-=++cnt;
        for(auto itr=sp_idx.begin();itr!=sp_idx.end();)
        {
            auto nxt=next(itr);
            if(nxt==sp_idx.end())break;
            if(*itr==*nxt)itr=sp_idx.erase(itr++);
            else itr++;
        }
        if(!cnt)break;
        res++;
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}