#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int>c[3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        c[t-1].push_back(i+1);
    }
    int m=min({c[0].size(),c[1].size(),c[2].size()});
    printf("%d\n",m);
    for(int i=0;i<m;i++)
        printf("%d %d %d\n",c[0][i],c[1][i],c[2][i]);
    return 0;
}