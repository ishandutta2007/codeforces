#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,k;
vector<int> v[4];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		char s[5];
		int x,y;
		scanf("%s%d",&s,&x);
		y=(s[0]-'0')*2+(s[1]-'0');
		v[y].push_back(x);
	}
	for (int i=0;i<3;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for (int i=0;i<v[3].size();i++)
	{
		cnt++;
		k++;
		ans+=v[3][i];
	}
	for (int i=0;i<v[1].size() && i<v[2].size();i++)
	{
		cnt+=2;
		k++;
		ans+=v[1][i]+v[2][i];
	}
	int t;
	if ((int)(v[1].size())>(int)(v[2].size()))
	{
		t=1;
	}
	else
	{
		t=2;
	}
	int i=0,j=cnt-k;
	//cout<<i<<" "<<j<<endl;
	cnt=k*2-cnt;
	assert(cnt>=0);
	while (cnt && (i<(int)v[0].size() || j<(int)v[t].size()))
	{
		cnt--;
		if (i<(int)v[0].size() && (j==(int)v[t].size() || v[0][i]>v[t][j]))
		{
			ans+=v[0][i++];
		}
		else
		{
			ans+=v[t][j++];
		}
	}
	printf("%d\n",ans); 
	return 0;
}