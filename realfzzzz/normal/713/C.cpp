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
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n=read();
	priority_queue<int> pq;
	pq.push(read()-1);
	ll ans=0;
	for(int i=2;i<=n;i++){
		int a=read()-i;
		if(a>pq.top()) pq.push(a);
		else{
			ans+=pq.top()-a;
			pq.pop();
			pq.push(a);
			pq.push(a);
		}
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}