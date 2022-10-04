#include<cstdio>
const int m[60]={28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31};
int n,o;
int a[34];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<60-n;++i){
		int oo=1;
		for(int j=0;j<n;++j)
			if(m[i+j]!=a[j]) {oo=0; break;}
		if(oo) {o=1; break;}
	}
	if(o) printf("YES");
	else puts("NO");
	return 0;
}