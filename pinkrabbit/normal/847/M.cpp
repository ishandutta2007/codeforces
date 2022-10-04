#include<cstdio>

int n,a[106];

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	
	int d=a[2]-a[1], o=1;
	
	for(int i=2;i<n;++i) {
		if(a[i+1]-a[i]!=d) {
			o=0;
			break;
		}
	}
	
	if(o==0) printf("%d",a[n]);
	else printf("%d",a[n]+d);
	
	return 0;
	
}