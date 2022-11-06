#include <cstdio>
const int Maxn=100000;
char s[Maxn+5];
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		int x;
		scanf("%d",&x);
		for(int i=1;i<=n;i++){
			a[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				if(i>x){
					a[i-x]=0;
				}
				if(i+x<=n){
					a[i+x]=0;
				}
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				bool tmp=0;
				if(i>x){
					if(a[i-x]==1){
						tmp=1;
					}
				}
				if(i+x<=n){
					if(a[i+x]==1){
						tmp=1;
					}
				}
				if(!tmp){
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			puts("-1");
		}
		else{
			for(int i=1;i<=n;i++){
				printf("%d",a[i]);
			}
			puts("");
		}
	}
	return 0;
}