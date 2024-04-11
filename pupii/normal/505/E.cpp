#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll h[100010],a[100010],s[100010],c[100010];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>que;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),k=gi(),p=gi();
	for(int i=1;i<=n;++i)h[i]=gi(),a[i]=gi();
	ll l=0,r=5001*1e9,mid;
	while(l<r){
		mid=(l+r)>>1;
		ll t=0;
		while(!que.empty())que.pop();
		for(int i=1;i<=n;++i){
			s[i]=mid-a[i]*m;c[i]=0;
			if(s[i]<0)que.push({(mid)/a[i],i});
			else if(s[i]<h[i])t+=(h[i]-s[i]+p-1)/p;
		}
		bool flg=1;
		for(int i=0;flg&&i<m;++i)
			for(int _=0;_<k;++_){
				if(!que.empty()){
					int o=que.top().second;
					if(que.top().first<=i){flg=0;break;}
					que.pop();
					++c[o],s[o]+=p;
					if(s[o]<0)que.push({(mid+p*c[o])/a[o],o});
					else if(s[o]<h[o])t+=(h[o]-s[o]+p-1)/p;
				}else if(t)--t;
			}
		if(t)flg=0;
		if(flg)r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}