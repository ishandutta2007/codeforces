#include <cstdio>
#include <algorithm>
const int Maxn=100000;
char s_1[Maxn+5],s_2[Maxn+5];
int n;
int a[Maxn+5];
int f[Maxn+5];
int lst[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",s_1+1);
	scanf("%s",s_2+1);
	for(int i=1;i<=n;i++){
		if(s_1[i]==s_2[i]){
			a[i]=s_1[i]-'0';
		}
		else{
			a[i]=2;
		}
	}
	a[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]||a[i]==2){
			lst[i]=i;
		}
		else{
			lst[i]=lst[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(a[i]==0?1:(a[i]==1?0:2));
		if(lst[i]-1>0){
			f[i]=std::max(f[i],f[lst[i]-2]+2);
		}
	}
	printf("%d\n",f[n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}