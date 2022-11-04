#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
int c1[MAXN],c2[MAXN];
vector<pair<int,int> >ans;
int main()
{
    int n;
    scanf("%d",&n);
    int in,winner;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        if(i==n)winner=in;
        c1[i]=c1[i-1]+(in==1);
        c2[i]=c2[i-1]+(in==2);
    }
    for(int t=1;t<=n;t++)
    {
        int w1=0,w2=0,loc=0;
        while(loc<n)
        {
            int loc1=lower_bound(c1,c1+n+1,c1[loc]+t)-c1;
            int loc2=lower_bound(c2,c2+n+1,c2[loc]+t)-c2;
            loc=min(loc1,loc2);
            if(loc>n)break;
            if(loc1<loc2)w1++;
            else w2++;
        }
        if(loc==n)
            if((winner==1 && w1>w2)||(winner==2 && w1<w2))
                ans.push_back(make_pair(max(w1,w2),t));
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}