#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int cnt[N], n, kol[N], prost[N];

void obradi(){
	for(int i = 2;i < N;i++) prost[i] = 1;
	for(int i = 2;i < N;i++){
		kol[i] = cnt[i];
		for(int j = 2 * i;j < N;j += i){
			kol[i] += cnt[j];	
			prost[j] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int x; scanf("%d", &x); cnt[x]++;
	}
	obradi();
	ll sol = 1;
	for(int i = 1;i < N;i++){
		if(!prost[i]) continue;
		ll st = i;
		while(kol[st] >= n - 1){
			st *= i;
			if(st >= N) break;
		}
		sol *= (ll)(st / i);
	}
	printf("%lld\n", sol);
	return 0;
}