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
const int maxn=1e5+5;
int n;
char s[maxn],t[maxn];
vector<int> vec[26];
int cur[26];
struct node{
	int l,r;
	node* ch[2];
	int mn,add=0;
	void pushup(){
		mn=ch[0]->mn;
	}
	node(vector<int>& vec,int l,int r):l(l),r(r),mn(vec[l]){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(vec,l,mid);
		ch[1]=new node(vec,mid+1,r);
	}
	void pushtag(int k){
		mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	int query1(int x){
		if(l==r) return r;
		pushdown();
		if(ch[1]->mn<x) return ch[1]->query1(x);
		else return ch[0]->query1(x);
	}
	int query2(int x){
		if(l==r) return mn;
		pushdown();
		if(x<=ch[0]->r) return ch[0]->query2(x);
		else return ch[1]->query2(x);
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt[26];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<26;i++) vec[i]={0};
		for(int i=1;i<=n;i++) vec[s[i]-'a'].push_back(i);
		for(int i=0;i<26;i++) cur[i]=1;
		for(int i=0;i<26;i++)
			rt[i]=new node(vec[i],0,vec[i].size()-1);
		ll ans=9e18,res=0;
		for(int i=1;i<=n;i++){
			int c=t[i]-'a';
			for(int j=0;j<c;j++)
				if(cur[j]<(int)vec[j].size())
					ans=min(ans,res+rt[j]->query2(cur[j])-i);
			if(cur[c]==(int)vec[c].size()) break;
			int x=rt[c]->query2(cur[c]);
			res+=x-i;
			for(int j=0;j<26;j++) rt[j]->modify(0,rt[j]->query1(x),1);
			cur[c]++;
		}
		printf("%lld\n",ans<9e18?ans:-1);
		for(int i=0;i<26;i++) delete rt[i];
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}