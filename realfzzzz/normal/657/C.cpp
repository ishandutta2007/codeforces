#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=2e5+5;
int n,k,b,c,t[maxn];
priority_queue<ll> hp[5];
ll s[5];
int cdiv(int a,int b){
	if(a>=0) return a/b;
	else return -(-a-1)/b-1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	b=readint();
	c=readint();
	b=min(b,c*5);
	for(int i=1;i<=n;i++) t[i]=readint();
	sort(t+1,t+n+1);
	ll ans=9e18;
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			int x=cdiv(t[i],5),y=t[i]-x*5;
			ll res;
			if(j>=y) res=(j-y)*c-1ll*x*b;
			else res=(j+5-y)*c-1ll*(x+1)*b;
			hp[j].push(res);
			s[j]+=res;
			if((int)hp[j].size()>k){
				s[j]-=hp[j].top();
				hp[j].pop();
			}
		}
		for(int j=0;j<5;j++)
			if((int)hp[j].size()>=k){
				int x=cdiv(t[i]+j,5),y=t[i]+j-x*5;
				ans=min(ans,1ll*x*b*k+s[y]);
			}
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}