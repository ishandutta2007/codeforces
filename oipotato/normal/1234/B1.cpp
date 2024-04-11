#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        int now=0;
        set<int>s;
        queue<int>q;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            if(s.find(x)==s.end())
            {
                if(now==k)s.erase(q.front()),q.pop(),now--;
                s.insert(x);
                q.push(x);
                now++;
            }
        }
        printf("%d\n",now);
        vector<int>ans;
        rep(i,now)ans.pb(q.front()),q.pop();
        reverse(ans.begin(),ans.end());
        rep(i,now)printf("%d%c",ans[i-1]," \n"[i==now]);
    }
    return 0;
}