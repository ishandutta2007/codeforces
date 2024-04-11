#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<pair<int,int>> e(n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&e[i].first,&e[i].second);
        sort(e.begin(),e.end());
        string res="";
        int nx=0,ny=0,fail=0;
        for(int i=0;i<n;i++)
        {
            if(ny>e[i].second)
            {
                fail=1;
                break;
            }
            while(nx<e[i].first)
                res+='R',nx++;
            while(ny<e[i].second)
                res+='U',ny++;
        }
        if(fail)printf("NO\n");
        else printf("YES\n%s\n",res.c_str());
    }
    return 0;
}