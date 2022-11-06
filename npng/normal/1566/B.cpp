#include <cstdio>
const int Maxn=100000;
char s[Maxn+5];
int n;
void solve(){
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	if(flag){
		puts("0");
		return;
	}
	int num=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(s[i]=='1'){
			continue;
		}
		while(j<=n&&s[j]=='0'){
			j++;
		}
		j--;
		num++;
	}
	if(num==1){
		puts("1");
		return;
	}
	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}