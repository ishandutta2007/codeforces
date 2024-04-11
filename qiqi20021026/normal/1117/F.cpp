#include<bits/stdc++.h>

using namespace std;

int n,m,ans,g[1<<20],a[20][20];
bool f[1<<20],h[20][20][1<<17];
char s[120000];

void fmt_plus(int f[]){
	for (int i=0;i<m;++i){
		int t=1<<i;
		for (int j=0;j<1<<m;j+=t<<1){
			int *f1=f+j,*f2=f+j+t;
			for (int k=0;k<t;++k)
				f2[k]+=f1[k];
		}
	}
}

void fmt_or(bool f[]){
	for (int i=0;i<m;++i){
		int t=1<<i;
		for (int j=0;j<1<<m;j+=t<<1){
			bool *f1=f+j,*f2=f+j+t;
			for (int k=0;k<t;++k)
				f2[k]|=f1[k];
		}
	}
}

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for (int i=1;i<=n;++i) ++g[1<<(s[i]-'a')];
	for (int i=0;i<m;++i)
		for (int j=0;j<m;++j) scanf("%d",a[i]+j);
	for (int i=0;i<m;++i)
		for (int j=0;j<m;++j){
			if (i==j||a[i][j]) continue;
			bool fl=0; int t=0;
			for (int k=1;k<=n;++k){
				if (s[k]==i+'a'){fl=1; t=0;}
				else
					if (fl&&s[k]==j+'a'){fl=0; h[i][j][t]=1; t=0;}
					else t|=1<<(s[k]-'a');
			}
			fmt_or(h[i][j]);
		}
	for (int i=0;i<m;++i){
		if (a[i][i]) continue;
		bool fl=0; int t=0;
		for (int k=1;k<=n;++k){
			if (s[k]==i+'a'){
				if (fl) h[i][i][t]=1;
				fl=1; t=0;
			}
			else t|=1<<(s[k]-'a');
		}
		fmt_or(h[i][i]);
	}
	f[0]=1;
	for (int i=1;i<1<<m;++i){
		f[i]=1;
		for (int j=0;j<m;++j)
			if (!(i>>j&1)&&h[j][j][i]){f[i]=0; break;}
		for (int j=0;j<m;++j) if (!(i>>j&1))
			for (int k=0;k<m;++k) if (j!=k&&!(i>>k&1))
				if (h[j][k][i]){f[i]=0; break;}
		if (!f[i]) continue; f[i]=0;
		for (int j=0;j<m;++j)
			if (i>>j&1) f[i]|=f[i^(1<<j)];
	}
	fmt_plus(g);
	ans=n; for (int i=0;i<1<<m;++i) if (f[i]) ans=min(ans,n-g[i]);
	printf("%d\n",ans);
	
	return 0;
}