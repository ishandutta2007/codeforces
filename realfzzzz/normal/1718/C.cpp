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
int n,m,a[maxn],p[20],cnt;
ll sum[20][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=0;i<n;i++) a[i]=read();
		int x=n;
		cnt=0;
		for(int i=2;x>1;i++) if(x%i==0){
			p[++cnt]=n/i;
			while(x%i==0) x/=i;
		}
		multiset<ll> s;
		for(int i=1;i<=cnt;i++) for(int j=0;j<p[i];j++){
			sum[i][j]=0;
			for(int k=j;k<n;k+=p[i]) sum[i][j]+=1ll*a[k]*p[i];
			s.insert(sum[i][j]);
		}
		printf("%lld\n",*--s.end());
		while(m--){
			int x,k;
			x=read()-1;
			k=read();
			for(int i=1;i<=cnt;i++){
				s.erase(s.find(sum[i][x%p[i]]));
				s.insert(sum[i][x%p[i]]+=1ll*(k-a[x])*p[i]);
			}
			a[x]=k;
			printf("%lld\n",*--s.end());
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}