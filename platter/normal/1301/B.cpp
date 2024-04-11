#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
long long arr[400005];
 
int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n;
		scanf("%d\n",&n);
		vector<long long> adj;
		for(int i=0;i<n;i++) {
			scanf("%lld ",&arr[i]);
		}
		scanf("\n");
		for(int i=0;i<n;i++) {
			if (arr[i]!=-1) {
				if (i!=0&&arr[i-1]==-1) {
					adj.push_back(arr[i]);
				}
				else if (i!=n-1&&arr[i+1]==-1) {
					adj.push_back(arr[i]);
				}
			}
		}
		if (adj.empty()) {
			printf("0 0\n");
			continue;
		}
		sort(adj.begin(),adj.end());
		long long lo=adj[0];
		long long hi=adj[adj.size()-1];
		long long k=(lo+hi)/2;
		for(int i=0;i<n;i++) {
			if (arr[i]==-1) {
				arr[i]=k;
			}
		}
		long long m=0;
		for(int i=0;i<n-1;i++) {
			long long diff=arr[i]-arr[i+1];
			if (diff<0) {
				diff=-diff;
			}
			m=max(m,diff);
		}
		printf("%lld %lld\n",m,k);
	}
}