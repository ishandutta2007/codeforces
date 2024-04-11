#include <cstdio>
#include <utility>
using namespace std;

const int N = 1000;
pair <int, int> point[N];

long long cross (pair <int, int> x, pair <int, int> y, pair <int, int> z) {
	return (long long) (y.first - x.first) * (z.second - y.second) - (long long) (z.first - y.first) * (y.second - x.second);
}

int main () {
	int n;
	scanf ("%d", &n);
	
	for (int i=0; i<=n; i++) 
		scanf ("%d %d", &point[i].first, &point[i].second);
		
	int ans = 0;
	for (int i=0; i<n-1; i++) {
		ans += cross (point[i], point[i + 1], point[i + 2]) > 0;
	}
	
	ans += cross (point[n-1], point[n], point[0]) > 0;
	
	return 0 * printf ("%d\n", ans);
	
	return 0;
}