#include<cstdio>
int n,ans=0;
char str[9999];
int vis[2222];
int main(){
	scanf("%d",&n);
	scanf("%s",str); str[n]='A'; str[n+1]='\0';
	for(int i=0;i<=n;++i){
		if('a'<=str[i]&&str[i]<='z'){
			vis[str[i]]=1;
		}
		else{
			int sum=0;
			for(int j='a';j<='z';++j)
				if(vis[j]) ++sum;
			if(ans<sum) ans=sum;
			for(int j='a';j<='z';++j)
				vis[j]=0;
		}
	}
	printf("%d",ans);
	return 0;
}