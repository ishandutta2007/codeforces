#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=266666,mod=998244353;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct point{
	int x,y,c,id;
	bool operator<(const point &p)const{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
	point operator-(const point &p)const{return (point){x-p.x,y-p.y,0,0};}
	int operator*(const point &p)const{return x*p.y-y*p.x;}
}p[maxn];
int n,tp,hl,stk[maxn],hul[maxn],al;
PII ans[maxn];
inline void add(int x,int y){
	ans[++al]=MP(p[x].id,p[y].id);
}
bool in(int x,int y,int z,int i){
	if(i==x || i==y || i==z) return false;
	int c=(p[i]-p[x])*(p[y]-p[x])>0;
	c+=(p[i]-p[y])*(p[z]-p[y])>0;
	c+=(p[i]-p[z])*(p[x]-p[z])>0;
	return c==0 || c==3;
}
void work(int x,int y,int z,vector<int> &v){
//	assert(p[x].c==p[y].c && p[x].c!=p[z].c);
	if(v.empty()) return;
	int at=0;
	FOR(i,0,(int)v.size()-1) if(p[v[i]].c==p[z].c){at=v[i];break;}
	if(!at){
		sort(v.begin(),v.end());
		if(y==max({x,y,z}) || y==min({x,y,z})) swap(x,y);
		if(x==max({x,y,z})) add(x,v.back());
		else add(x,v.front());
		FOR(i,1,(int)v.size()-1) add(v[i],v[i-1]);
	}
	else{
		add(z,at);
		vector<int> v1,v2,v3;
		FOR(i,0,(int)v.size()-1){
			if(in(x,y,at,v[i])) v1.PB(v[i]);
			if(in(at,z,x,v[i])) v2.PB(v[i]);
			if(in(at,z,y,v[i])) v3.PB(v[i]);
		}
//		assert(v1.size()+v2.size()+v3.size()==v.size()-1);
		work(x,y,at,v1);
		work(at,z,x,v2);
		work(at,z,y,v3);
	}
}
void solve(int x,int y,int z){
	vector<int> v;
	FOR(i,1,n) if(in(x,y,z,i)) v.PB(i);
	work(x,y,z,v);
}
int main(){
	n=read();
	bool flag=true;
	FOR(i,1,n) p[i].x=read(),p[i].y=read(),p[i].c=read(),p[i].id=i-1,flag&=p[i].c==p[1].c;
	sort(p+1,p+n+1);
	if(flag){
		printf("%d\n",n-1);
		FOR(i,1,n-1) printf("%d %d\n",p[i].id,p[i+1].id);
		return 0;
	}
	FOR(i,1,n){
		while(tp>1 && (p[stk[tp]]-p[stk[tp-1]])*(p[i]-p[stk[tp]])<=0) tp--;
		stk[++tp]=i;
	}
	FOR(i,1,tp) hul[++hl]=stk[i];
	tp=0;
	ROF(i,n,1){
		while(tp>1 && (p[stk[tp]]-p[stk[tp-1]])*(p[i]-p[stk[tp]])<=0) tp--;
		stk[++tp]=i;
	}
	FOR(i,2,tp-1) hul[++hl]=stk[i];
	int l=hl,r=1;
	while(l && p[hul[l]].c==p[hul[1]].c) l--;
	while(r<=hl && p[hul[r]].c==p[hul[1]].c) r++;
	if(r>hl){
		FOR(i,1,hl-1) add(hul[i],hul[i+1]);
		FOR(i,1,n) if(p[i].c!=p[hul[1]].c){
			FOR(j,1,hl-1) solve(hul[j],hul[j+1],i);
			solve(hul[hl],hul[1],i);
			break;
		}
	}
	else{
		FOR(i,r,l) if(p[hul[i]].c==p[hul[1]].c) return puts("Impossible"),0;
		FOR(i,r,l-1) add(hul[i],hul[i+1]),solve(hul[i],hul[i+1],hul[1]);
		FOR(i,1,r-2) add(hul[i],hul[i+1]),solve(hul[i],hul[i+1],hul[r]);
		FOR(i,l+1,hl-1) add(hul[i],hul[i+1]),solve(hul[i],hul[i+1],hul[l]);
		if(l!=hl) add(hul[1],hul[hl]),solve(hul[1],hul[hl],hul[l]);
	}
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d\n",ans[i].first,ans[i].second);
}