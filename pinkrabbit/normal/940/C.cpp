#include<cstdio>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
int n,k,tot;
int px[150];
bool used[150];
char str[100010],use[30];
char ans[100010];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",str);
	F2(i,0,n) used[str[i]]=1;
	F(i,1,140) if(used[i]) use[++tot]=i;
	F(i,1,tot) px[use[i]]=i; 
	if(k>n){
		printf("%s",str);
		F(i,n+1,k) printf("%c",use[1]);
		return 0;
	}
	F2(i,0,k) ans[i]=str[i]; ans[k]='\0';
	int x=k-1;
	while(px[ans[x]]==tot){
		ans[x]=use[1];
		--x;
	}
	ans[x]=use[px[ans[x]]+1];
	printf("%s",ans);
	return 0;
}