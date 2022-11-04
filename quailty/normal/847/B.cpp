#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5+10;

int a[N];
vector<int> ans[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    set< pair<int,int> > s;
    s.insert({a[0],0});
    int cnt=0;
    ans[cnt++].push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        auto now=s.lower_bound({a[i],0});
        if(now==s.begin())
        {
            s.insert({a[i],cnt});
            ans[cnt++].push_back(a[i]);
        }
        else
        {
            now--;
            ans[now->second].push_back(a[i]);
            s.insert({a[i],now->second});
            s.erase(now);
        }
    }
    for(int i=0;i<cnt;i++)
        for(int j=0;j<ans[i].size();j++)
            printf("%d%c",ans[i][j],j+1==ans[i].size()?'\n':' ');
    return 0;
}