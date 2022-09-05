#include<bits/stdc++.h>
using namespace std;

int T;
char s[200010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s); int n=strlen(s),sum=0;
		for (int i=0; i<n; i++) sum+=(s[i]-'a')+1;
		if (n&1)
		{
			if (n==1) printf("Bob %d\n",sum); else
			printf("Alice %d\n",sum-2*(min(s[0]-'a',s[n-1]-'a')+1));
		} else printf("Alice %d\n",sum);
	}
	return 0;
}