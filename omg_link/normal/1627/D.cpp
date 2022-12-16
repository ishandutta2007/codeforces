#include <stdio.h>
#define MN 1000000

bool ex[MN+5];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		ex[a] = true;
	}
	int ans = 0;
	for(int i=1;i<=MN;i++){
		if(ex[i]) continue;
		int g = -1;
		for(int j=i;j<=MN;j+=i){
			if(ex[j]){
				if(g==-1) g = j;
				else g = gcd(g,j);
			}
		}
		if(g==i) ans++;
	}
	printf("%d\n",ans);
}