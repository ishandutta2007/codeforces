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
const int maxn=2e5+5;
int n,m,a[maxn];
vector<int> vec[maxn];
int mn[maxn],mx[maxn],b[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		map<int,int> mp;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(!mp[a[i]]) mp[a[i]]=mp.size();
			a[i]=mp[a[i]];
			vec[a[i]].push_back(i);
		}
		for(int i=1;i<=n;i++) mn[i]=mx[i]=i;
		while(m--){
			int l,r;
			l=read();
			r=read();
			mn[r]=min(mn[r],l);
			mx[l]=max(mx[l],r);
		}
		for(int i=2;i<=n;i++) mx[i]=max(mx[i],mx[i-1]);
		for(int i=n-1;i>0;i--) mn[i]=min(mn[i],mn[i+1]);
		for(int i=1;i<=n;i++)
			if(i<vec[a[i]].back()&&*upper_bound(vec[a[i]].begin(),vec[a[i]].end(),i)<=mx[i]) b[i]=-n;
			else b[i]=*lower_bound(vec[a[i]].begin(),vec[a[i]].end(),mn[i]);
		multiset<int> s;
		for(int i=1;i<=n;i++) s.insert(b[i]);
		int ans=n;
		for(int i=1;i<=n;i++){
			s.erase(s.find(b[i]));
			if(*lower_bound(vec[a[i]].begin(),vec[a[i]].end(),mn[i])<i) s.insert(i);
			ans=min(ans,i-(s.size()?*s.begin():i+1)+1);
		}
		printf("%d\n",max(ans,0));
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}