#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
char s[Maxn+5];
int n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		int ans=n;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				int cnt=0;
				int len=1;
				for(int k=1;k<=n;k++){
					if(len&1){
						if(s[k]-'0'==i){
							len++;
						}
						else{
							cnt++;
						}
					}
					else{
						if(s[k]-'0'==j){
							len++;
						}
						else{
							cnt++;
						}
					}
				}
				if((!(len&1))&&(i!=j)){
					cnt++;
				}
				ans=min(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}