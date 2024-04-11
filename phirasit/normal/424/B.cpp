#include <stdio.h>
#include <math.h>
#include <algorithm>

#define A first
#define B second

#define N 1010

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> p3;

p3 arr[N];
int n,m;

int cmp(p3 a,p3 b) {
	return a.A.A * a.A.A + a.A.B * a.A.B < b.A.A * b.A.A + b.A.B * b.A.B;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d%d%d",&arr[i].A.A,&arr[i].A.B,&arr[i].B);
	}
	sort(arr,arr+n,cmp);
	int ans = -2;
	for(int i=0;i<=n;i++) {
		if(m >= 1000000) {
			ans = i-1;
			break;
		}
		if(i < n) {
			m += arr[i].B;
		}
	}
	if(ans == -2) {
		printf("-1\n");
	}else if(ans == -1) {
		printf("0.0000\n");
	}else {
		printf("%.8lf\n",sqrt(arr[ans].A.A*arr[ans].A.A + arr[ans].A.B*arr[ans].A.B));
	}
	return 0;
}