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
        int n;scanf("%d",&n);
        char s[110];scanf("%s",s+1);
        vector<int>ans;
        rep(i,n)
        if(s[i]=='B')
        {
            int j=i;
            for(;s[j]=='B';j++);
            ans.pb(j-i);
            i=j;
        }
        int cnt=ans.size();
        printf("%d\n",cnt);
        rep(i,cnt)printf("%d%c",ans[i-1]," \n"[i==cnt]);
    }
    return 0;
}