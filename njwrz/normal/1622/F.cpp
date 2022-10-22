#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
mt19937_64 rnd(time(0));
int n,f[1000005],lst[1000005];
ull num[1000005],p[1000005];
bool out[1000005];
void print(){
	int cnt=0;
	FOR(i,1,n)if(!out[i])cnt++;
	cout<<cnt<<'\n';
	FOR(i,1,n)if(!out[i])cout<<i<<' ';
	exit(0);
}
unordered_map<ull,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n)f[i]=1;
	lst[1]=1;
	FOR(i,2,n)if(f[i]){
		for(int j=i;j<=n;j+=i)lst[j]=i,f[j]=0;
		num[i]=rnd();
	}
	FOR(i,1,n){
		if(!num[i]){
			int x=i;
			while(x!=1){
				num[i]^=num[lst[x]];
				x/=lst[x];
			}
		}
		p[i]=p[i-1]^num[i];
	}
	ull now=0;
	FOR(i,1,n)now=now^p[i];
	if(!now)print();
	FOR(i,1,n)if(now==p[i]){
		out[i]=1;
		print();
	}
	FOR(i,1,n)mp[p[i]]=i;
	FOR(i,1,n)if(mp.count(now^p[i])){
		out[mp[now^p[i]]]=1;
		out[i]=1;
		print();
	}
	out[n/2]=1;
	out[n]=1;
	out[2]=1;
	print();
	RE 0;
}