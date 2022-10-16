#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
struct ques{
	int x,y,l,r;
	bool operator<(const ques &q)const{return y<q.y;}
}q[maxn];
int n,Q,ql,p[maxn],a[maxn],b[maxn],r[maxn],stk[maxn],tp,to[20][maxn];
ll sum[maxn],pre[maxn],c[20][maxn],ans[maxn],bit[maxn];
set<int> s;
map<PII,int> mp;
pair<ll,int> jump(int x,int y){
	ll res=0;
	ROF(i,19,0) if(to[i][x]<=y) res+=c[i][x],x=to[i][x];
	return MP(res,x);
}
inline void update(int p,ll v){
	for(int i=p;i;i-=i&-i) bit[i]+=v;
}
inline ll query(int p){
	ll res=0;
	for(int i=p;i<=n+1;i+=i&-i) res+=bit[i];
	return res;
}
int main(){
	n=read();Q=read();
	FOR(i,1,n){
		p[i]=read();
		while(tp && p[stk[tp]]<p[i]) r[stk[tp--]]=i;
		stk[++tp]=i;
	}
	while(tp) r[stk[tp--]]=n+1;
	FOR(i,1,n) pre[i]=pre[i-1]+(a[i]=read());
	FOR(i,1,n) b[i]=min(pre[r[i]-1]-pre[i-1],(ll)read());
	FOR(i,0,19) to[i][n+1]=n+1,c[i][n+1]=0;
	ROF(i,n,1){
		to[0][i]=r[i];
		c[0][i]=min((ll)b[i],a[i]+jump(i+1,r[i]).first);
		FOR(j,1,19){
			to[j][i]=to[j-1][to[j-1][i]];
			c[j][i]=c[j-1][i]+c[j-1][to[j-1][i]];
		}
	}
	s.insert(1);s.insert(n+1);
	mp[MP(1,n+1)]=0;
	FOR(i,1,Q){
		int x=read();
		if(x!=1){
			auto it=s.find(x);
			if(it==s.end()){
				it=s.insert(x).first;
				auto it1=it,it2=it;
				it1--;it2++;
				q[++ql]=(ques){*it1,*it2,mp[MP(*it1,*it2)],i-1};
				mp[MP(*it1,*it2)]=-1;
				mp[MP(*it1,*it)]=mp[MP(*it,*it2)]=i;
			}
			else{
				auto it1=it,it2=it;
				it1--;it2++;
				q[++ql]=(ques){*it1,*it,mp[MP(*it1,*it)],i-1};
				q[++ql]=(ques){*it,*it2,mp[MP(*it,*it2)],i-1};
				mp[MP(*it1,*it)]=mp[MP(*it,*it2)]=-1;
				mp[MP(*it1,*it2)]=i;
				s.erase(it);
			}
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++) if(~it->second)
		q[++ql]=(ques){it->first.first,it->first.second,it->second,Q};
	sort(q+1,q+ql+1);
	int cur=1;
	FOR(i,1,ql){
		while(cur<=q[i].y){
			if(tp) update(stk[tp],-a[stk[tp]]-jump(stk[tp]+1,cur-1).first);
			while(tp && r[stk[tp]]==cur){
				if(tp>1) update(stk[tp-1],-a[stk[tp-1]]-jump(stk[tp-1]+1,stk[tp]).first);
				tp--;
			}
			if(cur!=1 && r[cur-1]!=cur){
				if(tp) update(stk[tp],a[stk[tp]]+jump(stk[tp]+1,cur-1).first);
				stk[++tp]=cur-1;
			}
			if(tp) update(stk[tp],a[stk[tp]]+jump(stk[tp]+1,cur).first);
			cur++;
		}
		auto p=jump(q[i].x,q[i].y);
		ll res=p.first+query(p.second);
		ans[q[i].l]+=res;
		ans[q[i].r+1]-=res;
	}
	FOR(i,1,Q) printf("%lld\n",ans[i]+=ans[i-1]);
}