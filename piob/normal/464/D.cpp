#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const K eps = 1e-9;

int n, k;
K res;
K cnt[610];

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,2,600) cnt[i] = 0;
	cnt[1] = k;
	FWD(i,0,n){
		FWD(i,1,600)
			res += cnt[i]/k * ((K)(1+i)/2 * i/(i+1) + (K)i * 1/(i+1));
		BCK(i,600,0){
			K adv = cnt[i]/k * 1/(i+1);
			cnt[i+1] += adv;
			cnt[i] -= adv;
		}
	}
	cout.precision(10);
	cout << fixed << res << endl;
	return 0;
}