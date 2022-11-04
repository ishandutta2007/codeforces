#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > edge;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<n-1)return 0*printf("Impossible\n");
    for(int i=2;i<=n;i++)
        edge.push_back({1,i});
    for(int i=2;i<=min(n,1000);i++)
        for(int j=i+1;j<=min(n,1000);j++)
            if(__gcd(i,j)==1 && (int)edge.size()<m)edge.push_back({i,j});
    if((int)edge.size()<m)return 0*printf("Impossible\n");
    printf("Possible\n");
    for(int i=0;i<m;i++)
        printf("%d %d\n",edge[i].first,edge[i].second);
    return 0;
}