#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct XD{
    long long a,b;
    int c;
    int id;
    void get(int ii){
	scanf("%I64d%I64d%d",&a,&b,&c);
	id=ii;
    }
    bool operator<(const XD& x)const{
	return c<x.c;
    }
}in[55];
long long dp[55][110][55];
int pre[55][110][55][3];
inline void output(int i,int j,int k){
    if(pre[i][j][k][0]!=-1)output(pre[i][j][k][0],pre[i][j][k][1],pre[i][j][k][2]);
    printf("%d %I64d\n",in[i].id+1,in[i].a+j);
}
inline void relax(int a,int b,int c,long long v,int pa,int pb,int pc){
    if(dp[a][b][c]<v){
	dp[a][b][c]=v;
	pre[a][b][c][0]=pa;
	pre[a][b][c][1]=pb;
	pre[a][b][c][2]=pc;
    }
}
int main(){
    int n,m,k,i,j,q,w;
    scanf("%d%d%d",&m,&n,&k);// m,n swapped
    for(i=0;i<n;i++)in[i].get(i);
    sort(in,in+n);
    memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++){
	for(j=0;j<=in[i].b-in[i].a;j++){
	    relax(i,j,1,in[i].a+j,-1,-1,-1);
	}
	for(j=0;j<i;j++){
	    if(in[j].c==in[i].c)break;
	    for(w=0;w<=i;w++){
		for(q=0;q<=in[j].b-in[j].a;q++)if(dp[j][q][w]!=-1){
		    long long r=in[j].a+q;
		    if(r+k<=in[i].b&&r+k>=in[i].a){
			relax(i,r+k-in[i].a,w+1,dp[j][q][w]+r+k,j,q,w);
		    }
		    if(r*k<=in[i].b&&r*k>=in[i].a){
			relax(i,r*k-in[i].a,w+1,dp[j][q][w]+r*k,j,q,w);
		    }
		}
	    }
	}
    }
    
    long long aa=-1;
    int a1,a2,a3;
    for(i=0;i<n;i++)for(j=0;j<=in[i].b-in[i].a;j++)if(dp[i][j][m]>aa){
	aa=dp[i][j][m];
	a1=i;a2=j;a3=m;
    }
    if(aa==-1)puts("NO");
    else{
	puts("YES");
	output(a1,a2,a3);
    }
}