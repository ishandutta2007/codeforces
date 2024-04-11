/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int cnt[6],num[100005],p[1<<6];
bool check(){
	rep(i,0,1<<6){
		int t=i,sum=0;
		rep(j,0,6){
			if(i&(1<<j))sum+=cnt[j];
		}
		while(t){
			sum-=p[t];
			t=(t-1)&i;
		}
		if(sum<0)RE 0;
	}
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for(auto u:s){
		cnt[u-'a']++;
	}
	int n;
	n=s.size();
	FOR(i,1,n)num[i]=(1<<6)-1;
	int m;
	cin>>m;
	FOR(i,1,m){
		int it;
		cin>>it>>s;num[it]=0;
		for(auto u:s){
			num[it]^=1<<(u-'a');
		}
	}
	FOR(i,1,n)p[num[i]]++;
	if(!check()){
		cout<<"Impossible";RE 0;
	}
	FOR(i,1,n){
		rep(j,0,6){
			if(num[i]&(1<<j)){
				p[num[i]]--;
				cnt[j]--;
				if(check()){
					cout<<(char)('a'+j);break;
				}
				p[num[i]]++;
				cnt[j]++;
			}
		}
	}
	RE 0;
}