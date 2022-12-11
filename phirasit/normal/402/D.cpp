#include <stdio.h>
#include <map>

#define N 5010

using namespace std;

map<int, bool> bad;

int arr[N];
int n, m;

int gcd(int a, int b) {
	while(a%b) {
		int r = a%b;
		a = b;
		b = r;
	}
	return b;
}
int beauty(int val) {
	int ans = 0;
	for(int i = 2;i*i <= val;i++) {
		while(val%i == 0) {
			if(bad[i]) {
				ans--;
			}else {
				ans++;
			}
			val /= i;
		}
	}
	if(val != 1) {
		if(bad[val]) {
			ans--;
		}else {
			ans++;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 1;i <= m;i++) {
		int val;
		scanf("%d", &val);
		bad[val] = true;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		ans += beauty(arr[i]);
	}
	for(int i = n;i > 0;i--) {
		int g;
		for(int j = 1;j <= i;j++) {
			if(j == 1) {
				g = arr[j];
			}else {
				g = gcd(g, arr[j]);
			}
		}
		int val = beauty(g);
		if(val < 0) {
			ans -= val * i;
			for(int j = 1;j <= i;j++) {
				arr[j] /= g;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}