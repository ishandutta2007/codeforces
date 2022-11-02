#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int n,a[110],cnt[110],num,belong[110];
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]),cnt[a[i]]++;
    rep(i,100)if(cnt[i]!=2&&cnt[i])num++;
    int fk=0;
    rep(i,100)if(cnt[i]==1)fk++;
    if(fk%2==1&&num==fk){puts("NO");return 0;}
    puts("YES");
    int x=num/2,y=num/2;
    rep(i,100)
    if(cnt[i]==1)
    {
        if(x)belong[i]=-1,x--;
        else if(y)belong[i]=1,y--;
    }
    rep(i,100)
    if(cnt[i]>2)
    {
        if(x)belong[i]=-1,x--;
        else if(y)belong[i]=1,y--;
    }
    rep(i,n)
    if(!belong[a[i]])putchar('A');
    else if(belong[a[i]]==-1)
    {
        if(cnt[a[i]]>1)putchar('A'),cnt[a[i]]--;
        else putchar('B');
    }
    else
    {
        if(cnt[a[i]]>1)putchar('B'),cnt[a[i]]--;
        else putchar('A');
    }
    puts("");
	return 0;
}