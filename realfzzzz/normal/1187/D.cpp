#include<algorithm>
#include<queue>
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
const int maxn=3e5+5;
int n,a[maxn],b[maxn];
queue<int> q[maxn];
struct node{
	int l,r;
	node* ch[2];
	int v;
	void pushup(){
		v=min(ch[0]->v,ch[1]->v);
	}
	node(int l,int r):l(l),r(r){
		if(l<r){
			int mid=l+(r-l)/2;
			ch[0]=new node(l,mid);
			ch[1]=new node(mid+1,r);
			pushup();
		}
		else{
			ch[0]=ch[1]=0;
			v=a[r];
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
		if(ql==l&&qr==r) return v;
		else{
			if(qr<=ch[0]->r) return ch[0]->query(ql,qr);
			else if(ql>=ch[1]->l) return ch[1]->query(ql,qr);
			else return min(ch[0]->query(ql,ch[0]->r),ch[1]->query(ch[1]->l,qr));
		}
	}
	~node(){
		if(l<r){
			delete ch[0];
			delete ch[1];
		}
	}
}*rt;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	n=readint();
    	for(int i=0;i<n;i++) a[i]=readint();
    	for(int i=0;i<n;i++) b[i]=readint();
    	for(int i=0;i<n;i++) q[a[i]].push(i);
    	rt=new node(0,n-1);
    	bool ok=1;
    	for(int i=0;i<n;i++){
    		if(q[b[i]].empty()){
    			ok=0;
    			break;
			}
    		if(rt->query(0,q[b[i]].front())<b[i]){
    			ok=0;
    			break;
			}
			rt->modify(q[b[i]].front(),maxn);
			q[b[i]].pop();
		}
		printf(ok?"yes\n":"no\n");
    	for(int i=1;i<=n;i++) queue<int>().swap(q[i]);
    	delete rt;
	}
    return 0;
}