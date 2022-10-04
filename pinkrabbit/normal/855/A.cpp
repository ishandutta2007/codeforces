#include<cstdio>
int n;
char str[105][105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str[i]);
		int ok=0;
		for(int j=1;j<i;++j){
			int o=1,k;
			for(k=0;str[i][k]!='\0'&&str[j][k]!='\0';++k){
				if(str[j][k]!=str[i][k]) {o=0; break;}
			}
			if((str[i][k]=='\0'&&str[j][k]!='\0')||(str[j][k]=='\0'&&str[i][k]!='\0')) o=0;
			if(o==1) {ok=1; break;}
		}
		if(ok==1) puts("Yes");
		else puts("No");
	}
	return 0;
}