#include <bits/stdc++.h>
using namespace std;

vector<int> v[6001];

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int n;
		scanf("%d\n",&n);
		for(int i=0;i<n;i++) {
			int x;
			scanf("%d ",&x);
			v[x].push_back(i);
		}
		scanf("\n");
		bool flag=false;
		for(int i=1;i<=n;i++) {
			if (v[i].size()>2) {
				flag=true;
				break;
			}
			for(int j=0;j+1<v[i].size();j++) {
				if (v[i][j+1]-v[i][j]>1) {
					flag=true;
					break;
				}
			}
		}
		printf("%s\n",flag?"YES":"NO");
		for(int i=1;i<=n;i++) {
			v[i].clear();
		}
	}
}