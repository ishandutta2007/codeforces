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
const int maxn=2e5+5;
int n,m,l[maxn],r[maxn];
char s[maxn],f[maxn];
struct node{
	int l,r;
	node* ch[2];
	int cnt,ass;
	void pushup(){
		cnt=ch[0]->cnt+ch[1]->cnt;
	}
	node(int l,int r):l(l),r(r),ass(-1){
		if(l==r){
			cnt=f[r]=='1';
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(bool k){
		ass=k;
		cnt=k?r-l+1:0;
	}
	void pushdown(){
		if(ass>=0){
			ch[0]->pushtag(ass);
			ch[1]->pushtag(ass);
			ass=-1;
		}
	}
	void modify(int ql,int qr,bool k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return cnt;
		int ans=0;
		pushdown();
		if(ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
		return ans;
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		scanf("%s%s",s+1,f+1);
		for(int i=1;i<=m;i++){
			l[i]=readint();
			r[i]=readint();
		}
		rt=new node(1,n);
		bool flag=1;
		for(int i=m;i>0;i--){
			int res=rt->query(l[i],r[i]);
			if(res*2<r[i]-l[i]+1) rt->modify(l[i],r[i],0);
			else if(res*2>r[i]-l[i]+1) rt->modify(l[i],r[i],1);
			else flag=0;
		}
		for(int i=1;i<=n;i++) if((s[i]=='1')^rt->query(i,i)) flag=0;
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}