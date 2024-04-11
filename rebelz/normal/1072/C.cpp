#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a,b,cnt,cnt1,cnt2;
ll vis[1000005],num1[1000005],num2[1000005];

bool check(ll x){
	memset(vis,0,sizeof(vis));
	cnt=0;
	int now=x,ta=a,tb=b;
	while(a>0){
		if(now==0)
			break;
		for(;now>=1;now--)
			if(!vis[now]&&a>=now)
				vis[now]=1,a-=now,cnt++;
	}
	now=x;
	while(b>0){
		if(now==0)
			break;
		for(;now>=1;now--)
			if(!vis[now]&&b>=now)
				vis[now]=2,b-=now,cnt++;
	}
	a=ta,b=tb;
	if(cnt==x)
		return true;
	else
		return false;
}

int main(){
	cin>>a>>b;
	ll l=1,r=100000,ans;
	while(l<=r){
		ll mid=(l+r)/2;
//		cout<<mid<<' ';
//		cout<<check(mid)<<endl;
		if(check(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	memset(vis,0,sizeof(vis));
	int now=ans;
	cnt=0;
	while(a>0){
		if(now==0)
			break;
		for(;now>=1;now--)
			if(!vis[now]&&a>=now)
				vis[now]=1,num1[++cnt1]=now,a-=now;
	}
	now=ans;
	while(b>0){
		if(now==0)
			break;
		for(;now>=1;now--)
			if(!vis[now]&&b>=now)
				vis[now]=2,num2[++cnt2]=now,b-=now;
	}
	cout<<cnt1<<endl;
	for(int i=1;i<=cnt1;i++)
		cout<<num1[i]<<' ';
	cout<<endl<<cnt2<<endl;
	for(int i=1;i<=cnt2;i++)
		cout<<num2[i]<<' ';
	cout<<endl;
	return 0;
}