#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct prob{int a,p;}s[101];
il bool operator<(const prob&a,const prob&b){return a.a>b.a;}
double f[101][1010];// f[i][j]ijm
double p1[101];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	p1[0]=1;for(int i=1;i<101;++i)p1[i]=p1[i-1]*10/9;
	int tc=gi();
	double l,r,lmid,rmid,lans,rans;
	while(tc--){
		int n=gi();
		double C,T;scanf("%lf%lf",&C,&T);
		for(int i=1;i<=n;++i)s[i].a=gi(),s[i].p=gi();
		std::sort(s+1,s+n+1);
		for(int i=0;i<101;++i)
			for(int j=0;j<1010;++j)
				f[i][j]=1e18;
		f[0][0]=0;
		for(int i=1;i<=n;++i)
			for(int j=i;j;--j)
				for(int k=s[i].p;k<=10*i;++k)
					f[j][k]=std::min(f[j][k],f[j-1][k-s[i].p]+s[i].a*p1[j]);
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=ans+1;j<=10*i;++j){
				l=0,r=T;
				while(r-l>1e-5){
					lmid=l+(r-l)/3;
					rmid=lmid+(r-l)/3;
					lans=lmid+f[i][j]/(1+C*lmid);
					rans=rmid+f[i][j]/(1+C*rmid);
					if(lans<rans)r=rmid;
					else l=lmid;
				}
				l=(l+r)*0.5;
				if(l+f[i][j]/(1+C*l)+10*i<T)ans=j;
			}
		printf("%d\n",ans);
	}
	return 0;
}