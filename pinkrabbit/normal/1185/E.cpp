#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 2005
#define inf 0x3f3f3f3f
int n,m;
char a[MN][MN],e[MN][MN];
int mxk,mxx[26],mnx[26],mxy[26],mny[26],cnt[26];
int ar(int a,int b,int c,int d){return (c-a+1)*(d-b+1);}
void pa(int k,int a,int b,int c,int d){
	F(i,a,c)F(j,b,d)e[i][j]=k+'a';
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		F(i,1,n)scanf("%s",a[i]+1);
		F(i,1,n)F(j,1,m)e[i][j]='.';
		F(i,1,n)e[i][m+1]='\0';
		F(k,0,25)mxx[k]=mxy[k]=-inf,mnx[k]=mny[k]=inf,cnt[k]=0;
		mxk=-1;
		F(i,1,n)F(j,1,m){
			if(a[i][j]=='.')continue;
			int k=a[i][j]-'a';
			mxx[k]=max(mxx[k],i);
			mnx[k]=min(mnx[k],i);
			mxy[k]=max(mxy[k],j);
			mny[k]=min(mny[k],j);
			++cnt[k];
			mxk=max(mxk,k);
		}
		int ok=1;
		if(mxk==-1){puts("YES\n0");continue;}
		F(k,0,mxk)if(cnt[k]&&mnx[k]!=mxx[k]&&mny[k]!=mxy[k]){ok=0;break;}
		if(ar(mnx[mxk],mny[mxk],mxx[mxk],mxy[mxk])!=cnt[mxk])ok=0;
		if(!ok){puts("NO");continue;}
		F(k,0,mxk){
			if(!cnt[k]){pa(k,mnx[mxk],mny[mxk],mxx[mxk],mxy[mxk]);continue;}
			pa(k,mnx[k],mny[k],mxx[k],mxy[k]);
		}
//		puts("e:");
//		F(i,1,n)printf("%s\n",e[i]+1);
//		puts("===");
		F(i,1,n)F(j,1,m)if(a[i][j]!=e[i][j])ok=0;
		if(!ok){puts("NO");continue;}
		printf("YES\n%d\n",mxk+1);
		F(k,0,mxk){
			if(!cnt[k]){printf("%d %d %d %d\n",mnx[mxk],mny[mxk],mxx[mxk],mxy[mxk]);continue;}
			printf("%d %d %d %d\n",mnx[k],mny[k],mxx[k],mxy[k]);
		}
	}
	return 0;
}