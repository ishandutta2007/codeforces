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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define st st1
#define CHECK (double(clock() - st) / CLOCKS_PER_SEC < 3.89)

const int maxn = 1e6;
LL a[maxn];
LL vec1[maxn], vec2[maxn], vec3[maxn];
int vecsz1, vecsz2, vecsz3;
int n, cnt[maxn * 2];
clock_t st;

/*inline bool check(void){
	return double(clock() - st) / CLOCKS_PER_SEC < 3.9;
}*/

int main(){
	st = clock();
	scanf("%d", &n);
	LL d = 0;
	for(int i = 0; i < n; i++){
		scanf("%I64d", a + i);
		d = __gcd(d, a[i]);
	}
	for(int i = 0; i < n; i++)
		a[i] /= d;
	srand(time(0));
	random_shuffle(a, a + n);
	LL ret = 1;
	for(int id = 0; id < n and CHECK; id++){
		vecsz1 = 0;
		vecsz2 = 0;
		vecsz3 = 0;
		memset(cnt, 0, sizeof cnt);
		for(LL i = 1; i * i <= a[id]; i++)
			if(a[id] % i == 0){
				vec1[vecsz1++] = i;
				if(i * i != a[id]) vec2[vecsz2++] = a[id] / i;
			}
		reverse(vec2, vec2 + vecsz2);
		merge(vec1, vec1 + vecsz1, vec2, vec2 + vecsz2, vec3);
		vecsz3 = vecsz1 + vecsz2;
		for(int i = 0; i < n; i++){
			LL gcd = __gcd(a[id], a[i]);
			int idx = lower_bound(vec3, vec3 + vecsz3, gcd) - vec3;
			cnt[idx]++;
		}
		for(int i = 0; i < vecsz3 and CHECK; i++){
			int cnt2 = 0;
			for(int j = 0; j < vecsz3; j++)
				if(vec3[j] % vec3[i] == 0)
					cnt2 += cnt[j];
			if(cnt2 >= (n + 1) / 2)
				smax(ret, vec3[i]);
		}
	}
	printf("%I64d\n", ret * d);
	return 0;
}