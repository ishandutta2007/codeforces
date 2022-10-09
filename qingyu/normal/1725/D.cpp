#include <bits/stdc++.h>
#define int long long
using namespace std;
int up[100105],sup[100105];
int W(int x)
{
	int rtn=0;
	while(!(x&1)) x>>=1,++rtn;
	return x+rtn;
}
signed main()
{
//	freopen("data.txt","r",stdin);
//	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int l=0,r=1e5,p=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int s=0;
		for(int i=0;i<=100000;i++)
			s+=max((mid-i+1)/2,0ll);
		if(s<=n) p=mid,l=mid+1;
		else r=mid-1;
	}
	int S=0;
	for(int i=0;i<=100000;i++)
		S+=up[i]=max((p-i+1)/2,0ll);
	for(int i=100000;i>=0;i--)
		if(S<n&&up[i]*2+1+i<=p+1) ++S,++up[i];
//	for(int i=0;i<=100000;i++)
//		if(S<n&&up[i]*2+1+i<=p+2) ++S,++up[i];
	int ans1=0;
	for(int i=0;i<=100000;i++)
		ans1+=up[i]*i+(up[i]*up[i]);
	sup[0]=up[0];
	for(int i=1;i<=100000;i++) sup[i]=up[i]+sup[i-1];
	cout << ans1 << "\n";
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		int L=0,R=100000,p=0;
		while(L<=R)
		{
			int mid=(L+R)/2;
			if(sup[mid]>=x) p=mid,R=mid-1;
			else L=mid+1;
		}
		p-=30;
		p=max(p,0ll);
		if(p) x-=sup[p-1];
		L=0,R=1e18;
		int ANS=0;
		while(L<=R)
		{
			int mid=(L+R)/2;
			int sum=0;
			for(int x=p;x<=p+60;x++)
				sum+=min(up[x],((mid>>x-p)+1)/2);
			if(sum>=x) ANS=mid,R=mid-1;
			else L=mid+1;
	//		cout << L << ' ' << R << "\n";
		}
		cout << W(ANS)+p << "\n";
	}
	return 0;
}