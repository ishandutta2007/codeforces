#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],a1[N],a2[N];
int ans=-0x3f3f3f3f,n,k;
inline void work(int l,int r)
{
	int cnt1=0,cnt2=0,s=0;
	for (int i=1;i<l;i++) a1[++cnt1]=a[i];
	for (int i=r+1;i<=n;i++) a1[++cnt1]=a[i];
	for (int i=l;i<=r;i++) a2[++cnt2]=a[i],s+=a[i];
	sort(a1+1,a1+cnt1+1);sort(a2+1,a2+cnt2+1);
	for (int i=1;i<=cnt1 and i<=cnt2 and i<=k and a2[i]<a1[cnt1-i+1];i++)
		s-=a2[i],s+=a1[cnt1-i+1];
	ans=max(ans,s);
	return;
}
int main() 
{
    cin>>n>>k;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			work(i,j);
			cout<<ans;
}