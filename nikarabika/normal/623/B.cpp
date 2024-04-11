//sobskdrbhvk
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

const int maxn = 1000 * 1000 + 85 - 69;
const LL Inf = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int intInf = 1000 * 1000 * 10;
LL ans = Inf;
LL arr[maxn], dp[maxn], pd[maxn];
LL a, b, n;
vector<LL> prm;
int vec1[maxn], vec2[maxn], vecsz1, vecsz2;

void fuck(LL val){
	for(LL i = 2; i * i <= val; i++)
		if(val % i == 0){
			prm.PB(i);
			while(val % i == 0)
				val /= i;
		}
	if(val != 1)
		prm.PB(val);
	return;
}

int main(){
	{
		int nn, aa, bb;
		scanf("%d%d%d", &nn, &aa, &bb);
		n = nn, a = aa, b = bb;
	}
	for(int i = 0; i < n; i++)
		scanf("%d", arr + i);
	fuck(arr[0]);
	fuck(arr[0] - 1);
	fuck(arr[0] + 1);
	fuck(arr[n - 1]);
	fuck(arr[n - 1] - 1);
	fuck(arr[n - 1] + 1);
	sort(all(prm));
	prm.resize(unique(all(prm)) - prm.begin());
	for(auto val : prm){
		vecsz1 = vecsz2 = 0;
		int l = intInf, r = -1;
		int left1 = 0, right1 = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] % val == 0)
				continue;
			if(arr[i] % val == 1 or arr[i] % val == val - 1){
				if(r == -1)
					vec1[vecsz1++] = i;
				else
					vec2[vecsz2++] = i;
			}
			else
				smin(l, i), smax(r, i), vecsz2 = 0;
		}
		if(!vecsz1 and r == -1){
			printf("%d\n", 0);
			return 0;
		}
		if(r != -1){
			LL costl = vecsz1 * b, costr = vecsz2 * b;
			for(int i = 0; i < vecsz1; i++)
				smin(costl, i * b + (l - vec1[i]) * a);
			for(int i = vecsz2 - 1; i >= 0; i--)
				smin(costr, (vecsz2 - i - 1) * b + (vec2[i] - r) * a);
			smin(ans, (r - l + 1) * a + costl + costr);
		}
		else{
			dp[0] = b;
			pd[0] = a;
			for(int i = 1; i < vecsz1; i++){
				dp[i] = dp[i - 1] + b;
				pd[i] = min(pd[i - 1] + (vec1[i] - vec1[i - 1]) * a, dp[i - 1] + a);
				smin(ans, pd[i] + (vecsz1 - i - 1) * b);
			}
			smin(ans, b * vecsz1);
			smin(ans, a + b * (vecsz1 - 1));
		}
	}
	printf("%I64d\n", ans);
	return 0;
}