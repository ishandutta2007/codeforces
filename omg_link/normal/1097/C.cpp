#include <stdio.h>
#include <string.h>
#define MN 100000
#define ML 500000
int n,cnt[ML+5],ans=0;
char s[ML+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&s[1]);
		bool flag=false;
		int c=0,len=strlen(&s[1]),v=0;
		for(int j=1;j<=len;j++){
			if(s[j]=='('){
				c++;
			}else{
				c--;
				if(c<0){
					flag=true;
					v++;
					c=0;
				}
			}
		}
		if(flag&&c>0) continue;
		if(flag){
			if(cnt[v]>0) cnt[v]--,ans++;
			else cnt[v]--;
		}else{
			if(c==0){
				if(cnt[0]) ans++;
				cnt[0]^=1;
			}else{
				if(cnt[c]<0) cnt[c]++,ans++;
				else cnt[c]++;
			}
		}
	}
	printf("%d\n",ans);
}