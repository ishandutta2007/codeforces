#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

struct P{
	ll depth;
	ll ix;
};

const int BIT = 62;
ll pak[BIT];
ll shift[BIT];

P fin(ll x){
	P ans;
	for(int j = 0;j<BIT-1;j++){
		if( x >= pak[j] and x < pak[j+1]){
			ans.depth = j;
			x -= pak[j];
			x += shift[j];
			x = (x + pak[j]) % pak[j];
			ans.ix = x;
		}
	}
	return ans;
}

ll finP(P x){
	x.ix -= shift[x.depth];
	x.ix = (x.ix + pak[x.depth]) % pak[x.depth];
	x.ix += pak[x.depth];
	return x.ix;
}

void Query(){
	int t;
	scanf("%d",&t);
	if(t == 1){
		ll x,k;
		scanf("%lld %lld",&x,&k);
		for(int i = 0;i<BIT-1;i++){
			if(x>=pak[i] and x < pak[i+1]){
				shift[i] += k;
				shift[i] %= pak[i];
				break;
			}
		}
	}
	else if(t == 2){
		ll x,k;
		scanf("%lld %lld",&x,&k);
		for(int i = 0;i<BIT-1;i++){
			if(x >= pak[i] and x < pak[i+1]){
				for(int j = i;j<BIT;j++){
					k %= pak[j];
					shift[j] += k;
					shift[j] %= pak[j];
					k *= 2;
				}
				break;
			}
		}
	}
	else{
		ll x;
		scanf("%lld",&x);
		P cur = fin(x);
		printf("%lld ",finP(cur));
		while(cur.depth > 0){
			cur.depth--;
			cur.ix /= 2;
			printf("%lld ",finP(cur));
		}
		printf("\n");
	}
}

int main(){
	pak[0] = 1;
	for(int i = 1;i<BIT;i++)
		pak[i] = pak[i-1] * 2LL;
	int q;
	scanf("%d",&q);
	while(q--){
		Query();
	}
	return 0;
}