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
int n;
int a[100005];
bool f[300];
string ex="-+*";
int ans[100005];
void print(){
	cout<<a[1];
	FOR(i,2,n)cout<<ex[ans[i]]<<a[i];
	exit(0);
}
int dp[24],it[24],cnt,lst[24];
void solve(int l,int r){
	if(l>=r)RE;
	int sum=0;
	FOR(i,l,r)sum+=a[i];
	int t=1;
	bool ff=0;
	FOR(i,l,r){
		t=t*a[i];
		if(t>=(r-l+1)*10){
			ff=1;break;
		}
	} 
	if(ff){
		while(a[l]==1){
			ans[l+1]=1;
			l++;
		}
		while(a[r]==1){
			ans[r]=1;
			r--;
		}
		FOR(i,l+1,r)ans[i]=2;
		RE;
	}
	cnt=0;
	FOR(i,l,r){
		if(a[i]>1){
			it[++cnt]=i;
		}
	}
	FILL(dp,0);FILL(lst,0);
	it[0]=it[1]-1;
	FOR(i,1,cnt){
		int now=1;
		for(int j=i;j>=1;j--){
			now=now*a[it[j]];
			if(now+dp[j-1]+it[j]-it[j-1]-1>dp[i]){
				dp[i]=now+dp[j-1]+it[j]-it[j-1]-1;
				lst[i]=j;
			}
		}
	}
	int now=cnt;
	FOR(i,l+1,r)ans[i]=1;
	while(now>0){
		FOR(i,it[lst[now]]+1,it[now])ans[i]=2;
		now=lst[now]-1;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	string s;
	cin>>s;
	for(auto u:s)f[u]=1;
	if(!f['*']){
		if(f['+']){
			FOR(i,2,n)ans[i]=1;
		}else FOR(i,2,n)ans[i]=0;
		print();
	}else if(!f['+']&&!f['-']){
		FOR(i,2,n)ans[i]=2;
		print();
	}else if(!f['+']){
		int it=0;
		FOR(i,1,n)if(a[i]==0){
			it=i;break;
		}
		FOR(i,2,n)ans[i]=2;
		if(it){
			ans[it]=0;
		}
		print();
	}
	int l=1;
	FOR(i,1,n){
		if(!a[i]){
			ans[i]=ans[i+1]=1;
			solve(l,i-1);
			l=i+1;
		}
	}
	solve(l,n);
	print();
	RE 0;
}