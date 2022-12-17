// LUOGU_RID: 91366392
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
const int maxn=4e4+5,maxk=1e6+5,maxb=1.1e3;
int n,m,k,t;
vector<int> b1[maxn],b2[maxn];
int S;
struct ds{
	int s[maxb],c[maxk];
	void modify(int x,int k){
		s[(x-1)/S]-=c[x]?1:0;
		c[x]+=k;
		s[(x-1)/S]+=c[x]?1:0;
	}
	int query(){
		int x=0;
		while(s[x]==S) x++;
		x=x*S+1;
		while(c[x]) x++;
		return x;
	}
}s1,s2;
void upd(int x,int y,int k){
	for(int i:b1[(x-1)*m+y]) s1.modify(i,k);
	for(int i:b2[(x-1)*m+y]) s2.modify(i,k);
}
int solve(int d){
	int ans=0,c=max(1,1-d);
	for(int i=max(1,1-d);i<=min(n,m-d);i++){
		upd(i,i+d,1);
		for(int j=1;j<=i-c;j++){
			upd(i-j,i+d,1);
			upd(i,i+d-j,1);
		}
		while(c<=i&&s1.query()+s2.query()-1>=t){
			upd(c,c+d,-1);
			for(int j=1;j<=i-c;j++){
				upd(c+j,c+d,-1);
				upd(c,c+d+j,-1);
			}
			c++;
		}
		ans+=c-max(1,1-d);
	}
	for(int i=c;i<=min(n,m-d);i++)
		for(int j=c+d;j<=min(n+d,m);j++) upd(i,j,-1);
	return ans;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	k=read();
	t=read();
	for(int i=1;i<=k;i++){
		int x,y,w;
		x=read();
		y=read();
		w=read();
		if(w>0) b1[(x-1)*m+y].push_back(min(w,k+2));
		else b2[(x-1)*m+y].push_back(min(-w,k+2));
	}
	S=sqrt(k);
	ll ans=0;
	for(int i=1-n;i<m;i++) ans+=solve(i);
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}