#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int dp[501][5001];
pair<int,int> pre[501][5001];
pair<int,int> kraj={-1,-1};
int main()
{
    int d,s;
    scanf("%i %i",&d,&s);
    memset(dp,-1,sizeof(dp));
    queue<pair<int,int> > q;
    q.push({0,0});
    dp[0][0]=-2;
    pre[0][0]=kraj;
    while(!q.empty())
    {
        int mod=q.front().first;
        int sum=q.front().second;
        //printf("Usao za %i %i\n",mod,sum);
        q.pop();
        if(mod==0&&sum==s)
        {
            string broj;
            pair<int,int> tr=make_pair(mod,sum);
            while(pre[tr.first][tr.second]!=kraj)
            {
                //printf("%i, %i, dp: %i, pre: %i %i\n",tr.first,tr.second,dp[tr.first][tr.second],pre[tr.first][tr.second].first,pre[tr.first][tr.second].second);
                broj+=dp[tr.first][tr.second]+'0';
                tr=pre[tr.first][tr.second];
            }
            reverse(broj.begin(),broj.end());
            cout << broj;
            return 0;
        }
        for(int j=0;j<=9;j++)
        {
            int m=(mod*10+j)%d;
            int ss=sum+j;
            if(ss<=s&&dp[m][ss]==-1)
            {
                //printf("Dodajem %i %i\n",m,ss);
                dp[m][ss]=j;
                pre[m][ss]=make_pair(mod,sum);
                q.push(make_pair(m,ss));
            }
        }
    }
    printf("-1\n");
    return 0;
}