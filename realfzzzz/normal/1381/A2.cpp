#include<algorithm>
#include<vector>
#include<ctime>
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
int n;
char a[maxn],b[maxn];
struct node{
	bool v;
	int s,r;
	node* ch[2];
	bool flip;
	node(bool x):v(x),s(1),r(rand()),flip(0){
		ch[0]=ch[1]=0;
	}
	void pushup(){
		s=1;
		if(ch[0]) s+=ch[0]->s;
		if(ch[1]) s+=ch[1]->s;
	}
	void pushtag(){
		flip^=1;
		v^=1;
		swap(ch[0],ch[1]);
	}
	void pushdown(){
		if(flip){
			if(ch[0]) ch[0]->pushtag();
			if(ch[1]) ch[1]->pushtag();
			flip=0;
		}
	}
};
node* merge(node* l,node* r){
	if(!l) return r;
	if(!r) return l;
	if(l->r>r->r){
		l->pushdown();
		l->ch[1]=merge(l->ch[1],r);
		l->pushup();
		return l;
	}
	else{
		r->pushdown();
		r->ch[0]=merge(l,r->ch[0]);
		r->pushup();
		return r;
	}
}
void split(node* o,int k,node*& l,node*& r){
	if(!o){
		l=r=0;
		return;
	}
	o->pushdown();
	if(o->ch[0]){
		if(k<=o->ch[0]->s){
			split(o->ch[0],k,l,o->ch[0]);
			r=o;
		}
		else{
			split(o->ch[1],k-o->ch[0]->s-1,o->ch[1],r);
			l=o;
		}
	}
	else{
		if(!k){
			l=0;
			r=o;
		}
		else{
			split(o->ch[1],k-1,o->ch[1],r);
			l=o;
		}
	}
	o->pushup();
}
node* rt;
void modify(int l,int r){
	node *left,*mid,*right;
	split(rt,r,rt,right);
	split(rt,l-1,left,mid);
	mid->pushtag();
	rt=merge(merge(left,mid),right);
}
bool query(int x){
	node *left,*mid,*right;
	split(rt,x,rt,right);
	split(rt,x-1,left,mid);
	char res=mid->v;
	rt=merge(merge(left,mid),right);
	return res;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	srand(time(0));
	int t=readint();
	while(t--){
		n=readint();
		scanf("%s%s",a+1,b+1);
		rt=0;
		for(int i=1;i<=n;i++) rt=merge(rt,new node(a[i]-'0'));
		vector<int> ans;
		for(int i=n;i>0;i--){
			if(query(1)==b[i]-'0'){
				ans.push_back(1);
				modify(1,1);
			}
			ans.push_back(i);
			modify(1,i);
		}
		printf("%d ",ans.size());
		for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}