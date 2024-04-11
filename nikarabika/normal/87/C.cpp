//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
int gn[maxn],
	lu[maxn],
	par[maxn],
	xsu[maxn * 2],
	cnt[maxn * 2],
	n;

int get(int v2, int len){
	LL v1 = v2 - len;
	return (v2 - v1) * (v2 + v1 + 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++){
		cnt[0] = 1000000;
		for(int k = 2; k * (k + 1) / 2 <= i; k++){
			int lo = (i + (k * (k - 1) / 2)) / k;
			if(get(lo, k) == i)
				lu[xsu[lo] ^ xsu[lo - k]] = i, smin(cnt[xsu[lo] ^ xsu[lo - k]], k);
		}
		for(int j = 0; 1; j++){
			//val++;
			if(lu[j] < i){
				gn[i] = j;
				xsu[i] = xsu[i - 1] ^ gn[i];
				break;
			}
		}
	}
	if(!gn[n]) cout << -1 << endl;
	else cout << cnt[0] << endl;
	return 0;
}