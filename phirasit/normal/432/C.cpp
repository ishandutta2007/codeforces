#include <stdio.h>
#include <vector>

#define N 100010

using namespace std;

vector< pair<int,int> > V;
vector<int> P,ls[N];
int p[N],arr[N],pos[N],n;

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&arr[i]);
		pos[arr[i]] = i;
	}
	for(int i = 2;i <= n;i++) {
		if(p[i] == 0) {
			P.push_back(i);
			for(int j = i;j <= n;j += i) {
				p[j] = 1;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int k = pos[i];arr[k] != k;) {
			int dis = (arr[k] > k?arr[k] - k:k - arr[k]) + 1;
			int a = 0,b = P.size()-1;
			while(a < b) {
				int m = (a+b)/2 + 1;
				if(P[m] <= dis) {
					a = m;
				}else {
					b = m-1;
				}
			}
			int next = (k > arr[k]?-(P[a] - 1):(P[a] - 1));
			V.push_back(make_pair(k,k + next));
			swap(pos[arr[k]],pos[arr[k + next]]);
			swap(arr[k],arr[k + next]);
			k += next;
		}
	}
	printf("%d\n",V.size());
	for(int i = 0;i < V.size();i++) {
		if(V[i].first > V[i].second) {
			swap(V[i].first,V[i].second);
		}
		printf("%d %d\n",V[i].first,V[i].second);
	}
	return 0;
}