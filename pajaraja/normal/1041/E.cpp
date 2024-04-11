#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int cnt[MAXN];
vector<int> s[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		if(t1!=n && t2!=n) {printf("NO"); return 0;}
		cnt[t1+t2-n]++;
	}
	for(int i=n-1;i>0;i--)
	{
		if(cnt[i]>0) {s[i].push_back(i); continue;}
		else
		{
			for(int j=n-1;j>0;j--) if(s[j].size()!=cnt[j])
			{
				if(j<i) {printf("NO"); return 0;}
				s[j].push_back(i);
				j=0;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<n;i++) if(s[i].size()>0) for(int j=0;j<s[i].size()-1;j++) printf("%d %d\n",s[i][j],s[i][j+1]);
	for(int i=1;i<n;i++) if(s[i].size()>0) printf("%d %d\n",s[i][s[i].size()-1],n);
}