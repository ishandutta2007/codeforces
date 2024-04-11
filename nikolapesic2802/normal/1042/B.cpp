#include <bits/stdc++.h>

#define ll long long
#define pb push_back
const int inf=1000000009;
using namespace std;
int DP[1001][2][2][2];
int maxx;
pair<pair<int,int>,pair<int,int> > niz[1001];
int dp(int n,int a,int b,int c)
{
    //printf("Pozvan za %i %i %i %i\n",n,a,b,c);
    if(a==1&&b==1&&c==1)
        return 0;
    if(n==maxx)
        return inf;
    if(DP[n][a][b][c]!=-1)
        return DP[n][a][b][c];
    int a1=a,b1=b,c1=c;
    if(niz[n].first.second==1)
    {
        a1=1;
    }
    if(niz[n].second.first==1)
    {
        b1=1;
    }
    if(niz[n].second.second==1)
    {
        c1=1;
    }
    DP[n][a][b][c]=dp(n+1,a,b,c);
    DP[n][a][b][c]=min(DP[n][a][b][c],niz[n].first.first+dp(n+1,a1,b1,c1));
    return DP[n][a][b][c];
}
int main()
{
    int n;
    scanf("%i",&n);
    maxx=n;
    for(int i=0;i<n;i++)
    {
        DP[i][0][0][0]=-1;
        DP[i][0][0][1]=-1;
        DP[i][0][1][0]=-1;
        DP[i][0][1][1]=-1;
        DP[i][1][0][0]=-1;
        DP[i][1][0][1]=-1;
        DP[i][1][1][0]=-1;
        DP[i][1][1][1]=-1;
        int a;
        scanf("%i",&a);
        niz[i].first.first=a;
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='A')
            {
                niz[i].first.second=1;
            }
            if(s[j]=='B')
            {
                niz[i].second.first=1;
            }
            if(s[j]=='C')
            {
                niz[i].second.second=1;
            }
        }
    }
    dp(0,0,0,0);
    if(DP[0][0][0][0]==inf)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",DP[0][0][0][0]);
    return 0;
}