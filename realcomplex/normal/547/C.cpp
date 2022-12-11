#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define popcount(a) __builtin_popcount((a))

const int N = (int)2e5 + 9;
const int M = (int)5e5 + 9;

vector<int> masks[N];

int cnt[M];
bool use[N];


ll calc(int v){
	ll ret = 0;
	int k;
	for(int j = 0; j < masks[v].size(); j ++ ){
		k = popcount(j) % 2;
		if(k == 0)
			k = +1;
		else
			k = -1;
		ret += k * cnt[masks[v][j]];
	}
	return ret;
}

int main(){
	fastIO;
	int n, q;
	cin >> n >> q;
	int a;
	int m;
	int rz;
	for(int i = 1; i <= n; i ++ ){
		cin >> a;
		vector<int> p;
		for(int t = 2; t * t <= a; t ++ ){
			if(a % t == 0){
				p.push_back(t);
				while(a % t == 0)
					a /= t;
			}
		}
		if(a != 1)
			p.push_back(a);
		m = p.size();
		for(int j = 0 ; j < (1 << m); j ++){
			rz = 1;
			for(int t = 0; t < m; t ++ ){
				if(j & (1 << t)){
					rz *= p[t];
				}
			}
			masks[i].push_back(rz);
		}
	}
	int x;
	ll ret = 0;
	for(int i = 0; i < q; i ++ ){
		cin >> x;
		if(!use[x]){
			ret += calc(x);
			for(auto y : masks[x])
				cnt[y] ++ ;
			use[x] = true;
		}
		else{
			for(auto y : masks[x])
				cnt[y] -- ;
			ret -= calc(x);
			use[x] = false;
		}
		cout << ret << "\n";
	}
	return 0;
}