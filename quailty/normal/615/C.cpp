#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2105;
char s[MAXN],t[MAXN];
int p[MAXN<<1],v[MAXN<<1];
bool ok[MAXN<<1];
vector<pair<int,int> >res;
int main()
{
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t),r=0;
    bool isok=1;
    while(r<m)
    {
        int tot=0;
        for(int i=0;i<2*n;i++)
            ok[i]=0;
        for(int i=0;i<n;i++)
            if(s[i]==t[r])
            {
                p[tot++]=i;
                p[tot++]=i;
            }
        if(tot==0)
        {
            isok=0;
            break;
        }
        for(int i=0;i<tot;i++)
        {
            ok[i]=1;
            v[i]=p[i];
        }
        int cnt=tot,loc=0;
        while(r<m)
        {
            for(int i=tot-1;i>=0;i--)
                if(ok[i])
                {
                    if(v[i]>=0 && v[i]<n && t[r]==s[v[i]])
                    {
                        loc=i;
                        if(i&1)v[i]++;
                        else v[i]--;
                    }
                    else
                    {
                        ok[i]=0;
                        cnt--;
                    }
                }
            if(!cnt)break;
            r++;
        }
        res.push_back(make_pair(p[loc],v[loc]+(loc&1 ? -1 : 1)));
    }
    if(isok)
    {
        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();i++)
            printf("%d %d\n",res[i].first+1,res[i].second+1);
    }
    else printf("-1\n");
    return 0;
}