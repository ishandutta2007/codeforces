#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 500;

int A[N], n, cnt[N], dob[N];

int main(){
	scanf("%d", &n);
	int ans = 1;
	for(int i = 0;i < n;i++){
		char c; scanf(" %c", &c);
		A[i] = c - '0';
		if(A[i]) ans = 0;
	}
	for(int i = 1;i < n;i++){
		if(n % i != 0){
			ans += dob[__gcd(i, n)];
			continue;
		}
		for(int j = 0;j < n;j++)
			cnt[j % i] += A[j];
		dob[i] = 1;
		for(int j = 0;j < i;j++){
			if(cnt[j] % 2 == 1) dob[i] = 0;
			cnt[j] = 0;
		}
		ans += dob[i];
	}
	printf("%d\n", ans);
}