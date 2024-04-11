#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=200005;
char s[MAXN];
set<int>d[2];
int main()
{
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        d[s[i]=='R'].insert(i);
    while(!d[0].empty() && !d[1].empty())
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                if(d[j].find(i)!=d[j].end())
                {
                    if(d[j^1].lower_bound(i)!=d[j^1].end())
                        d[j^1].erase(d[j^1].lower_bound(i));
                    else if(!d[j^1].empty())
                        d[j^1].erase(d[j^1].begin());
                }
    printf("%c\n","DR"[d[0].empty()]);
    return 0;
}