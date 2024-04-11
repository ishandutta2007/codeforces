#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
int f[8][1111];
int A[1111];


vector<int> a[1111][8];
int dp[1111][256];

vector<int> ty_PIDOR[256];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        A[i]--;
    }

    for(int d=0;d<8;d++)
        f[d][n]=-1;

    for(int j=n-1;j>=0;j--)
        for(int d=0;d<8;d++)
        {
            f[d][j]=f[d][j+1];
            if (A[j]==d)
                f[d][j]=j;
        }


    for(int j=0;j<n;j++)
        for(int d=0;d<8;d++)
        {
            int curr=j;
            while(curr <= n-1)
            {
                if (f[d][curr]==-1)
                    break;
                a[j][d].push_back(f[d][curr]);
                curr=f[d][curr]+1;
            }
        }


    for(int mask=0;mask<(1<<8);mask++)
    {
        for(int d=0;d<8;d++)
        {
            if ((mask>>d)&1)
                continue;
            ty_PIDOR[mask].push_back(d);
        }
    }

    int answer=0;
    for(int minn=0;8*minn<=n;minn++)
    {
        for (int pos=n;pos>=0;pos--)
        {
            for(int mask=(1<<8)-1;mask>=0;mask--)
            {
                if (mask == ((1<<8)-1))
                {
                    dp[pos][mask]=0;
                    continue;
                }

                if (pos == n)
                {
                    dp[pos][mask]=-1e9;
                    continue;
                }
                int left = 8-__builtin_popcount(mask);
                if (left*minn > n-pos)
                {
                    dp[pos][mask]=-1e9;
                    continue;
                }
                bool ok=true;
                for (int d : ty_PIDOR[mask])
                    if (a[pos][d].size() < minn)
                        ok=false;
                if (!ok)
                {
                    dp[pos][mask]=-1e9;
                    continue;
                }
                int answer = -1e9;
                for(int d : ty_PIDOR[mask])
                {
                    for(int c=minn;c<=minn+1;c++)
                    {
                        if (a[pos][d].size()<c)
                            break;
                        answer = max(answer, c+dp[(c>0?a[pos][d][c-1]+1:pos)][mask|(1<<d)]);
                    }
                }
                dp[pos][mask]=answer;
            }
        }
        answer = max(answer, dp[0][0]);
    }
    cout << answer << endl;



}