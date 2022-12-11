#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m,q;
int d[1<<20];
int r[1<<20];
int v[1<<20];

int id(int i, int j){return i*(m+1)+j;}

int f(int x, int y){
	int k=0;
	while(x--)k=d[k];
	while(y--)k=r[k];
	return k;
}

int main(){
	memset(v,-1,sizeof(d));
	scanf("%d%d%d",&n,&m,&q);
	fore(i,0,n){
		fore(j,0,m){
			scanf("%d",v+id(i+1,j+1));
		}
	}
	fore(i,0,n+1){
		fore(j,0,m+1){
			d[id(i,j)]=id(i+1,j);
			r[id(i,j)]=id(i,j+1);
		}
	}
	while(q--){
		int x0,y0,x1,y1,h,w;
		scanf("%d%d%d%d%d%d",&x0,&y0,&x1,&y1,&h,&w);
		int kk0=f(x0-1,y0-1),kk1=f(x1-1,y1-1);
		int k0=kk0,k1=kk1;
		fore(i,0,h){
			k0=d[k0];k1=d[k1];
			swap(r[k0],r[k1]);
		}
		fore(i,0,w){
			k0=r[k0];k1=r[k1];
			swap(d[k0],d[k1]);
		}
		k0=kk0,k1=kk1;
		fore(i,0,w){
			k0=r[k0];k1=r[k1];
			swap(d[k0],d[k1]);
		}
		fore(i,0,h){
			k0=d[k0];k1=d[k1];
			swap(r[k0],r[k1]);
		}
	}
	int k=0;
	fore(i,0,n){
		k=d[k];
		int kk=k;
		fore(j,0,m){
			kk=r[kk];
			if(j)putchar(' ');
			printf("%d",v[kk]);
		}
		puts("");
	}
	return 0;
}