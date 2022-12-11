#include <stdio.h>
#include <queue>

#define N 210
#define K 11

using namespace std;

int arr[N];
int ans = -(-1u/2);
int n,k;

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n ;i++) {
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < n ;i++) {
		for(int j = i;j < n;j++) {
			priority_queue<int> mnH,mxH;
			while(!mnH.empty()) mnH.pop();
			while(!mxH.empty()) mxH.pop();
			for(int x = 0;x < n;x++) {
				if(x < i || x > j) {
					mxH.push(arr[x]);
				}else {
					mnH.push(-arr[x]);
				}
			}
			int t = k;
			while(t-- && !mxH.empty() && !mnH.empty()) {
				int mx = mxH.top();
				int mn = -mnH.top();
				if(mx <= mn) {
					break;
				}else {
					mnH.pop();
					mnH.push(-mx);
					mxH.pop();
					mxH.push(mn);
				}
			}
			int sum = 0;
			while(!mnH.empty()) {
				sum += -mnH.top();
				mnH.pop();
			}
			if(sum > ans) {
				ans = sum;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}