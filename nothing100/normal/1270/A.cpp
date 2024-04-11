#include<bits/stdc++.h>
using namespace std;
int t,n,k1,k2;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&n,&k1,&k2);
		int f=0,o;
		for (int i=0;i<k1;i++) scanf("%d",&o);
		for (int i=0;i<k2;i++){
			scanf("%d",&o);
			if (o==n) f=1;
		}
		if (!f) printf("YES\n");
		else printf("NO\n");
	}
}