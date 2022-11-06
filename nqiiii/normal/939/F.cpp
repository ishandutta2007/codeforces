/*
f[i][j][0]=min(f[i-1][j-(r[i]-r[i-1])][0]+r[i]-r[i-1],f[i-1][j-k][1]+1(k=0~r[i]-l[i])) 0 - 2
f[i][j][1]=min(f[i-1][j][1],f[i-1][j-k][0]+1(k=l[i]-r[i-1]~r[i]-r[i-1])) 3 - 5
//end of perid i, first bake j, face 0 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000,maxk=100,inf=0x3f3f3f3f;
int n,k,l[maxk+10],r[maxk+10],f[maxn*2+10][2],tmp[maxn*2+10][2],q[maxn*2+10],ql,qr;
int ans=inf;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i) scanf("%d%d",&l[i],&r[i]);
	memset(f,0x3f,sizeof f); f[0][0]=f[0][1]=0;
	for(int i=1;i<=k;++i){
		memset(tmp,0x3f,sizeof tmp); ql=1; qr=0;
		for(int j=0;j<=n*2;++j){
			if(j-r[i]+r[i-1]>=0) tmp[j][0]=min(tmp[j][0],f[j-r[i]+r[i-1]][0]);
			for(;ql<=qr&&f[j][1]<f[q[qr]][1];--qr); q[++qr]=j;
			for(;ql<=qr&&q[ql]<j-r[i]+l[i];++ql); if(ql<=qr) tmp[j][0]=min(tmp[j][0],f[q[ql]][1]+1);
		}
		ql=1; qr=0;
		for(int j=0;j<=n*2;++j){
			tmp[j][1]=min(tmp[j][1],f[j][1]);
			if(j-l[i]+r[i-1]>=0){
				for(;ql<=qr&&f[j-l[i]+r[i-1]][0]<f[q[qr]][0];--qr); q[++qr]=j-l[i]+r[i-1];
			}
			for(;ql<=qr&&q[ql]<j-r[i]+r[i-1];++ql); if(ql<=qr) tmp[j][1]=min(tmp[j][1],f[q[ql]][0]+1);
		}
		for(int j=0;j<=n*2;++j){
			f[j][0]=tmp[j][0]; f[j][1]=tmp[j][1];
			if(f[j][0]+1<f[j][1]) f[j][1]=f[j][0]+1;
			if(f[j][1]+1<f[j][0]) f[j][0]=f[j][1]+1;
		}
	}
	for(int i=0;i<=n*2;++i){
		if(i==r[k]-n) ans=min(ans,f[i][0]);
		if(i==n) ans=min(ans,f[i][1]);
	}
	if(ans>=inf) printf("Hungry");
	else printf("Full\n%d",ans);
}