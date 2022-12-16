#include <stdio.h>
#define MN 100

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	long long lft = 0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,lst=0;i<=n;i++,lst++){
		if(a[i]>lst){
			lft += a[i]-lst;
			a[i] = lst;
		}else{
			int t = lst-a[i];
			if(t>lft){
				puts("NO");
				return;
			}else{
				lft -= t;
			}
		}
	}
	puts("YES");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}