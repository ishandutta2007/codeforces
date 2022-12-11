#include <stdio.h>
#include <algorithm>
#include <map>
#define MX_N 100010

using namespace std;

map<int,int> mp;
int arr[MX_N];
int opt[MX_N];
int n,m;

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
	}
	for(i=n;i>0;i--) {
		if(i >= n) {
			opt[i] = 0;
		}else {
			opt[i] = opt[i+1];
		}
		if(mp[arr[i]] == 0) {
			mp[arr[i]] = 1;
			opt[i]++;
		}
	}
	while(m--) {
		int a;
		scanf("%d",&a);
		printf("%d\n",opt[a]);
	}
	return 0;
}