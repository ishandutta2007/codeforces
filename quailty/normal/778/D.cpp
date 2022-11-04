#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[55][55];
bool check(int n,int m,int t)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=="LU"[t])return 0;
    return 1;
}
vector<pair<int,int> > solve(int n,int m)
{
    vector<pair<int,int> >res;
    while(1)
    {
        while(1)
        {
            bool isok=1;
            for(int i=0;i<n-1;i++)
                for(int j=0;j<m-1;j++)
                    if(s[i][j]=='L' && s[i][j+1]=='R'
                    && s[i+1][j]=='L' && s[i+1][j+1]=='R')
                    {
                        isok=0;
                        s[i][j]='U',s[i][j+1]='U';
                        s[i+1][j]='D',s[i+1][j+1]='D';
                        res.push_back(make_pair(i+1,j+1));
                    }
            if(isok)break;
        }
        if(n%2==0 && check(n,m,0))break;
        while(1)
        {
            bool isok=1;
            for(int i=0;i<n-1;i++)
                for(int j=0;j<m-1;j++)
                    if(s[i][j]=='U' && s[i][j+1]=='U'
                    && s[i+1][j]=='D' && s[i+1][j+1]=='D')
                    {
                        isok=0;
                        s[i][j]='L',s[i][j+1]='R';
                        s[i+1][j]='L',s[i+1][j+1]='R';
                        res.push_back(make_pair(i+1,j+1));
                    }
            if(isok)break;
        }
        if(n%2==1 && check(n,m,1))break;
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    vector<pair<int,int> >lef=solve(n,m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    vector<pair<int,int> >rig=solve(n,m);
    printf("%d\n",(int)(lef.size()+rig.size()));
    for(int i=0;i<(int)lef.size();i++)
        printf("%d %d\n",lef[i].first,lef[i].second);
    for(int i=(int)rig.size()-1;i>=0;i--)
        printf("%d %d\n",rig[i].first,rig[i].second);
    return 0;
}