#include <bits/stdc++.h>
using namespace std;
int a[100007],b[100007],p[100007],n;
int main()
{
	int res=0,cmx=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) p[a[i]]=n+1-i;
	for(int i=n;i>0;i--)
	{
		b[i]=p[b[i]];
		cmx=max(cmx,b[i]);
		if(b[i]<cmx) res++;
	}
	cout<<res;
}