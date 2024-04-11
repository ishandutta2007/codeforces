#include <cstdio>
#include <cstring>
const int Maxn=500;
char s[Maxn+5],t[Maxn<<1|5];
char a[Maxn<<1|5];
int n,m;
void solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=m=0;
	while(s[++n]!='\0');
	n--;
	while(t[++m]!='\0');
	m--;
	bool flag=0;
	for(int i=1;i<=n&&!flag;i++){
		for(int j=i;j<=n&&j-i+1<=m;j++){
			if(j-i+j<m){
				continue;
			}
			int len=0;
			for(int k=i;k<=j;k++){
				a[++len]=s[k];
			}
			for(int k=j-1;len<m;k--){
				a[++len]=s[k];
			}
			bool eq=1;
			for(int k=1;k<=m;k++){
				if(a[k]!=t[k]){
					eq=0;
					break;
				}
			}
			if(eq){
				flag=1;
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