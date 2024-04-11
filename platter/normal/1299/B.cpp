#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<long long,long long> P;

int main(void) {
	int n;
	scanf("%d\n",&n);
	if (n%2==1) {
		printf("NO");
		return 0;
	}
	P point[100000];
	for(int i=0;i<n;i++) {
		long long x,y;
		scanf("%lld %lld\n",&x,&y);
		point[i]=P(x,y);
	}
	P st=P(point[0].first+point[n/2].first,point[0].second+point[n/2].second);
	for(int i=0;i<n/2;i++) {
		P now=P(point[i].first+point[i+n/2].first,point[i].second+point[i+n/2].second);
		if (st!=now) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}