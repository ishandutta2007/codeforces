#include<bits/stdc++.h>
using namespace std;
int T,x,y,z;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&x,&y,&z);
		if(x == y && z <= x) printf("YES\n%d %d %d\n",z,x,z);
		else if(y == z && x <= y) printf("YES\n%d %d %d\n",x,x,z);
		else if(z == x && y <= z) printf("YES\n%d %d %d\n",x,y,y);
		else printf("NO\n");
	}
	return 0;
}