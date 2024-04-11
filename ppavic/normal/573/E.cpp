#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;

const int N = 1e5 + 50;
const int B = 350;
const int INF = 0x3f3f3f3f;

int n, A[N];
ll off_k[N], off_o[N];
deque < ll > D[N];

inline ll get(int i){
	if(i == -1 || (int)D[i / B].size() <= i % B) return -(ll)INF * INF;
	return D[i / B][i % B] + off_k[i / B] * i + off_o[i / B];
}

void dod(ll x, int i){
	off_o[i] -= off_k[i];
	x -= off_o[i];
	x -= off_k[i] * i * B;
	D[i].push_front(x);
}

void rebalans(){
	for(int i = 0;!D[i].empty();i++){
		if((int)D[i].size() > B){
			ll nw = D[i].back() + off_o[i] + off_k[i] * (i + 1) * B;
			D[i].pop_back(); dod(nw, i + 1);
		}
	}
}

inline bool dobar(int i, ll k){
	return get(i) < get(i - 1) + k * i;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", A + i);
	D[0].push_back(0);
	for(int i = 1;i <= n;i++){
		for(int j = (i - 1) / B;j >= 0;j--){
			if(dobar(j * B, A[i])){
				off_k[j] += A[i]; off_o[j] += A[i];
				continue;
			}
			deque < ll > nw;
			for(int k = j * B;k <= (j + 1) * B && k <= i;k++){
				nw.push_back(max((k < (j + 1) * B && k < i ? get(k) : -(ll)INF * INF), get(k - 1) + (ll)A[i] * k));
			}
			off_k[j] = 0; off_o[j] = 0;
			D[j] = nw; rebalans();
			break;
		}
	}
	ll sol = 0;
	for(int i = 1;i <= n;i++)
		if(get(i) > sol)
			sol = get(i);
	printf("%lld\n", sol);
	return 0;
}