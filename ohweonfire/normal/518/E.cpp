#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=1010101010;
int a[maxn],n,k;
bool ques[maxn];
void pro(int t)
{
	vector<int> nt,ct,mark,sol;
	nt.push_back(-inf);
	ct.push_back(0);
	for(int i=t;i<n;i+=k)
	{
		if(ques[i])
		{
			mark.push_back(i);
			ct[ct.size()-1]++;
		}
		else
		{
			nt.push_back(a[i]);
			ct.push_back(0);
		}
	}
	nt.push_back(inf);
	for(int i=0;i<ct.size();i++)
	{
		if(nt[i]+ct[i]>=nt[i+1])
		{
			puts("Incorrect sequence");
			exit(0);
		}
		if(ct[i]==0)
			continue;
		if(nt[i]>=0)
		{
			for(int j=1;j<=ct[i];j++)
				sol.push_back(nt[i]+j);
		}
		else if(nt[i+1]<=0)
		{
			for(int j=ct[i];j;j--)
				sol.push_back(nt[i+1]-j);
		}
		else if((-nt[i]-1)*2+1<=ct[i])
		{
			for(int j=1;j<=ct[i];j++)
				sol.push_back(nt[i]+j);
		}
		else if((nt[i+1]-1)*2+1<=ct[i])
		{
			for(int j=ct[i];j;j--)
				sol.push_back(nt[i+1]-j);
		}
		else
		{
			if(ct[i]%2==0)
			{
				sol.push_back(-(ct[i]>>1));
				ct[i]--;
			}
			ct[i]=(ct[i]-1)/2;
			for(int j=-ct[i];j<=ct[i];j++)
				sol.push_back(j);
		}
	}
	for(int i=0;i<sol.size();i++)
		a[mark[i]]=sol[i];
}
int main()
{
	scanf("%d%d",&n,&k);
	char s[15];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		if(s[0]=='?')
			ques[i]=true;
		else
			sscanf(s,"%d",a+i);
	}
	for(int i=0;i<k;i++)
		pro(i);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}