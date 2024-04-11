#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))
#define maxn 7010
#define mod 2520
int dp[2][maxn],num[2][maxn];
int n;
vector<int> v[2];


void bfs()
{
    queue<pair<int,int> > que;
    que.push(make_pair(0,0));
    que.push(make_pair(1,0));
    while(!que.empty())
    {
        int p=que.front().first;
        int pos=que.front().second;
        int x=dp[p][pos];
        que.pop();
        if(x==0)
        {
            for(int i=0; i<v[!p].size(); i++)
            {
                int nxt=(pos-v[!p][i]+n)%n;
                if(dp[!p][nxt]==-1)
                {
                    dp[!p][nxt]=1;
                    que.push(make_pair(!p,nxt));
                }
            }
        }
        else
        {
            for(int i=0; i<v[!p].size(); i++)
            {
                int nxt=(pos-v[!p][i]+n)%n;
                if(dp[!p][nxt]!=-1) continue;
                if(num[!p][nxt]<v[!p].size()) num[!p][nxt]++;
                if(num[!p][nxt]==v[!p].size())
                {
                    dp[!p][nxt]=0;
                    que.push(make_pair(!p,nxt));
                }
            }

        }
    }

}

int main ()
{
    memset(dp,-1,sizeof(dp));
    memset(num,0,sizeof(num));
    cin>>n;
    for(int i=0; i<2; i++)
    {
        int k;
        cin>>k;
        for(int j=0; j<k; j++)
        {
            int m;
            cin>>m;
            v[i].push_back(m);
        }
    }
    dp[0][0]=dp[1][0]=0;
    bfs();
    for(int i=0; i<2; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(dp[i][j]==0) cout<<"Lose"<<' ';
            else if(dp[i][j]==1) cout<<"Win"<<' ';
            else cout<<"Loop"<<' ';
        }
        cout<<endl;
    }
    return 0;
}