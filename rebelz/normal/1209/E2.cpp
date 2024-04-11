#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int a[15],maxa;
	bool operator<(const node c)const{return maxa>c.maxa;}
}t[2005];

int n,m;
int f[5005],d[5005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=m;i++) t[i].maxa=0;
		for(int i=0;i<n;i++) for(int j=1;j<=m;j++) t[j].a[i]=readint(),chkmax(t[j].maxa,t[j].a[i]);
		memset(d,0,sizeof(d));
		sort(t+1,t+m+1);
		for(int i=1;i<=min(n,m);i++){
			memset(f,0,sizeof(f));
			for(int j=0;j<n;j++){
				for(int k=0;k<(1<<n);k++){
					int now=0;
					for(int l=0;l<n;l++) if(k&(1<<l)) now+=t[i].a[(j+l)%n];
					chkmax(f[k],now);
				}
			}
			for(int j=(1<<n)-1;j>=0;j--){
				for(int k=j;;k=(k-1)&j){
					chkmax(d[j],d[k]+f[j^k]);
					if(!k) break;
				}
			}
		}
		printf("%d\n",d[(1<<n)-1]);
	}
	return 0;
}