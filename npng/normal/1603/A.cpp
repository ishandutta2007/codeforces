#include <cstdio>
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=2;j<=a[i]+1;j++){
			if(a[i]%j!=0){
				if(j-1>i){
					flag=0;
				}
				break;
			}
		}
	}
	if(flag){
		puts("YES");
	}
	else{
		puts("NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}