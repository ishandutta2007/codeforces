#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222222;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],lim=2097151,ans;
PII v[maxn];
void insert(PII &p,int v){
	if(p.first<v) p.second=p.first,p.first=v;
	else p.second=max(p.second,v);
}
int main(){
	n=read();
	FOR(i,1,n) insert(v[a[i]=read()],i);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) insert(v[j+k],v[i+j+k].first),insert(v[j+k],v[i+j+k].second);
	ROF(_,21,0){
		bool flag=false;
		int go=ans+(1<<_);
		FOR(i,1,n-2) if((a[i]|go)==a[i]){flag=true;break;}
		if(!flag) FOR(i,1,n) if(v[go-(go&a[i])].second>i){flag=true;break;}
		if(flag) ans=go;
	}
	printf("%d\n",ans);
}