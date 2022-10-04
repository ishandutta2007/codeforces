#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef pair<int,int> pii;

int n,m,r,c,x,y;
int M[2005][2005];
bool v[2005][2005];
char str[2005];

pii q[8000005],p[8000005];
int L,R;

int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&x,&y);
	F(i,1,n) {scanf("%s",str+1); F(j,1,m) M[i][j]=str[j]=='.'; }
	q[L=R=4000000]=pii(r,c); p[4000000]=pii(0,0); v[r][c]=1;
	while(L<=R){
		pii pos=q[L];
		pii st=p[L];
		++L;
		for(int j=pos.first-1;M[j][pos.second]&&!v[j][pos.second];--j){
			q[--L]=pii(j,pos.second);
			p[L]=st;
			v[j][pos.second]=1;
		}
		for(int j=pos.first+1;M[j][pos.second]&&!v[j][pos.second];++j){
			q[--L]=pii(j,pos.second);
			p[L]=st;
			v[j][pos.second]=1;
		}
		if(st.first<x&&M[pos.first][pos.second-1]&&!v[pos.first][pos.second-1]){
			q[++R]=pii(pos.first,pos.second-1);
			p[R]=pii(st.first+1,st.second);
			v[pos.first][pos.second-1]=1;
		}
		if(st.second<y&&M[pos.first][pos.second+1]&&!v[pos.first][pos.second+1]){
			q[++R]=pii(pos.first,pos.second+1);
			p[R]=pii(st.first,st.second+1);
			v[pos.first][pos.second+1]=1;
		}
	}
	int Ans=0;
	F(i,1,n) F(j,1,m) if(v[i][j]) ++Ans;
	printf("%d",Ans);
	return 0;
}