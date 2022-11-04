#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int s[2][MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int r=0;r<2;r++)
        for(int i=0;i<n;i++)
            scanf("%d",&s[r][i]);
    for(int r=0;r<2;r++)
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            s[r][i]-=t;
        }
    if(accumulate(s[0],s[0]+n,0)+accumulate(s[1],s[1]+n,0)!=0)
        return 0*printf("-1\n");
    queue<int,list<int>> que[2][2];
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int u=s[0][i],d=s[1][i];
        for(int r=0;r<2;r++)
        {
            if(u!=0 && !que[r][u>0].empty())
            {
                int c=que[r][u>0].front();
                que[r][u>0].pop();
                res+=i-c+r,u=0;
            }
            if(d!=0 && !que[r^1][d>0].empty())
            {
                int c=que[r^1][d>0].front();
                que[r^1][d>0].pop();
                res+=i-c+r,d=0;
            }
        }
        if(u!=0 && d!=0 && u==-d)res++;
        else
        {
            if(u!=0)que[0][u<0].push(i);
            if(d!=0)que[1][d<0].push(i);
        }
    }
    return 0*printf("%lld\n",res);
}
int main()
{
    int T=1;
    while(T--)solve();
    return 0;
}
/*
3
0 1 0
0 1 0
0 0 1
1 0 0
*/