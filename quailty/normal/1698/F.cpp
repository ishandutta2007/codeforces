#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int a[MAXN],b[MAXN];
int solve()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	vector<pair<int,int>> pa,pb;
	for(int i=1;i+1<=n;i++)
	{
		pa.emplace_back(min(a[i],a[i+1]),max(a[i],a[i+1]));
		pb.emplace_back(min(b[i],b[i+1]),max(b[i],b[i+1]));
	}
	sort(pa.begin(),pa.end());
	sort(pb.begin(),pb.end());
	if(a[1]!=b[1] || a[n]!=b[n] || pa!=pb)return 0*printf("NO\n");
	vector<pair<int,int>> res;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])continue;
		bool isok=0;
		for(int j=i;j+1<=n && !isok;j++)
			if(a[j]==a[i-1] && a[j+1]==b[i])
				for(int l=i;l<=j && !isok;l++)
					for(int r=j+1;r<=n && !isok;r++)
						if(a[l]==a[r])
						{
							res.emplace_back(l,r);
							reverse(a+l,a+r+1);
							isok=1;
						}
		for(int j=i;j+1<=n;j++)
			if(a[j]==b[i] && a[j+1]==a[i-1])
			{
				res.emplace_back(i-1,j+1);
				reverse(a+i-1,a+j+2);
				break;
			}
	}
	printf("YES\n%zu\n",res.size());
	for(auto& [l,r] : res)
		printf("%d %d\n",l,r);
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}