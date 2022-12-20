#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,maxk=12;
int n,k,q,a[maxk+5][maxn];
bitset<(1<<maxk)+5> f[maxk+maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	q=readint();
	for(int i=0;i<k;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	for(int i=0;i<k;i++) for(int j=0;j<(1<<k);j++) f[i][j]=j>>i&1;
	int cnt=k;
	while(q--){
		int t=readint();
		if(t==1){
			int x,y;
			x=readint()-1;
			y=readint()-1;
			f[cnt++]=f[x]|f[y];
		}
		else if(t==2){
			int x,y;
			x=readint()-1;
			y=readint()-1;
			f[cnt++]=f[x]&f[y];
		}
		else{
			int x,y;
			x=readint()-1;
			y=readint();
			int l=1,r=1e9;
			while(l<r){
				int mid=l+(r-l+1)/2,res=0;
				for(int i=0;i<k;i++) if(a[i][y]>=mid) res|=1<<i;
				if(f[x][res]) l=mid;
				else r=mid-1;
			}
			printf("%d\n",r);
		}
	}
	return 0;
}