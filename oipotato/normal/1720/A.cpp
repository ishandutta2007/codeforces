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
	for(scanf("%d",&T);T--;)
	{
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		if((LL)a*d==(LL)b*c){puts("0");continue;}
		LL x=(LL)a*d,y=(LL)b*c;
		if(x>y)swap(x,y);
		if(x==0||y%x==0){puts("1");continue;}
		puts("2");
	}
    return 0;
}