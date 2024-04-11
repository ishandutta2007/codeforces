#include<cstring>
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
const int maxn=2e5+5,maxk=10+5;
int n,m,k;
char s[maxn],t[maxk];
struct node{
	int l,r;
	node* ch[2];
	int lv,rv,cnt[maxk][maxk],setv;
	void pushup(){
		lv=ch[0]->lv;
		rv=ch[1]->rv;
		for(int i=0;i<k;i++) for(int j=0;j<k;j++)
			cnt[i][j]=ch[0]->cnt[i][j]+ch[1]->cnt[i][j];
		cnt[ch[0]->rv][ch[1]->lv]++;
	}
	node(int l,int r):l(l),r(r),setv(-1){
		if(l<r){
			int mid=l+(r-l)/2;
			ch[0]=new node(l,mid);
			ch[1]=new node(mid+1,r);
			pushup();
		}
		else{
			lv=rv=s[r]-'a';
			memset(cnt,0,sizeof(cnt));
		}
	}
	void pushtag(int k){
		setv=k;
		lv=rv=k;
		memset(cnt,0,sizeof(cnt));
		cnt[k][k]=r-l;
	}
	void pushdown(){
		if(setv>=0){
			ch[0]->pushtag(setv);
			ch[1]->pushtag(setv);
			setv=-1;
		}
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r) pushtag(k);
		else{
			pushdown();
			if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
			if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
			pushup();
		}
	}
}*rt;
inline char readchar(){
	char c=getchar();
	while(isspace(c)) c=getchar();
	return c;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	scanf("%s",s+1);
	rt=new node(1,n);
	while(m--){
		int opt=readint();
		if(opt==1){
			int l,r;
			l=readint();
			r=readint();
			rt->modify(l,r,readchar()-'a');
		}
		else{
			scanf("%s",t);
			int ans=1;
			for(int i=0;i<k;i++) for(int j=0;j<=i;j++)
				ans+=rt->cnt[t[i]-'a'][t[j]-'a'];
			printf("%d\n",ans);
		}
	}
	return 0;
}