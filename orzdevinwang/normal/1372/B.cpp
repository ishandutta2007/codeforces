#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	scanf("%d",&m);
	while(m--) {
		scanf("%d",&n);
		int cnt = n;
		for(int i = 2; i <= sqrt(n); i++)
			if(n % i == 0) {
				cnt = i;
				break;
			}
		printf("%d %d\n",n/cnt,n/cnt*(cnt-1));
	}
	return 0;
}