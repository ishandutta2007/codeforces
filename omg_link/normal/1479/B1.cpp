#include <stdio.h>
#define MN 100000

int n,a[MN+5],l0=-1,l1=-1,ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(l0!=a[i]){
			if(l1!=a[i]){
				if(a[i+1]==l0){
					l0 = a[i];
				}else{
					l1 = a[i];
				}
			}else{
				l0 = a[i];
			}
			ans++;
		}else if(l1!=a[i]){
			l1 = a[i];
			ans++;
		}
	}
	printf("%d\n",ans);
}