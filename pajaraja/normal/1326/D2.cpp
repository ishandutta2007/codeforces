#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000007
using namespace std;
long long st[MAXN],lh[MAXN],rh[MAXN],inv[MAXN];
int n;
long long mmi(long long a,long long x)
{
	if(x==0) return 1;
	if(x&1) return (a*mmi(a,x-1))%MOD;
	return mmi((a*a)%MOD,x/2);
}
long long levihash(int l,int r)
{
	return ((lh[r]-lh[l-1]+MOD)*inv[l-1])%MOD;
}
long long desnihash(int l,int r)
{
	return ((rh[l]-rh[r+1]+MOD)*inv[n-r])%MOD;
}
bool checkpal(int l,int r)
{
	return levihash(l+1,r+1)==desnihash(l+1,r+1);
}
int main()
{
	st[0]=1; for(int i=1;i<MAXN;i++) st[i]=(st[i-1]*67)%MOD;
	inv[0]=1; for(int i=1;i<MAXN;i++) inv[i]=(inv[i-1]*mmi(67,MOD-2))%MOD;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		n=s.size();
		int lt=0,rt=n-1;
		while(rt>lt && s[lt]==s[rt]) {lt++; rt--;}
		for(int i=0;i<n+4;i++) lh[i]=rh[i]=0;
		for(int i=0;i<n;i++) lh[i+1]=(lh[i]+st[i]*(s[i]-'a'+1))%MOD;
		for(int i=n-1;i>=0;i--) rh[i+1]=(rh[i+2]+st[n-i-1]*(s[i]-'a'+1))%MOD;
		bool found=false;
		for(int i=rt-lt+1;i>0;i--)
		{
			if(checkpal(lt,lt+i-1))
			{
				for(int j=0;j<lt;j++) cout<<s[j];
				for(int j=lt;j<lt+i;j++) cout<<s[j];
				for(int j=rt+1;j<n;j++) cout<<s[j];
				found=true;
				cout<<endl;
				break;
			}
			if(checkpal(rt-i+1,rt))
			{
				for(int j=0;j<lt;j++) cout<<s[j];
				for(int j=rt-i+1;j<=rt;j++) cout<<s[j];
				for(int j=rt+1;j<n;j++) cout<<s[j];
				found=true;
				cout<<endl;
				break;
			}
		}
		if(!found)
		{
			for(int j=0;j<lt;j++) cout<<s[j];
			for(int j=rt+1;j<n;j++) cout<<s[j];
			cout<<endl;	
		}
	}
}