#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int hd,tl;
int dist[300010],_dist[300010],vis[300010];
ll F[300010];
std::priority_queue<std::pair<int,int> >que;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int m=gi(),a=gi(),b=gi(),n=2*a+b;
	memset(dist,63,sizeof dist);
	dist[0]=0;que.push({0,0});
	while(!que.empty()){
		int x=que.top().second;
		vis[x]=1;
		if(x>=b&&dist[x-b]>dist[x])dist[x-b]=dist[x],que.push({-dist[x-b],x-b});
		if(x+a<=n&&dist[x+a]>std::max(x+a,dist[x]))dist[x+a]=std::max(x+a,dist[x]),que.push({-dist[x+a],x+a});
		while(!que.empty()&&vis[que.top().second])que.pop();
	}
	ll ans=0;
	int mn=std::min(m,a+b-1);
	for(int i=0;i<=mn;++i)ans+=std::max(0,mn-dist[i]+1);
	if(m>=a+b){
		int s=a/std::__gcd(a,b);
		memcpy(_dist,dist,sizeof dist);
		std::sort(_dist,_dist+n);
		ll nowf=0;
		for(int i=0,p=0,tot=0;i<n;++i){
			while(p!=n&&_dist[p]-1<=i)++tot,nowf-=_dist[p]-1,++p;
			F[i]=nowf+1ll*tot*i;
		}
		for(int i=n-1;i;--i)F[i]-=F[i-1];
		for(int _l=a+b,_r=(m-b%a)/a*a+b%a;_l<a+a+b;++_l,++_r){
			if(_r>m)_r-=a;
			int l=_l/a,r=_r/a;
			ans+=1ll*(r-l+1)*F[_l]+1ll*(r-l+1)*(r-l)/2*s;
		}
	}
	printf("%lld\n",ans);
	return 0;
}