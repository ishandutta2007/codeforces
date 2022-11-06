#include<cctype>
#include<cstdio>
const int maxn=100000;
int belong(int x,int y){return x<y?-1:x==y?0:1;}
int xx[maxn+10],yy[maxn+10],ans,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		char c=getchar(); while(!isgraph(c)) c=getchar();
		xx[i]=xx[i-1]; yy[i]=yy[i-1];
		if(c=='U') ++yy[i]; else ++xx[i];
	}
	for(int i=1;i<n;++i) if(belong(xx[i],yy[i])==0&&
							belong(xx[i-1],yy[i-1])*belong(xx[i+1],yy[i+1])<0)
		++ans;
	printf("%d",ans);
}