#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[2333];
int cnt[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cin>>(s+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			cnt[s[i]-'a']++;
		}
		int ans=0;
		for(int d=1;d<=k;d++)
		{
			if(k%d!=0)continue;
			for(int l=d;l<=n;l+=d)
			{
				int s=0;
				for(char ch='a';ch<='z';ch++)
				{
					s+=cnt[ch-'a']/(l/d);
				}
				if(s>=d)ans=max(ans,l);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}