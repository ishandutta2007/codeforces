#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n,m,p;
	scanf("%d %d %d\n",&n,&m,&p);
	int af;
	bool flag=false;
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d ",&x);
		if (x%p!=0) {
			if (!flag) {
				af=i;
				flag=true;
			}
		}
	}
	scanf("\n");
	int bf;
	flag=false;
	for(int i=0;i<m;i++) {
		int x;
		scanf("%d ",&x);
		if (x%p!=0) {
			if (!flag) {
				bf=i;
				flag=true;
			}
		}
	}
	printf("%d",af+bf);
}