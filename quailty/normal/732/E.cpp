#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=200005;
set<pair<int,int> >computer;
pair<int,int>socket[MAXN];
int number[MAXN],match[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        computer.insert(make_pair(a,i));
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&socket[i].first);
        socket[i].second=i;
    }
    sort(socket+1,socket+m+1);
    int totNumber=0,totMatch=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=30;j++)
        {
            auto itr=computer.lower_bound(make_pair(socket[i].first,0));
            if(itr!=computer.end() && itr->first==socket[i].first)
            {
                totNumber+=j;
                totMatch+=1;
                number[socket[i].second]=j;
                match[itr->second]=socket[i].second;
                computer.erase(itr);
                break;
            }
            socket[i].first=(socket[i].first+1)/2;
        }
    }
    printf("%d %d\n",totMatch,totNumber);
    for(int i=1;i<=m;i++)
        printf("%d%s",number[i],(i<m ? " " : "\n"));
    for(int i=1;i<=n;i++)
        printf("%d%s",match[i],(i<n ? " " : "\n"));
    return 0;
}