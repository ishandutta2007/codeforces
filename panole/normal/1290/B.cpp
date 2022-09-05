#include<bits/stdc++.h>
using namespace std;

int n,q,nxt[200010][26];
char s[200010];

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for (int i=0; i<26; i++) nxt[n+1][i]=n+1;
	for (int i=n; i; i--) memcpy(nxt[i],nxt[i+1],sizeof(nxt[i])),nxt[i][s[i]-'a']=i;
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if (l==r) puts("Yes"); else
		{
			int cnt=0;
			for (int j=0; j<26; j++) if (nxt[l][j]<=r) cnt++;
			if (cnt==1) puts("No"); else
			if (cnt>=3) puts("Yes"); else
			{
				if (s[l]==s[r]) puts("No");
				else puts("Yes");
			}
		}
	}
	return 0; 
}