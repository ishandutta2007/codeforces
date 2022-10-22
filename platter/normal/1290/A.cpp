#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[3500];
typedef pair<int,int> P;

int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n,m,k;
		scanf("%d %d %d\n",&n,&m,&k);
		for(int i=0;i<n;i++) {
			scanf("%d ",&arr[i]);
		}
		scanf("\n");
		vector<int> v;
		for(int i=0;i<m;i++) {
			v.push_back(max(arr[i],arr[i+n-m]));
		}
		if (k>=m) {
			k=m-1;
		}
		int ret=0;
		for(int i=0;i<=k;i++) {
			int mini=2e9;
			for(int j=i;j<i+m-k;j++) {
				mini=min(v[j],mini);
			}
			ret=max(ret,mini);
		}
		printf("%d\n",ret);
	}
}