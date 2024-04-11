#include<bits/stdc++.h>
using namespace std;

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
	s[0]=0;
	for (int i=1; i<=n; i++) s[i]=s[i-1]+(a[i]==maa);
	for (int i=1; i<=n; i++) if (!v[i].empty()&&i!=maa)
	{
		ss[0]=200000;
		for (int j=1; j<=n; j++) ss[j]=ss[j-1]+(a[j]==maa)-(a[j]==i);
		for (int j=n; j>=0; j--)
			if (!p[ss[j]]) p[ss[j]]=j; else Ans=max(Ans,p[ss[j]]-j);
		for (int j=0; j<=n; j++) p[ss[j]]=0;
	}
	printf("%d\n",Ans);
	return 0;
}