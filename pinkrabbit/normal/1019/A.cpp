#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
#define Luogu Gu
int n,m;
int x[3005], y[3005];
int b[3005], p[3005], c[3005];
int M[3005];
LL Ans=1e16;

bool cmp(int i,int j){return y[i]<y[j];}

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d%d",x+i,y+i), p[i]=i, ++b[x[i]];
	sort(p+1,p+n+1,cmp);
	F(i,1,n){
		LL S=0, C=0;
		F(j,1,m) c[j]=b[j];
		F(j,1,n) if(x[p[j]]!=1){
			M[p[j]]=0;
			if(c[x[p[j]]]>=i)
				M[p[j]]=1, S+=y[p[j]], ++C, --c[x[p[j]]];
		}
		F(j,1,n) if(x[p[j]]!=1&&!M[p[j]]){
			if(b[1]+C<i) S+=y[p[j]], ++C;
		}
		Ans=min(Ans,S);
		
	} printf("%I64d",Ans);
	return 0;
}