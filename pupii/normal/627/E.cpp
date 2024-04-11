#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pos[3010];
std::vector<int>v[3010];
std::multiset<int>S;
//k
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),q=gi(),k=gi();
	for(int i=1,x,y;i<=q;++i)x=gi(),y=gi(),v[x].push_back(y);
	ll ans=0;
	for(int U=1;U<=n;++U){
		S.clear();
		ll res=0;
		for(int D=U;D<=n;++D){
			for(int p:v[D]){
				auto x=S.insert(p),_=x;
				for(int i=k-1;~i;--i)pos[i]=x==S.begin()?0:*--x;
				x=_;for(int i=k;i<=k<<1;++i)pos[i]=x==S.end()?m+1:*x++;
				for(int i=1;i<=k;++i)res+=(pos[i]-pos[i-1])*(pos[i+k]-pos[i+k-1]);
			}
			ans+=res;
		}
	}
	printf("%lld\n",ans);
	return 0;
}