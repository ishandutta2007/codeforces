#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int a[100007];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,x;
        scanf("%d%d%d",&n,&m,&x);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        while(!pq.empty()) pq.pop();
        printf("YES\n");
        for(int i=0;i<m;i++) pq.push({0,i+1});
        for(int i=0;i<n;i++)
        {
            pair<int,int> pr=pq.top();
            pq.pop();
            pr.first+=a[i];
            printf("%d ",pr.second);
            pq.push(pr);
        }
        printf("\n");
    }
}