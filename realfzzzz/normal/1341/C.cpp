#include<algorithm>
#include<cctype>
#include<cstdio>
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
int n,p[maxn];
struct node{
	int l,r;
	node* ch[2];
	int v;
	void pushup(){
		v=max(ch[0]->v,ch[1]->v);
	}
	node(int l,int r):l(l),r(r),v(1){
		if(l<r){
			int mid=l+(r-l)/2;
			ch[0]=new node(l,mid);
			ch[1]=new node(mid+1,r);
		}
	}
	void modify(int x,int k){
		if(l==r) v=k;
		else{
			if(x<=ch[0]->r) ch[0]->modify(x,k);
			else ch[1]->modify(x,k);
			pushup();
		}
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return v;
		else{
			int ans=0;
			if(ql<=ch[0]->r) ans=max(ans,ch[0]->query(ql,qr));
			if(qr>=ch[1]->l) ans=max(ans,ch[1]->query(ql,qr));
			return ans;
		}
	}
}*rt;
int nxt[maxn],pre[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		for(int i=1;i<=n;i++) p[readint()]=i;
		rt=new node(1,n);
		for(int i=1;i<=n;i++){
			nxt[i]=i+1;
			pre[i]=i-1;
		}
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(rt->query(p[i],p[i])!=rt->v){
				ok=0;
				break;
			}
			if(pre[p[i]]>0) nxt[pre[p[i]]]=nxt[p[i]];
			if(nxt[p[i]]<=n){
				pre[nxt[p[i]]]=pre[p[i]];
				rt->modify(nxt[p[i]],rt->query(nxt[p[i]],nxt[p[i]])+rt->query(p[i],p[i]));
			}
			rt->modify(p[i],0);
		}
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}