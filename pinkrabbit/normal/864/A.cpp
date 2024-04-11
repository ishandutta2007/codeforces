#include<cstdio>
int num[1000],n;
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;++i) scanf("%d",&x), num[x]++;
	int ns=0,a1=0,a2=0;
	for(int i=1;i<=100;++i){
		if(num[i]){
			++ns;
			if(!a1) a1=i;
			else a2=i;
		}
		if(ns>2){puts("NO");return 0;}
	}
	if(ns==2){
		if(num[a1]==num[a2]) printf("YES\n%d %d",a1,a2);
		else puts("NO");
	}
	else puts("NO");
	return 0;
}