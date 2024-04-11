#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
vector<int> r;
string c;
int m;
int DP[51][5001];
int minDP(int n,int k)
{
    if(k>=m)
        return 0;
    if(DP[n][k]!=0)
    {
        return DP[n][k];
    }
    int minn=INT_MAX/10;
    for(int i=0;i<r.size();i++)
    {
        if(r[i]>r[n]&&c[i]!=c[n])
        {
            minn=min(minn,minDP(i,k+r[i])+abs(i-n));
        }
    }
    DP[n][k]=minn;
    return minn;
}
int main()
{
    int n,s,k;
    scanf("%i %i %i",&n,&s,&k);
    m=k;
    r.resize(n);
    for(int i=0;i<n;i++)
        scanf("%i",&r[i]);
    cin >> c;
    s--;
    int l=INT_MAX/10;
    for(int i=0;i<n;i++)
    {
        l=min(l,minDP(i,r[i])+abs(s-i));
    }
    if(l>1e6)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",l);
    return 0;
}