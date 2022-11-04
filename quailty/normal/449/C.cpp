#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
vector<int>f[MAXN],mp[MAXN];
#define ft first
#define sd second
vector<pair<int,int> >res;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t=i;
        for(int j=2;j*j<=t;j++)
            if(t%j==0)
            {
                f[i].push_back(j);
                while(t%j==0)t/=j;
            }
        if(t>1)f[i].push_back(t);
    }
    for(int i=2;i<=n;i++)
    {
        mp[f[i][(int)f[i].size()-1]].push_back(i);
        f[i].clear();
    }
    for(int i=n;i>=2;i--)
    {
        if((int)mp[i].size()<2)continue;
        else
        {
            if((int)mp[i].size()%2)
            {
                res.push_back(make_pair(mp[i][0],mp[i][2]));
                if(i>2)mp[2].push_back(mp[i][1]);
                for(int j=3;j<(int)mp[i].size();j+=2)
                    res.push_back(make_pair(mp[i][j],mp[i][j+1]));
            }
            else
            {
                for(int j=0;j<(int)mp[i].size();j+=2)
                    res.push_back(make_pair(mp[i][j],mp[i][j+1]));
            }
        }
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d %d\n",res[i].ft,res[i].sd);
}