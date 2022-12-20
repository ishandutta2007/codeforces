#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define MN 100000
int n,m,a[MN+5],opt[MN+5][3],f[(1<<8)];
void gg(){
	puts("NO");
	exit(0);
}
bool flip(int i,int d){
	if(i+d+d>n) return false;
	++m;
	for(int j=0;j<3;j++)
		opt[m][j]=i+j*d,a[i+j*d]^=1;
	return true;
}
namespace bb{
	int n;
	int f[(1<<8)],fr[(1<<8)],cnt,mx; bool vis[(1<<8)];
	int flip(int x,int i,int d){
		if(i+d+d>n) return 0;
		i--;
		for(int j=0;j<3;j++) x^=(1<<(i+j*d));
		return x;
	}
	int toint(){
		int ret=0;
		for(int i=1;i<=n;i++)
			ret|=(a[i]<<(i-1));
		return ret;
	}
	void toopt(int x,int y){
		int st,d;
		x^=y;
		for(int i=0;i<n;i++)
			if(x&(1<<i)){st=i+1;break;}
		for(int i=st;i<n;i++)
			if(x&(1<<i)){d=i-st+1;break;}
		::flip(st,d);
	}
	void main(int _n){
		n=_n;
		std::queue<int> q;
		q.push(0); vis[0]=true; f[0]=0;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int i=1;i<=n-2;i++){
				for(int d=1;d<=n-2;d++){
					int y=flip(x,i,d);
					if(!vis[y]){
						f[y]=f[x]+1; fr[y]=x;
						vis[y]=true;
						q.push(y);
					}
				}
			}
		}
		int x=toint();
		if(vis[x]){
			while(x!=0){
				toopt(x,fr[x]);
				x=fr[x];
			}
		}else{
			::gg();
		}
	}
}
namespace bbb{
	int n,bsc;
	int f[(1<<8)],fr[(1<<8)],cnt,mx; bool vis[(1<<8)];
	int flip(int x,int i,int d){
		if(i+d+d>n) return 0;
		i--;
		for(int j=0;j<3;j++) x^=(1<<(i+j*d));
		return x;
	}
	int toint(){
		int ret=0;
		for(int i=1;i<=n;i++)
			ret|=(a[i+bsc]<<(i-1));
		return ret;
	}
	void toopt(int x,int y){
		int st,d;
		x^=y;
		for(int i=0;i<n;i++)
			if(x&(1<<i)){st=i+1;break;}
		for(int i=st;i<n;i++)
			if(x&(1<<i)){d=i-st+1;break;}
		::flip(st+bsc,d);
	}
	void main(int _n,int _bsc){
		n=_n; bsc=_bsc;
		std::queue<int> q;
		q.push(0); vis[0]=true; f[0]=0;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int i=1;i<=n-2;i++){
				for(int d=1;d<=n-2;d++){
					int y=flip(x,i,d);
					if(!vis[y]){
						f[y]=f[x]+1; fr[y]=x;
						vis[y]=true;
						q.push(y);
					}
				}
			}
		}
		int x=toint();
		if(vis[x]){
			while(x!=0){
				toopt(x,fr[x]);
				x=fr[x];
			}
		}else{
			::gg();
		}
	}
}
void printans(){
	for(int i=1;i<=n;i++)
		if(a[i]!=0) fprintf(stderr,"error : %d\n",i);
	puts("YES");
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",opt[i][0],opt[i][1],opt[i][2]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=8){
		bb::main(n);
	}else{
		for(int i=1;i<=n-7;i++){
			if(a[i]){
				if(a[i]&&a[i+1]&&a[i+2]) flip(i,1);
				else for(int j=i+2;j<=n;j++){
					if(a[j]&&flip(i,j-i))break;
					if(j==n) flip(i,1);
				}
			}
		}
		bbb::main(8,n-8);
	}
	printans();
}