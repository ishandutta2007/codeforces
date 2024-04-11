#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(int x)
{
    int limit=(int)floor(sqrt(x));
    for(int i=2;i<=limit;i++)if(x%i==0)return 1;
    return 0;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int cnt[10],n;scanf("%d",&n);
        char s[55];
        scanf("%s",s+1);
        rep(i,9)cnt[i]=0;
        rep(i,n)cnt[s[i]-'0']++;
        int pos=-1;
        rep(i,9)if(i!=2&&i!=3&&i!=5&&i!=7&&cnt[i]){pos=i;break;}
        if(pos!=-1)
        {
            printf("1\n%d\n",pos);
            continue;
        }
        rep(i,9)if(cnt[i]>=2){pos=i;break;}
        if(pos!=-1)
        {
            printf("2\n%d%d\n",pos,pos);
            continue;
        }
        int ans;
        rep(i,n)rep(j,n-1)
        {
            int x=(s[j]-'0')*10+(s[i]-'0');
            if(check(x)){ans=x;break;}
        }
        printf("2\n%d\n",ans);
    }
    return 0;
}