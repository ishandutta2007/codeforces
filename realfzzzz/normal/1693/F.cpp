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
int n,s[maxn];
char a[maxn];
vector<int> vec[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+(a[i]=='1'?1:-1);
		if(s[n]<0){
			reverse(a+1,a+n+1);
			for(int i=1;i<=n;i++)
				a[i]=a[i]=='1'?'0':'1';
		}
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+(a[i]=='1'?1:-1);
		int r=n;
		while(r&&s[r]>s[r-1]) r--;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=r;i++)
			if(s[i]>0) vec[s[i]].push_back(i);
		int ans=0;
		while(s[r]>0){
			int l=vec[s[r]][0];
			for(int i=l+1;i<=r;i++)
				if(s[i]>0) vec[s[i]].pop_back();
			for(int i=l+1;i<=(l+r)/2;i++){
				s[i]=s[i-1]-1;
				if(s[i]>0) vec[s[i]].push_back(i);
			}
			for(int i=(l+r)/2+1;i<r;i++) s[i]=s[i-1]+1;
			ans++;
			r=(l+r)/2;
		}
		printf("%d\n",ans+(s[r]!=-r));
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}