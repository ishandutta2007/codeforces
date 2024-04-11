#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m,q;
typedef long long ll;
ll a[maxn];
vector<int> s[maxn];
const int maxs=350,S=316;
vector<int> v;
int it[maxs][maxn];
bool c[maxn];
ll sum[maxs],add[maxs];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++){
		int sz=readint();
		if(sz>S) v.push_back(i);
		while(sz--) s[i].push_back(readint());
	}
	for(int i=0;i<(int)v.size();i++){
		for(int j:s[v[i]]) c[j]=1;
		for(int j=1;j<=m;j++) for(int k:s[j]) it[i][j]+=c[k];
		for(int j:s[v[i]]) c[j]=0;
		for(int j:s[v[i]]) sum[i]+=a[j];
	}
	while(q--){
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='?'){
			int k=readint();
			if((int)s[k].size()>S){
				int pos=0;
				for(int i=0;i<(int)v.size();i++) if(v[i]==k) pos=i;
				ll ans=sum[pos];
				for(int i=0;i<(int)v.size();i++) ans+=add[i]*it[i][k];
				printf("%lld\n",ans);
			}
			else{
				ll ans=0;
				for(int i:s[k]) ans+=a[i];
				for(int i=0;i<(int)v.size();i++) ans+=add[i]*it[i][k];
				printf("%lld\n",ans);
			}
		}
		else{
			int k,x;
			k=readint();
			x=readint();
			if((int)s[k].size()>S){
				int pos=0;
				for(int i=0;i<(int)v.size();i++) if(v[i]==k) pos=i;
				add[pos]+=x;
			}
			else{
				for(int i:s[k]) a[i]+=x;
				for(int i=0;i<(int)v.size();i++) sum[i]+=1ll*x*it[i][k];
			}
		}
	}
	return 0;
}