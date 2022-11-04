#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int> vis(n+1),rem,tar;
        for(int i=1,a;i<=n;i++)
        {
            scanf("%d",&a);
            if(a<=n && !vis[a])vis[a]=1;
            else rem.push_back(a);
        }
        for(int i=1;i<=n;i++)
            if(!vis[i])tar.push_back(i);
        sort(tar.begin(),tar.end());
        sort(rem.begin(),rem.end());
        assert(tar.size()==rem.size());
        bool isok=1;
        for(size_t i=0;i<rem.size();i++)
            isok&=(rem[i]>2*tar[i]);
        printf("%d\n",isok ? (int)rem.size() : -1);
    }
    return 0;
}