#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char a[1010],b[1010];
vector<int>ans;
void work(int k)
{
    ans.pb(k);
    reverse(a+1,a+k+1);
    rep(i,k)a[i]=((a[i]-'0')^1)+'0';
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        scanf("%s%s",a+1,b+1);
        ans.clear();
        for(int i=n;i;i--)
        if(a[1]==b[i])work(1),work(i);else work(i);
        printf("%d",(int)ans.size());
        for(auto i:ans)printf(" %d",i);
        puts("");
    }
    return 0;
}