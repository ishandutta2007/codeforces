#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int n,k,a[maxn],cnt[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		int l=0,x=0,y=0,s=-n;
		for(int i=1;i<=n;i++){
			s+=cnt[i]*2;
			while(s-cnt[l]*2>=k) s-=cnt[l++]*2;
			if(l&&(!x||i-l<y-x)){
				x=l;
				y=i;
			}
		}
		printf("%d %d\n",x,y);
		s=0;
		int c=0,lst=0;
		for(int i=1;i<n;i++){
			s+=a[i]>=x&&a[i]<=y?1:-1;
			if(c<k-1&&s==c+1){
				printf("%d %d\n",lst+1,i);
				lst=i;
				c++;
			}
		}
		printf("%d %d\n",lst+1,n);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}