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
mt19937 rnd(time(0));
const int maxn=3e5+5;
int n,m,a[maxn];
bool b[50][maxn*2];
struct bit{
	int c[maxn];
	void modify(int x,int k){
		while(x<=n){
			c[x]+=k;
			x+=x&-x;
		}
	}
	int query(int x){
		int s=0;
		while(x){
			s+=c[x];
			x-=x&-x;
		}
		return s;
	}
}t[50];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!mp.count(a[i])) mp[a[i]]=mp.size()+1;
		a[i]=mp[a[i]];
	}
	for(int i=0;i<50;i++){
		for(int j=1;j<=n+m;j++) b[i][j]=rnd()%2;
		for(int j=1;j<=n;j++)
			if(b[i][a[j]]) t[i].modify(j,1);
	}
	while(m--){
		int opt=read();
		if(opt==1){
			int x,k;
			x=read();
			k=read();
			if(!mp.count(k)) mp[k]=mp.size()+1;
			k=mp[k];
			for(int i=0;i<50;i++){
				if(b[i][a[x]]) t[i].modify(x,-1);
				if(b[i][k]) t[i].modify(x,1);
			}
			a[x]=k;
		}
		else{
			int l,r,k;
			l=read();
			r=read();
			k=read();
			bool flag=1;
			for(int i=0;i<50;i++)
				flag&=(t[i].query(r)-t[i].query(l-1))%k==0;
			printf(flag?"YES\n":"NO\n");
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}