#include<bits/stdc++.h>
using namespace std;
int T,n,m,s[200009],flag,flags;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),flag=flags=1;
		for(int i = 1; i <= n; i++) {
			scanf("%d",&s[i]);
			if(s[i]!=i&&flag==0&&s[i-1]==i-1) flags=0;
			if(s[i]!=i) flag = 0;
		}
		if(flag == 1) {
			printf("0\n");
			continue;
		} 
		if(n == 2 || flags == 1) {
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
	return 0;
}