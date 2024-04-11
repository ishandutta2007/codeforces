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
int n,a[maxn];
struct node{
	int l,r;
	node* ch[2];
	int minv,cnt,addv;
	void pushup(){
		if(ch[0]->minv<ch[1]->minv){
			minv=ch[0]->minv;
			cnt=ch[0]->cnt;
		}
		else if(ch[0]->minv==ch[1]->minv){
			minv=ch[0]->minv;
			cnt=ch[0]->cnt+ch[1]->cnt;
		}
		else{
			minv=ch[1]->minv;
			cnt=ch[1]->cnt;
		}
	}
	node(int l,int r):l(l),r(r),minv(l),cnt(1),addv(0){
		if(l<r){
			int mid=l+(r-l)/2;
			ch[0]=new node(l,mid);
			ch[1]=new node(mid+1,r);
		}
		else ch[0]=ch[1]=0;
	}
	void pushtag(int k){
		addv+=k;
		minv+=k;
	}
	void pushdown(){
		ch[0]->pushtag(addv);
		ch[1]->pushtag(addv);
		addv=0;
	}
	void modify(int ql,int qr,int k){
		if(ql==l&&qr==r) pushtag(k);
		else{
			pushdown();
			if(qr<=ch[0]->r) ch[0]->modify(ql,qr,k);
			else if(ql>=ch[1]->l) ch[1]->modify(ql,qr,k);
			else{
				ch[0]->modify(ql,ch[0]->r,k);
				ch[1]->modify(ch[1]->l,qr,k);
			}
			pushup();
		}
	}
}*rt;
int s1[maxn],top1=0,s2[maxn],top2=0;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=0;i<n;i++){
    	int x=readint();
    	a[x]=readint();
	}
	rt=new node(1,n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		while(top1&&a[s1[top1]]>a[i]){
			rt->modify(s1[top1-1]+1,s1[top1],a[s1[top1]]);
			top1--;
		}
		while(top2&&a[s2[top2]]<a[i]){
			rt->modify(s2[top2-1]+1,s2[top2],-a[s2[top2]]);
			top2--;
		}
		rt->modify(s1[top1]+1,i,-a[i]);
		rt->modify(s2[top2]+1,i,a[i]);
		if(rt->minv==i) ans+=rt->cnt;
		s1[++top1]=s2[++top2]=i;
	}
	printf("%lld\n",ans);
    return 0;
}