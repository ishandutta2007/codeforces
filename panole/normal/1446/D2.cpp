#include<bits/stdc++.h>
using namespace std;

const int B=400;
int n,a[200010],s[200010],sta[200010],tp,l,r,mid,ans,Ans,ss[200010],p[400010];
vector<int> v[200010];

int main()
{
	Ans=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
	int ma=0,maa;
	for (int i=1; i<=n; i++)
		if (v[i].size()>ma) maa=i,ma=v[i].size(); else
		if (v[i].size()==ma) maa=-1;
	if (maa==-1) return printf("%d\n",n),0;
	for (int i=1; i<=n; i++) if (v[i].size()>=B&&i!=maa)
	{
		ss[0]=200000;
		for (int j=1; j<=n; j++) ss[j]=ss[j-1]+(a[j]==maa)-(a[j]==i);
		for (int j=n; j>=0; j--)
			if (!p[ss[j]]) p[ss[j]]=j; else Ans=max(Ans,p[ss[j]]-j);
		for (int j=0; j<=n; j++) p[ss[j]]=0;
	}
	p[0]=0; int sz=v[maa].size();
	for (int i=0; i<sz; i++) p[i+1]=v[maa][i];
	p[sz+1]=n+1;
	for (int i=0; i<=sz; i++)
	{
		int ma=0;
		for (int j=i+1; j<=sz+1&&j<=i+B+1; j++)
		{
			for (int k=p[j-1]+1; k<p[j]; k++) 
			{
				s[a[k]]++;
				if (s[a[k]]>ma) ma=s[a[k]];
			}
			if (ma==j-i-1) Ans=max(Ans,p[j]-p[i]-1);
		}
		for (int j=i+1; j<=sz+1&&j<=i+B+1; j++)
			for (int k=p[j-1]+1; k<p[j]; k++) s[a[k]]=0;
	}
	printf("%d\n",Ans);
	return 0;
}