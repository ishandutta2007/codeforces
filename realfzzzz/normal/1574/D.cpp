#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=10+5;
int n,m,c[maxn];
vector<int> a[maxn];
struct item{
	vector<int> vec;
	int s;
	bool operator <(const item b)const{
		if(s!=b.s) return s<b.s;
		for(int i=1;i<=n;i++) if(vec[i]!=b.vec[i]) return vec[i]<b.vec[i];
		return 0;
	}
};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++){
		c[i]=readint();
		a[i].resize(c[i]+1);
		for(int j=1;j<=c[i];j++) a[i][j]=readint();
	}
	m=readint();
	set<vector<int>> s;
	while(m--){
		vector<int> b(n+1);
		for(int i=1;i<=n;i++) b[i]=readint();
		s.insert(b);
	}
	set<item> pq;
	vector<int> res(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		res[i]=c[i];
		sum+=a[i][c[i]];
	}
	pq.insert({res,sum});
	while(1){
		item u=*--pq.end();
		pq.erase(u);
		if(!s.count(u.vec)){
			for(int i=1;i<=n;i++) printf("%d ",u.vec[i]);
			break;
		}
		for(int i=1;i<=n;i++) if(u.vec[i]>1){
			u.s-=a[i][u.vec[i]]-a[i][u.vec[i]-1];
			u.vec[i]--;
			pq.insert(u);
			u.vec[i]++;
			u.s+=a[i][u.vec[i]]-a[i][u.vec[i]-1];
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}