#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn],f[2][maxn][2];
const int inf=2e9;
bool b[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		f[0][0][1]=f[1][0][1]=0;
		f[0][0][0]=inf;
		f[1][0][0]=-inf;
		for(int i=1;i<=n;i++){
			f[0][i][0]=min(f[0][i-1][0],f[0][i-1][1]);
			f[0][i][1]=f[0][i-1][0]<inf?f[0][i-1][0]+a[i]:inf;
			f[1][i][0]=max(f[1][i-1][0],f[1][i-1][1]);
			f[1][i][1]=f[1][i-1][0]>-inf?f[1][i-1][0]+a[i]:-inf;
		}
		int s=0;
		for(int i=1;i<=n;i++) s+=a[i];
		if(s%2!=0){
			printf("-1\n");
			continue;
		}
		s/=2;
		auto chk=[](int x,int s){
			return min(f[0][x][0],f[0][x][1])<=s&&s<=max(f[1][x][0],f[1][x][1]);
		};
		if(!chk(n,s)){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=n;i>0;)
			if(i>1&&chk(i-2,s-a[i])){
				b[i]=1;
				s-=a[i];
				i-=2;
			}
			else i--;
		int k=n;
		for(int i=1;i<=n;i++) k-=b[i];
		printf("%d\n",k);
		for(int i=1;i<=n;)
			if(i<n&&b[i+1]){
				printf("%d %d\n",i,i+1);
				i+=2;
			}
			else{
				printf("%d %d\n",i,i);
				i++;
			}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}