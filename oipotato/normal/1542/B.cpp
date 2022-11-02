#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void print(bool b){puts(b?"Yes":"No");}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a==1)print((n-1)%b==0);
		else
		{
			bool flag=0;
			for(LL i=1;i<=n;i*=a)flag|=(n-i)%b==0;
			print(flag);
		}
	}
    return 0;
}