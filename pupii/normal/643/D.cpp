#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll t[100010],res[100010];
int d[100010],du[100010];
std::multiset<ll>max[100010],st;
ll calc(ll x,int y){return x-x/(y+1)*y;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),q=gi();
	for(int i=1;i<=n;++i)t[i]=gi();
	for(int i=1;i<=n;++i)d[i]=gi(),++du[i],++du[d[i]];
	for(int i=1;i<=n;++i)res[d[i]]+=t[i]/(du[i]+1);
	auto Ins=[&](int x){
		if(!max[x].empty()){
			st.insert(*max[x].begin()+t[x]/(du[x]+1));
			st.insert(*max[x].rbegin()+t[x]/(du[x]+1));
		}
	};
	auto Rem=[&](int x){
		if(!max[x].empty()){
			st.erase(st.find(*max[x].begin()+t[x]/(du[x]+1)));
			st.erase(st.find(*max[x].rbegin()+t[x]/(du[x]+1)));
		}
	};
	auto ins=[&](int x){max[d[x]].insert(res[x]);};
	auto rem=[&](int x){max[d[x]].erase(max[d[x]].find(res[x]));};
	for(int i=1;i<=n;++i)res[i]+=calc(t[i],du[i]),ins(i);
	for(int i=1;i<=n;++i)Ins(i);
	while(q--){
		int o=gi();
		if(o==1){
			int i=gi(),j=gi();
			std::vector<int>A={i,d[i],d[d[i]],d[d[d[i]]],j,d[j],d[d[j]]};
			std::vector<int>B={i,d[i],d[d[i]],j,d[j]};
			std::sort(A.begin(),A.end());
			A.erase(std::unique(A.begin(),A.end()),A.end());
			std::sort(B.begin(),B.end());
			B.erase(std::unique(B.begin(),B.end()),B.end());
			for(int x:A)Rem(x);
			for(int x:B)rem(x);

			for(int x:B)res[x]-=calc(t[x],du[x]);
			for(int x:B)for(int y:B)if(d[y]==x)res[x]-=t[y]/(du[y]+1);
			--du[d[i]];++du[d[i]=j];
			for(int x:B)res[x]+=calc(t[x],du[x]);
			for(int x:B)for(int y:B)if(d[y]==x)res[x]+=t[y]/(du[y]+1);
			
			for(int x:B)ins(x);
			for(int x:A)Ins(x);
			
		}else if(o==2){
			int i=gi();
			printf("%lld\n",res[i]+t[d[i]]/(du[d[i]]+1));
		}else{
			printf("%lld %lld\n",*st.begin(),*--st.end());
		}
	}
	return 0;
}