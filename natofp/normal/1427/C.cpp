#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int roz = (1<<18);

int tree[roz];

void wstaw(int pos,int val)
{
    pos += roz/2;
    tree[pos] = val;
    pos /= 2;
    while(pos >= 1)
    {
        tree[pos] = max(tree[pos*2],tree[pos*2+1]);
        pos /= 2;
    }
}

int ask(int lo,int hi,int u,int a,int b)
{
    if(lo == a && b == hi)
    {
        return tree[u];
    }
    if(b<=a) return -1e9;
    int mid = (lo+hi)/2;
    int l = ask(lo,mid,u*2,a,min(b,mid));
    int r = ask(mid,hi,u*2+1,max(a,mid),b);
    return max(l,r);
}

const int nax = 1e5 + 5;

int x[nax];
int y[nax];
int tim[nax];

int dp[nax];
int ans = 0;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,n; cin>>r>>n;
    dp[0] = 0;
    x[0] = y[0] = 1;
    for(int i=0;i<roz/2;i++) wstaw(i,-1e9);
    wstaw(0,0);
    for(int i=1;i<=n;i++) dp[i] = -1e9;
    for(int i=1;i<=n;i++)
    {
        int tt,xx,yy; cin>>tt>>xx>>yy;
        for(int j=i-1;j>=i-2*r;j--)
        {
            if(j == -1) break;
            int d = abs(xx - x[j]) + abs(yy - y[j]);
            if(d <= tt - tim[j])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }

        int g = ask(0,roz/2,1,0,i-2*r);
        dp[i] = max(dp[i],g + 1);
        ans = max(ans,dp[i]);
        wstaw(i,dp[i]);

        x[i] = xx;
        y[i] = yy;
        tim[i] = tt;

    }



    cout<<ans;



    return 0;
}