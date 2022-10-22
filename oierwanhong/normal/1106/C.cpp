#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll INF=1ll<<60;
#define maxn 300001
ll n;
ll a[maxn],p[maxn];

void Sort(ll l,ll r)// sort  a[] in O(nlogn)
{
	if(l==r)return;
	ll mid=(l+r)>>1,i=l,j=mid+1,k=l;
	Sort(l,mid);Sort(mid+1,r);
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])p[k++]=a[i++];
		else p[k++]=a[j++];
	}
	while(i<=mid)p[k++]=a[i++];
	while(j<=r)p[k++]=a[j++];
	for(ll w=l;w<=r;++w)a[w]=p[w];
}

int main()
{
	std::cin>>n;
	for(ll i=1;i<=n;++i)std::cin>>a[i];
	Sort(1,n);
	ll l=1,r=n,res=0;
	while(l<r)
	{
		res+=(a[l]+a[r])*(a[l]+a[r]);
		++l;--r;
	}
	std::cout<<res;
	return 0;
}