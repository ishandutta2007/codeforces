#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 500;

int n, k;
int A[N], P[N];

bool probaj(int x){
	int mi = N;
	for(int i = 0;i < n;i++){
		P[i] = ((A[i] >= x) ? 1 : -1) + (i ? P[i - 1] : 0);
		if(i == k - 1)
			mi = 0;
		if(i >= k)
			mi = min(mi, P[i - k]);
		if(P[i] > mi)
			return true;
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	int ans = 0;
	for(int i = 17;i >= 0;i--)
		if(probaj(ans + (1 << i)))
			ans += (1 << i);
	printf("%d\n", ans);
	return 0;
}