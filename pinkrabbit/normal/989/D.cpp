#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long

int n; ll L,W;
ll x[100005],v[100005]; int p[100005];
bool cmp(int i,int j){return x[i]<x[j];}
ll a[100005]; int t;
ll Ans;

int main(){
	scanf("%d%I64d%I64d",&n,&L,&W);
	for(ll i=1;i<=n;++i) scanf("%I64d%I64d",x+i,v+i), p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(ll I=1;I<=n;++I){
		ll i=p[I];
		if(v[i]==1) a[++t]=x[i];
		if(v[i]==-1){
			ll pos=x[i];
			int l=1,r=t,mid,ans=0;
			while(l<=r){
				mid=l+r>>1;
				if( abs(a[mid]+pos+L) < W * (pos-a[mid]+L) ) l=mid+1, ans=mid;
				else r=mid-1;
			}
			Ans+=ans;
		}
	}
	printf("%I64d",Ans);
	return 0;
}