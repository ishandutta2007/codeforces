#include<bits/stdc++.h>
using namespace std;

vector<int> v[101];
vector<int>::iterator it;
int sg[200001],n,p[200001],f,cnt,ans,A,B,C;
bool bo[200001],b[200001];

int main()
{
	memset(bo,1,sizeof(bo));
	bo[1]=0;
	for (int i=2; i<=200000; i++)
		if (bo[i])
			for (int j=(i<<1); j<=200000; j+=i) bo[j]=0,p[j]=i;
	for (int i=200000; i; i--)
		if (!bo[i]&&p[i]&&bo[i/p[i]]) bo[i]=1;
	scanf("%d%d",&n,&f); bo[f]=0; v[0].push_back(0);
	memset(sg,0,sizeof(sg));
	for (int i=1; i<=200000; i++)
	{
		for (int j=0; j<=100; j++)
		{
			int k=v[j].size();k--;
			for (;k>=0 && !bo[i-v[j][k]];--k);
			if (k>=0)sg[i]=j+1;else break;
		}
		v[sg[i]].push_back(i);
	}
	ans=0;
	while (n--)
	{
		scanf("%d%d%d",&A,&B,&C);
		ans^=sg[B-A-1]; ans^=sg[C-B-1];
	}
	if (ans) puts("Alice"),puts("Bob");
	else puts("Bob"),puts("Alice");
	return 0;
}