#include <bits/stdc++.h>

using namespace std;

bool prime[1000007];
vector <int> rozklad[1000007];
bool is[1000007];
int DP[1000007];

int main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!prime[i])
        {
            rozklad[i].push_back(i);
            for(int j=2*i;j<=1000000;j+=i)
            {
                prime[j]=1;
                rozklad[j].push_back(i);
            }
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,res=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        is[a]=1;
    }
    for(int i=1000000;i>0;i--)
    {
        if(is[i]) DP[i]++;
        res=max(res,DP[i]);
        for(int j=0;j<rozklad[i].size();j++)
        {
            DP[i/rozklad[i][j]]=max(DP[i/rozklad[i][j]],DP[i]);
        }
    }
    cout<<res;
    return 0;
}