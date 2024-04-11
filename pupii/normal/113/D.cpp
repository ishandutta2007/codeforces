#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int num[23][23],cnt,d[23];
bool s[23][23];
long double f[510][510],p[510],ans[510];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b,A=gi(),B=gi();
	if(A>B)std::swap(A,B);
	while(m--)a=gi(),b=gi(),++d[a],++d[b],s[a][b]=s[b][a]=1;
	for(int i=1;i<=n;++i)std::cin>>p[i];
	for(int i=1;i<=n;++i)s[i][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			num[i][j]=++cnt;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			f[num[i][j]][num[i][j]]+=-1;
			if(i==j)continue;
			for(int k=1;k<=n;++k)
				if(s[k][i])
					for(int l=1;l<=n;++l)
						if(s[l][j]){
							int a=k,b=l;if(a>b)std::swap(a,b);
							f[num[a][b]][num[i][j]]+=(i==k?p[i]:(1-p[i])/d[i])*(j==l?p[j]:(1-p[j])/d[j]);
						}
		}
	f[num[A][B]][cnt+1]-=1;
	for(int i=1;i<=cnt;++i){
		int p=0;
		for(int j=i;j<=cnt;++j)if(fabs(f[i][j])>1e-7){p=j;break;}
		if(!p)continue;
		std::swap(f[p],f[i]);
		for(int j=i+1;j<=cnt;++j){
			if(fabs(f[j][i])<1e-13)continue;
			double K=f[j][i]/f[i][i];
			for(int k=cnt+1;k>=i;--k)f[j][k]-=K*f[i][k];
		}
	}
	for(int i=cnt;i;--i){
		for(int j=i+1;j<=cnt;++j)f[i][cnt+1]-=ans[j]*f[i][j];
		if(fabs(f[i][i])<1e-13)ans[i]=0;
		else ans[i]=f[i][cnt+1]/f[i][i];
	}
	for(int i=1;i<=n;++i)std::cout<<ans[num[i][i]]<<' ';
	return 0;
}