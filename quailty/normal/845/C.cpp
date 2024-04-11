#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
vector<pair<int,int> > e;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        e.push_back(make_pair(l,1));
        e.push_back(make_pair(r+1,-1));
    }
    sort(e.begin(),e.end());
    int cnt=0;
    for(int i=0;i<(int)e.size();i++)
    {
        cnt+=e[i].second;
        if(cnt>2)return 0*printf("NO\n");
    }
    return 0*printf("YES\n");
}