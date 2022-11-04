#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int a[300005];
map<int,int>mp;
vector<pair<int,int> >res;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int la=1;
    for(int i=1;i<=n;i++)
    {
        if(!mp[a[i]])mp[a[i]]=i;
        else
        {
            res.push_back(make_pair(la,i));
            mp.clear();
            la=i+1;
        }
    }
    if(res.empty())printf("-1\n");
    else
    {
        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();i++)
        {
            printf("%d %d\n",res[i].first,(i<(int)res.size()-1 ? res[i].second : n));
        }
    }
    return 0;
}