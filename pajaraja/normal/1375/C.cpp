#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int p[MAXN];
bool kbl[MAXN],kbr[MAXN],pl[MAXN],pr[MAXN];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i];
		int mx=0,t=1;
		for(int i=n;i>=1;i--) 
		{
			mx=max(mx,p[i]);
			if(p[i]<mx) kbr[i]=true;
		}
		int mn=n+1; t=n;
		for(int i=1;i<=n;i++) 
		{
			mn=min(mn,p[i]);
			if(p[i]>mn) kbl[i]=true;
		}
		fill(pl,pl+n+7,true);
		fill(pr,pr+n+7,true);
		int mnk=0;
		for(int i=1;i<=n;i++)
		{
			if(mnk>p[i]) pl[i]=false;
			if(!kbl[i]) mnk=max(mnk,p[i]);
		}
		mnk=n+1;
		for(int i=n;i>=1;i--)
		{
			if(mnk<p[i]) pr[i]=false;
			if(!kbr[i]) mnk=min(mnk,p[i]);
		}
		bool fas=true;
		for(int i=1;i<n;i++) if(pr[i]&&pl[i]) fas=false;
		if(fas) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		fill(kbl,kbl+n+7,false);
		fill(kbr,kbr+n+7,false);
	}
}