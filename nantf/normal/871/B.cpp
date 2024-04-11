#include<bits/stdc++.h>
using namespace std;
const int maxn=5555;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],b[maxn],p[maxn],q[maxn],tmp[maxn],cnt;
int ask(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	return read();
}
int main(){
	n=read();
	FOR(i,0,n-1) a[i]=ask(0,i);
	FOR(i,0,n-1) b[i]=ask(i,0);
	FOR(i,0,n-1){
		MEM(p,-1);
		FOR(j,0,n-1) q[j]=i^a[j];
		bool flag=true;
		FOR(j,0,n-1){
			if(p[q[j]]!=-1){flag=false;break;}
			p[q[j]]=j;
		}
		FOR(j,0,n-1) if(p[j]==-1){flag=false;break;}
		FOR(j,0,n-1) if((p[j]^q[0])!=b[j]){flag=false;break;}
		if(flag) cnt++;
	}
	printf("!\n%d\n",cnt);
	FOR(i,0,n-1){
		MEM(p,-1);
		FOR(j,0,n-1) q[j]=i^a[j];
		bool flag=true;
		FOR(j,0,n-1){
			if(p[q[j]]!=-1){flag=false;break;}
			p[q[j]]=j;
		}
		FOR(j,0,n-1) if(p[j]==-1){flag=false;break;}
		FOR(j,0,n-1) if((p[j]^q[0])!=b[j]){flag=false;break;}
		if(flag){
			FOR(j,0,n-1) printf("%d ",p[j]);
			fflush(stdout);
			return 0;
		}
	}
}