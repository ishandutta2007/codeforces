#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
struct it{
	int a;
	ll b;
	int tp,id;
	bool operator<(const it &i)const{
		if(a*i.b!=i.a*b) return a*i.b>i.a*b;
		return id<i.id;
	}
};
int k,n,m;
ll a[maxn];
it to[maxn];
vector<it> v[maxn],mul;
int main(){
	k=read();n=read();m=read();
	FOR(i,1,k) a[i]=read();
	FOR(i,1,k) to[i].b=1;
	FOR(i,1,n){
		int t=read(),x=read(),b=read();
		if(t==1) to[x]=min(to[x],(it){b,1,1,i});
		if(t==2) v[x].PB((it){b,1,2,i});
		if(t==3) mul.PB((it){b-1,1,3,i});
	}
	FOR(i,1,k) if(to[i].a>a[i]) v[i].PB((it){to[i].a-a[i],1,1,to[i].id});
	FOR(i,1,k){
		sort(v[i].begin(),v[i].end());
		FOR(j,0,(int)v[i].size()-1){
			mul.PB((it){v[i][j].a,a[i],v[i][j].tp,v[i][j].id});
			a[i]+=v[i][j].a;
		}
	}
	sort(mul.begin(),mul.end());
	int l=min(m,(int)mul.size());
	printf("%d\n",l);
	FOR(i,0,l-1) if(mul[i].tp==1) printf("%d ",mul[i].id);
	FOR(i,0,l-1) if(mul[i].tp==2) printf("%d ",mul[i].id);
	FOR(i,0,l-1) if(mul[i].tp==3) printf("%d ",mul[i].id);
}