#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
int T,n,m,x;
const int N=2e5+55;
const int haas=20041031;
typedef unsigned long long ull;
ull jy[10000007];
int main(){
	T=read();
	for(int i=1;i<=10000000;i++){
		jy[i]=(998244353ull*i);
	}
	while(T--){
		n=read();
		m=read();
		int da=1;
		map<ull,int>ma;
		for(int lll=10;lll<=11;lll++){
				ma[lll]++;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]--;
			}
			int hh=0;
			for(int jj=1;jj<=10;jj++){
				hh++;
			}
		for(int i=1;i<=n;i++){
			x=read();
			for(int lll=10;lll<=11;lll++){
				ma[lll]++;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]--;
			}
			ull w=0;
			for(int k=2;k*k<=x;k++){
				if(x%k==0){
					int js=0;
					while(x%k==0)js++,x/=k;
					if(js&1){
						w+=jy[k];
					}
					if(x==1)break;
				}
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]++;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]--;
			}
			if(x!=1){
				w+=jy[x];
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]++;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]--;
			}
			if(!ma[w]){
				ma[w]=1;
			}
			else{
				da++;
				ma.clear();
				ma[w]=1;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]++;
			}
			for(int lll=10;lll<=11;lll++){
				ma[lll]--;
			}
		}
		for(int uu=1;uu<=10;uu++){
			hh--;
		}
		printf("%d\n",da);
	}
	return 0;
}