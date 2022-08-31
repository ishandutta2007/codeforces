#include<bits/stdc++.h>
using namespace std;
int T, a, b, c, d, cnta;
int main() {
	scanf("%d", &T);
	while(T--) {
		cnta = 0;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a % 2) cnta++;
		if(b % 2) cnta++;
		if(c % 2) cnta++;
		if(d % 2) cnta++;
		if(a == 0 || b == 0 || c == 0) {
			if(cnta <= 1) printf("Yes\n");
			else printf("No\n");
		}
		else {
			if(cnta <= 1) printf("Yes\n");
			else {
				a--, b--, c--, d++;
				cnta = 0;
				if(a % 2) cnta++;
				if(b % 2) cnta++;
				if(c % 2) cnta++;
				if(d % 2) cnta++;
				if(cnta <= 1) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}