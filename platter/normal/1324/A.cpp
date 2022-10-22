#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		int n;
		scanf("%d\n",&n);
		int f;
		bool flag=true;
		for(int i=0;i<n;i++) {
			int x;
			scanf("%d ",&x);
			if (i==0) {
				f=x%2;
			}
			else if (x%2!=f) {
				flag=false;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
}