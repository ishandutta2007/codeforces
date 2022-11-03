#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
std::vector<std::pair<int,int>>ans;
int p[300010],pos[300010],m;
il bool chk(int a,int b){return abs(a-b)>m;}
il vd swap(int a,int b){std::swap(p[a],p[b]),std::swap(pos[p[a]],pos[p[b]]),ans.push_back({a,b});}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();m=(n-1)/2;
	for(int i=1;i<=n;++i)pos[p[i]=gi()]=i;
	for(int i=2;i<n;++i){
		if(pos[i]==i)continue;
		if(chk(i,pos[i])){swap(pos[i],i);continue;}
		if(chk(i,1))
			if(chk(pos[i],1))swap(pos[i],1),swap(pos[i],i);
			else if(chk(pos[i],n))swap(pos[i],n),swap(pos[i],1),swap(pos[i],i);
			else assert(0);
		else if(chk(i,n))
			if(chk(pos[i],n))swap(pos[i],n),swap(pos[i],i);
			else if(chk(pos[i],1))swap(pos[i],1),swap(pos[i],n),swap(pos[i],i);
			else assert(0);
		else assert(0);
	}
	if(p[1]!=1)swap(1,n);
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d %d\n",i.first,i.second);
	return 0;
}