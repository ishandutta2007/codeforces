#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn=1<<19;
const int MOD=1e9+7;
const int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
int n, dp[71][maxn], cnt[71], table[71];
bool inq[71][maxn];
queue<pii> q;
void init(){
	for(int i=1; i<=70; i++)
		for(int j=0; j<19; j++){
			int cur=i;
			while(cur%primes[j]==0) table[i]^=1<<j, cur/=primes[j];
		}
}
ll fast_pow(ll k){
	ll product=1, base=2;
	while(k){
		if(k&1){
			product*=base;
			product%=MOD;
		}
		base*=base;
		base%=MOD;
		k>>=1;
	}
	return product;
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	init();
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		cnt[tmp]++;
	}
	dp[0][0]=1;
	q.push(make_pair(0, 0));
	inq[0][0]=true;
	while(!q.empty()){
		pii u=q.front(); q.pop();
		inq[u.first][u.second]=false;
		if(!cnt[u.first+1]){
			dp[u.first+1][u.second]+=dp[u.first][u.second];
			dp[u.first+1][u.second]%=MOD;
			if(u.first+1==70) continue;
			if(!inq[u.first+1][u.second]){
				q.push(make_pair(u.first+1, u.second));
				inq[u.first+1][u.second]=true;
			}
			continue;
		}
		ll mul=fast_pow(cnt[u.first+1]-1);
		dp[u.first+1][u.second]=(ll(dp[u.first+1][u.second])+ll(dp[u.first][u.second])*mul%MOD)%MOD;
		dp[u.first+1][u.second^table[u.first+1]]=(ll(dp[u.first+1][u.second^table[u.first+1]])+ll(dp[u.first][u.second])*mul%MOD)%MOD;
		if(u.first+1==70) continue;
		if(!inq[u.first+1][u.second]){
			q.push(make_pair(u.first+1, u.second));
			inq[u.first+1][u.second]=true;
		}
		if(!inq[u.first+1][u.second^table[u.first+1]]){
			q.push(make_pair(u.first+1, u.second^table[u.first+1]));
			inq[u.first+1][u.second^table[u.first+1]]=true;
		}
	}
	cout<<(dp[70][0]-1+MOD)%MOD<<endl;
	return 0;
}