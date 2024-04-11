#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s=0;
	int x=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
const int N=2e5+55;
int T,n,a[N];
signed main(){
	T=read();
	while(T--){
		n=read();
		if(n==3){
			printf("5\n2 3 1\n2\n2 1\n1 3\n");
			continue;
		}
		int ans=0;
		if(!(n&1)){
			ans+=(n-1)*(n-1);
			int g=n-1;
			g--;
			int hh=n-1;
			while(g){
				ans+=2*(hh-1)*(hh-1);
				g-=2;
				hh--;
			}
		}
		else{
			ans+=(n-1)*(n-1);
			int g=n-1;
			g--;
			int hh=n-1;
			while(g>1){
				ans+=2*(hh-1)*(hh-1);
				g-=2;
				hh--;
			}
			ans+=(hh-1)*(hh-1);
		}
		printf("%lld\n",ans);
		if(!(n&1)){
			a[1]=(n/2)+1;
			a[n]=2;
			int tot=1;
			for(int i=3;i<=n/2;i++){
				a[++tot]=i;
			}
			a[++tot]=1;
			for(int i=a[1]+1;i<=n;i++){
				a[++tot]=i;
			}
			for(int i=1;i<=n;i++){
				printf("%lld ",a[i]);
			}
			puts("");
			printf("%lld\n",n-1);
			for(int i=n/2+1;i<n;i++){
				printf("%lld %lld\n",i,1ll);
			}
			for(int i=2;i<=n/2;i++){
				printf("%lld %lld\n",i,n);
			}
			printf("%lld %lld\n",1ll,n);
		}
		else{
			a[1]=(n/2)+1;
			a[n]=2;
			int tot=1;
			for(int i=3;i<=n/2;i++){
				a[++tot]=i;
			}
			a[++tot]=1;
			int qz=a[1];
			while(qz<n){
				qz++;
				a[++tot]=qz;
			}
			for(int i=1;i<=n;i++){
				printf("%lld ",a[i]);
			}
			puts("");
			printf("%lld\n",n-1);
			for(int i=2;i<=n/2;i++){
				printf("%lld %lld\n",i,n);
			}
			for(int i=n/2+1;i<n;i++){
				printf("%lld %lld\n",i,1ll);
			}
			printf("%lld %lld\n",1ll,n);
		}
	}
	return 0;
}