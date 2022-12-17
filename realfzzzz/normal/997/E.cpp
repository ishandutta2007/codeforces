#include<algorithm>
#include<vector>
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
const int maxn=1.2e5+5;
int n,p[maxn],q;
typedef long long ll;
struct node{
	int l,r;
	node* ch[2];
	int mn,cnt,add1,add2;
	ll sum;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
		cnt=0;
		if(mn==ch[0]->mn) cnt+=ch[0]->cnt;
		if(mn==ch[1]->mn) cnt+=ch[1]->cnt;
		sum=ch[0]->sum+ch[1]->sum;
	}
	node(int l,int r)
	:l(l),r(r),mn(l),cnt(1),add1(0),add2(0),sum(0){
		if(l<r){
			int mid=l+(r-l)/2;
			ch[0]=new node(l,mid);
			ch[1]=new node(mid+1,r);
		}
	}
	void pushadd1(int k){
		add1+=k;
		mn+=k;
	}
	void pushadd2(int k){
		add2+=k;
		sum+=1ll*cnt*k;
	}
	void pushdown(){
		ch[0]->pushadd1(add1);
		ch[1]->pushadd1(add1);
		add1=0;
		if(mn==ch[0]->mn) ch[0]->pushadd2(add2);
		if(mn==ch[1]->mn) ch[1]->pushadd2(add2);
		add2=0;
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r) pushadd1(k);
		else{
			pushdown();
			if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
			if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
			pushup();
		}
	}
	ll query(int ql,int qr){
		if(ql<=l&&qr>=r) return sum;
		else{
			pushdown();
			ll ans=0;
			if(ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
			if(qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
			return ans;
		}
	}
}*rt;
int l[maxn];
vector<int> qs[maxn];
int s1[maxn],top1=0,s2[maxn],top2=0;
ll ans[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	q=readint();
	for(int i=0;i<q;i++){
		l[i]=readint();
		int r=readint();
		qs[r].push_back(i);
	}
	rt=new node(1,n);
	for(int i=1;i<=n;i++){
		rt->modify(1,n,-1);
		while(top1&&p[i]>p[s1[top1]]){
			rt->modify(s1[top1-1]+1,s1[top1],-p[s1[top1]]);
			top1--;
		}
		rt->modify(s1[top1]+1,i,p[i]);
		s1[++top1]=i;
		while(top2&&p[i]<p[s2[top2]]){
			rt->modify(s2[top2-1]+1,s2[top2],p[s2[top2]]);
			top2--;
		}
		rt->modify(s2[top2]+1,i,-p[i]);
		s2[++top2]=i;
		rt->pushadd2(1);
		for(int j=0;j<(int)qs[i].size();j++)
			ans[qs[i][j]]=rt->query(l[qs[i][j]],i);
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}