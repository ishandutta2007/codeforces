//jjakioi
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
std::deque<int>que;
int oA[200010],oB[200010],o,b[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),q=gi(),mx=0,a;
	for(int i=1;i<=n;++i)que.push_back(a=gi()),mx=std::max(mx,a);
	while(que.front()!=mx){
		int A=que.front();que.pop_front();
		int B=que.front();que.pop_front();
		++o;oA[o]=A,oB[o]=B;
		que.push_front(std::max(A,B));
		que.push_back(std::min(A,B));
	}
	int m=0;que.pop_front();
	while(!que.empty())b[m++]=que.front(),que.pop_front();
	while(q--){
		ll k=gi();
		if(k<=o)printf("%d %d\n",oA[k],oB[k]);
		else printf("%d %d\n",mx,b[(k-o-1+m)%m]);
	}
	return 0;
}