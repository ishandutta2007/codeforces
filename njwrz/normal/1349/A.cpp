#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,a[100005]; 
V<int> v[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		int t=a[i],cnt;
		for(int j=2;j*j<=a[i];j++){
			if(t%j==0){
				cnt=0;
				while(t%j==0){
					t/=j;cnt++;
				}
				v[j].PB(cnt);
			}
		}
		if(t!=1){
			v[t].PB(1);
		}
	}
	int ans=1;
	FOR(i,2,200000){
		if(v[i].empty())continue;
		int min1=1000000000,min2=1000000000,len=min(2ll,(int)(n-v[i].size()));
		FOR(j,1,len)v[i].PB(0);
		for(auto u:v[i]){
			if(u<min1){
				min2=min1;min1=u;
			}else if(u<min2){
				min2=u;
			}
		}
		FOR(j,1,min2){
			ans=ans*i;
		}
	}
	cout<<ans;
	RE 0;
}