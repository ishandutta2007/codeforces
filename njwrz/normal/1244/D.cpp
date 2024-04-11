#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100005],co[5][100005],zh[4];
int zh1[6][3]={
1,2,3,
1,3,2,
2,1,3,
2,3,1,
3,1,2,
3,2,1
};
vector<ll> v[100005];
void dfs(ll q,ll la1,ll la2,ll pa){
	if(pa!=0&&v[q].size()==1){
		for(ll i=1;i<=3;i++){
			if(i!=la1&&i!=la2){
				a[q]=i;
				return ;
			}
		}
	}
	ll re=-1;
	for(ll i=1;i<=3;i++){
		if(i!=la1&&i!=la2){
			a[q]=i;
			for(int j=0;j<v[q].size();j++){
				if(v[q][j]!=pa){
					dfs(v[q][j],la2,i,q);
				}
			}
			break;
		}
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<=3;i++){
		for(ll j=1;j<=n;j++)cin>>co[i][j];
	}
	ll x,y;
	for(ll i=1;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bool f=1;
	for(ll i=1;i<=n;i++)if(v[i].size()>2)f=0;
	if(!f){
		cout<<-1;return 0;
	}
	ll qd=-1;
	for(ll i=1;i<=n;i++){
		if(v[i].size()==1){
			if(qd==-1){
				qd=i;
			}
		}
	}
	dfs(qd,0,0,0);
	ll ans1=-1,ans2=-1;
	for(int i=0;i<6;i++){
		ll t=0;
		for(int j=1;j<=n;j++){
			t+=co[zh1[i][a[j]-1]][j];
		}
		if(ans1==-1||ans1>t){
			ans1=t;
			ans2=i;
		}
	}
	cout<<ans1<<'\n';
	for(int i=1;i<=n;i++){
		cout<<zh1[ans2][a[i]-1]<<' ';
	}
	return 0;
}