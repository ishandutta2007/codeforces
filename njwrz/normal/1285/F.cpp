#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
const int maxi=1e5;
int mu[100005],pri[100005];
int prime[100005],tl;
void pre(){
	pri[1]=1;mu[1]=1;
	FOR(i,2,maxi){
		if(!pri[i]){
			prime[++tl]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=tl&&i*prime[j]<=maxi;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;break;
			}else{
				mu[i*prime[j]]=-mu[i];
			}
		}
	}
}
int n;
int val[100005],len;
V<int> d[100005];
int cnt[100005],t[100005];
int get(int x){
	int re=0;
	for(auto u:d[x])re+=cnt[u]*mu[u];
	RE re;
}
int get(){
	if(len<2)RE 0;
	sort(val+1,val+len+1);
	FOR(i,1,len){
		for(auto u:d[val[i]])cnt[u]++;
	}
	int it=1,re=0;
	for(int i=len;i>=1;i--){
		while(it<=len&&get(val[i])>0){
			for(auto u:d[val[it]])cnt[u]--;
			it++;
		}
		if(it>1&&__gcd(val[it-1],val[i])==1)gmax(re,val[i]*val[it-1]);
	}
	while(it<=len){
		for(auto u:d[val[it]])cnt[u]--;
		it++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,1,100000)for(int j=i;j<=100000;j+=i)d[j].PB(i);
	pre();
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		t[x]++;
	}
	int maxi=0;
	FOR(i,1,100000){
		len=0;
		for(int j=i;j<=100000;j+=i)FOR(k,1,t[j])val[++len]=j/i;
		gmax(maxi,i*get());
	}
	cout<<maxi;
	RE 0;
}