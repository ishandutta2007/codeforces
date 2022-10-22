#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll ii,jj;
}a[200005];
bool cmp1(node x,node y){
	return x.ii<y.ii||(x.ii==y.ii&&x.jj<y.jj);
}
bool cmp2(node x,node y){
	return x.jj<y.jj;
}
int main(){
	ll n,jian=0;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i].ii>>a[i].jj;
	sort(a+1,a+n+1,cmp1);
	ll l=1;
	for(ll i=2;i<=n;i++){
		if(a[i].ii!=a[i-1].ii||a[i].jj!=a[i-1].jj){
			jian+=((l-1)*l)>>1;
			l=1;
		}else l++;
	}
	jian+=((l-1)*l)>>1;
	ll ans=0;l=1;
	for(ll i=2;i<=n;i++){
		if(a[i].ii!=a[i-1].ii){
			ans+=((l-1)*l)>>1;
			l=1;
		}else l++;
	}
	ans+=((l-1)*l)>>1;
	sort(a+1,a+n+1,cmp2);
	l=1;
	for(ll i=2;i<=n;i++){
		if(a[i].jj!=a[i-1].jj){
			ans+=((l-1)*l)>>1;
			l=1;
		}else l++;
	}
	ans+=((l-1)*l)>>1;
	cout<<ans-jian;
	return 0;
}