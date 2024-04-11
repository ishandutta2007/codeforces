#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n,len,q0[200001],q1[200001],l0,r0,l1,r1;
char s[500001];
vector<int> ans[200001];

int main()
{
	scanf("%s",s); n=strlen(s);
	for (int i=0; i<=200000; i++) ans[i].clear();
	l0=l1=1; r0=r1=len=0;
	for (int i=0; i<n; i++)
		if (s[i]=='0')
		{
			if (l1>r1) ans[++len].push_back(i+1),q0[++r0]=len;
			else q0[++r0]=q1[l1],ans[q1[l1]].push_back(i+1),l1++;
		} else
		if (s[i]=='1')
		{
			if (l0>r0) {printf("-1\n"); return 0;}
			else q1[++r1]=q0[l0],ans[q0[l0]].push_back(i+1),l0++;
		}
	if (l1<=r1) {printf("-1\n"); return 0;}
	printf("%d\n",len);
	for (int i=1; i<=len; i++)
	{
		printf("%d ",ans[i].size());
		for (int j=0; j<ans[i].size(); j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}