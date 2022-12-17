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
const int maxn=1e5+5;
int n,m,a[maxn];
const ll mod=1004535809,p=1e5+3,invp=703033431;
ll pw[maxn],ipw[maxn];
struct seq{
	int len;
	ll hs;
	seq operator +(seq b){
		return {len+b.len,(hs*pw[b.len]%mod+b.hs)%mod};
	}
	bool operator ==(seq b){
		return len==b.len&&hs==b.hs;
	}
};
seq sub(seq a,seq b){
	return {a.len-b.len,(a.hs-b.hs+mod)%mod*ipw[b.len]%mod};
}
struct node{
	int l,r;
	node* ch[2];
	bool flag;
	seq s1,s2;
	seq get1(int k){
		if(l==r) return k?s1:(seq){0,0};
		if(k<=ch[0]->s1.len) return ch[0]->get1(k);
		else return sub(ch[1]->get1(k-ch[0]->s1.len+ch[0]->s2.len),ch[0]->s2)+ch[0]->s1;
	}
	seq get2(int k){
		if(l==r) return k?s2:(seq){0,0};
		if(k<=ch[1]->s2.len) return ch[1]->get2(k);
		else return sub(ch[0]->get2(k-ch[1]->s2.len+ch[1]->s1.len),ch[1]->s1)+ch[1]->s2;
	}
	void pushup(){
		flag=ch[0]->flag&&ch[1]->flag;
		if(!flag) return;
		if(ch[0]->s2.len>=ch[1]->s1.len){
			flag=ch[0]->get2(ch[1]->s1.len)==ch[1]->s1;
			s1=ch[0]->s1;
			s2=sub(ch[0]->s2,ch[1]->s1)+ch[1]->s2;
		}
		else{
			flag=ch[1]->get1(ch[0]->s2.len)==ch[0]->s2;
			s1=sub(ch[1]->s1,ch[0]->s2)+ch[0]->s1;
			s2=ch[1]->s2;
		}
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			flag=1;
			if(a[r]>0){
				s1={0,0};
				s2={1,a[r]};
			}
			else{
				s1={1,-a[r]};
				s2={0,0};
			}
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x,int k){
		if(l==r){
			if(k>0){
				s1={0,0};
				s2={1,k};
			}
			else{
				s1={1,-k};
				s2={0,0};
			}
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	void local(int ql,int qr,vector<node*>& vec){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			vec.push_back(this);
			return;
		}
		ch[0]->local(ql,qr,vec);
		ch[1]->local(ql,qr,vec);
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	read();
	for(int i=1;i<=n;i++) a[i]=read();
	pw[0]=ipw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*p%mod;
		ipw[i]=ipw[i-1]*invp%mod;
	}
	rt=new node(1,n);
	m=read();
	while(m--){
		int opt=read();
		if(opt==1){
			int x,k;
			x=read();
			k=read();
			rt->modify(x,k);
		}
		else{
			int l,r;
			l=read();
			r=read();
			vector<node*> vec;
			rt->local(l,r,vec);
			int len=0;
			for(int i=0;i<(int)vec.size();i++){
				node* u=vec[i];
				if(!u->flag||u->s1.len>len){
					len=-1;
					break;
				}
				int res=u->s1.len,x=i-1;
				while(x>=0&&res>vec[x]->s2.len){
					res-=vec[x]->s2.len-vec[x]->s1.len;
					x--;
				}
				seq s=x>=0?vec[x]->get2(res):(seq){0,0};
				for(int j=x+1;j<i;j++) s=sub(s,vec[j]->s1)+vec[j]->s2;
				if(!(s==u->s1)){
					len=-1;
					break;
				}
				len+=u->s2.len-u->s1.len;
			}
			printf(len?"No\n":"Yes\n");
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}