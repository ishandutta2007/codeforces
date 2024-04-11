#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int dx[200010],dy[200010],n,x,y;
char s[200010];
bool check(int st)
{
    rep(i,n-st+1)
    {
        int l=i,r=i+st-1;
        int X=abs(x-(dx[n]-dx[r]+dx[l-1])),Y=abs(y-(dy[n]-dy[r]+dy[l-1]));
        if(X+Y<=st&&(st-X-Y)%2==0)return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,n)
    {
        dx[i]=dx[i-1];dy[i]=dy[i-1];
        if(s[i]=='U')dy[i]++;
        else if(s[i]=='D')dy[i]--;
        else if(s[i]=='L')dx[i]--;
        else dx[i]++;
    }
    scanf("%d%d",&x,&y);
    if(x==dx[n]&&y==dy[n]){puts("0");return 0;}
    else if(abs(x)+abs(y)>n||(n-abs(x)-abs(y))%2==1){puts("-1");return 0;}
    int l=0,r=n;
    for(;l<r-1;)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid;
    }
    printf("%d\n",r);
	return 0;
}