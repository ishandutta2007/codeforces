#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
const int INF=0x3f3f3f3f;

int n,Ans=INF;
int a[2001],b[2001];

int s0=1;
int s1[10];
int s2[10][10];
int s3[10][10][10];
int s4[10][10][10][10];
int tot=1;
int Siz[716],P1[716],P2[716],P3[716],P4[716];
int q1[12880005],q2[12880005],q3[12880005],l=1,r=1;
int dis[2002][10][716];

void init(){
	F(i,1,9) s1[i]=++tot, Siz[tot]=1, P1[tot]=i;
	F(i,1,9) F(j,i,9) s2[i][j]=++tot, Siz[tot]=2, P1[tot]=i, P2[tot]=j;
	F(i,1,9) F(j,i,9) F(k,j,9) s3[i][j][k]=++tot, Siz[tot]=3, P1[tot]=i, P2[tot]=j, P3[tot]=k;
	F(i,1,9) F(j,i,9) F(k,j,9) F(l,k,9) s4[i][j][k][l]=++tot, Siz[tot]=4, P1[tot]=i, P2[tot]=j, P3[tot]=k, P4[tot]=l;
}

int main(){
	int p[5], P[5];
	memset(dis,-1,sizeof dis);
	init();
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",a+i,b+i);
	q1[1]=1, q2[1]=1, q3[1]=1; dis[1][1][1]=0;
	while(l<=r){
		int st=q1[l], lv=q2[l], S=q3[l];
		int sz=Siz[S];
		p[1]=P1[S], p[2]=P2[S], p[3]=P3[S], p[4]=P4[S];
		int d=dis[st][lv][S];
		if(sz<4&&st<=n){
			p[sz+1]=b[st];
			sort(p+1,p+sz+2);
			int nS;
			if(sz==0) nS=s1[p[1]];
			if(sz==1) nS=s2[p[1]][p[2]];
			if(sz==2) nS=s3[p[1]][p[2]][p[3]];
			if(sz==3) nS=s4[p[1]][p[2]][p[3]][p[4]];
			if(dis[st+1][a[st]][nS]==-1) q1[++r]=st+1, q2[r]=a[st], q3[r]=nS, dis[st+1][a[st]][nS]=d+abs(a[st]-lv);
			else dis[st+1][a[st]][nS]=min(dis[st+1][a[st]][nS],d+abs(a[st]-lv));
		}
		p[1]=P1[S], p[2]=P2[S], p[3]=P3[S], p[4]=P4[S];
		F(i,1,sz){
			P[1]=P1[S], P[2]=P2[S], P[3]=P3[S], P[4]=P4[S];
			if(p[i]){
				F(j,i,sz-1) P[j]=p[j+1];
				int nS;
				if(sz==1) nS=1;
				if(sz==2) nS=s1[P[1]];
				if(sz==3) nS=s2[P[1]][P[2]];
				if(sz==4) nS=s3[P[1]][P[2]][P[3]];
				if(dis[st][p[i]][nS]==-1) q1[++r]=st, q2[r]=p[i], q3[r]=nS, dis[st][p[i]][nS]=d+abs(p[i]-lv);
				else dis[st][p[i]][nS]=min(dis[st][p[i]][nS],d+abs(p[i]-lv));
			} else break;
		}
		++l;
	}
	F(i,1,9) Ans=min(Ans,dis[n+1][i][1]==-1?INF:dis[n+1][i][1]);
	printf("%d",Ans+n+n);
	return 0;
}