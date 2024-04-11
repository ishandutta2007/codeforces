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
int query(int w){
	printf("? %d\n",w);
	fflush(stdout);
	return read();
}
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	int n=read(),l=1,r=5e6;
	while(l<r){
		int mid=l+(r-l)/2;
		if(query(mid)==1) r=mid;
		else l=mid+1;
	}
	int ans=r;
	for(int i=1;i<=n;i++){
		int res=query(r/i);
		if(res) ans=min(ans,r/i*res);
	}
	printf("! %d\n",ans);
	fflush(stdout);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}