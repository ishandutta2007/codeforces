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
int cnt[2];
int a[1000005],b[1000005];
int p[1000005][2];
bool f[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	char c;
	queue<int> d[2];
	FOR(i,1,n){
		cin>>c;
		a[i]=c-'0';cnt[a[i]]++;
	}
	FOR(i,1,n){
		cin>>c;
		b[i]=c-'0';cnt[b[i]]--;
		if(a[i]!=b[i])d[a[i]].emplace(i);
	}
	if(cnt[0]){
		cout<<-1;RE 0;
	}
	int ans=0;
	FOR(i,1,n){
		p[i][0]+=p[i-1][0];
		p[i][1]+=p[i-1][1];
		if(f[i]||a[i]==b[i])continue;
		if(a[i]){
			int r=d[0].front();
			p[r+1][1]++;
			f[r]=1;
			if(p[i][1])p[i][1]--;else ans++;
		}else{
			int r=d[1].front();
			p[r+1][0]++;
			f[r]=1;
			if(p[i][0])p[i][0]--;else ans++;
		}
		rep(j,0,2)d[j].pop();
	}
	cout<<ans;
	RE 0;
}