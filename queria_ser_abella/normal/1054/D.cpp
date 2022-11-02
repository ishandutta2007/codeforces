#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 400400
#define debug 
#define pb push_back
typedef long long ll;
using namespace std;

int main(){

	int n,k;
	scanf("%d%d",&n,&k);
	
	int x = (1<<k)-1;
	
	map<int,int> mp, foi;
	
	int ac = 0;
	mp[0]++;
	
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		ac = ac xor a;
		mp[ac]++;
	}
	
	ll ans =0 ;
	for(map<int,int> :: iterator it = mp.begin(); it != mp.end(); it++){
		int a = it->first;
		int b = a^x;
		if(foi[a]) continue;
		foi[a] = foi[b] = 1;
		int u = (mp[a]+mp[b])/2;
		int v = mp[a]+mp[b]-u;
		ans += (ll)((ll)u*u-u)/2;
		ans += (ll)((ll)v*v-v)/2;
		debug("%d %d %d %d\n",a,b,u,v);
	}
	ans = ((ll)n*n+n)/2 - ans;
	printf("%lld\n",ans);
}