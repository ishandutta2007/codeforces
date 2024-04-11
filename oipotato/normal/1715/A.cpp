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
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1&&m==1){puts("0");continue;}
		printf("%d\n",min(2*n+m,2*m+n)-2);
	}
    return 0;
}