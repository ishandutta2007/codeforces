#include <bits/stdc++.h>
using namespace std;

inline int query(const vector<int> &s)
{
    if(s.empty())return 0;
    printf("? %zu",s.size());
    for(auto &i:s)
        printf(" %d",i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}

inline void guess(const vector<int> &s)
{
    printf("!");
    for(auto &i:s)
        printf(" %d",i);
    printf("\n");
    fflush(stdout);
    scanf("%*s");
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        vector<vector<int>> part(k);
        for(int i=0;i<k;i++)
        {
            int c;
            scanf("%d",&c);
            part[i].resize(c);
            for(int j=0;j<c;j++)
                scanf("%d",&part[i][j]);
        }
        vector<int> all(n);
        for(int i=0;i<n;i++)
            all[i]=i+1;
        int mx=query(all),l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            vector<int> que;
            for(int i=l;i<=m;i++)
                que.push_back(i);
            if(query(que)<mx)l=m+1;
            else r=m;
        }
        vector<int> res(k);
        for(int i=0;i<k;i++)
        {
            if(find(part[i].begin(),part[i].end(),l)==part[i].end())res[i]=mx;
            else
            {
                vector<int> que;
                for(int j=1;j<=n;j++)
                    if(find(part[i].begin(),part[i].end(),j)==part[i].end())
                        que.push_back(j);
                res[i]=query(que);
            }
        }
        guess(res);
    }
    return 0;
}