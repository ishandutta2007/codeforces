#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;scanf("%d",&n);
		int lasta=0,lastb=0;
		bool flag=1;
		for(;n--;)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a<lasta||b<lastb||a-lasta<b-lastb)flag=0;
			lasta=a;lastb=b;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}