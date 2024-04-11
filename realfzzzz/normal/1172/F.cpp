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
const int maxn=1e6+5;
int n,m,p,a[maxn];
typedef long long ll;
const ll inf=9e18;
struct node{
	int l,r;
	node* ch[2];
	ll s;
	vector<ll> f;
	void pushup(){
		s=ch[0]->s+ch[1]->s;
		for(int i=0;i<=r-l;i++) f.push_back(inf);
		for(int i=0;i<=ch[0]->r-l;i++) f[i]=ch[0]->f[i];
		int cur=0;
		for(int i=0;i<=ch[0]->r-l+1;i++){
			for(;cur<=r-ch[1]->l;cur++){
				ll pos=ch[1]->f[cur]+1ll*p*i-ch[0]->s;
				if(i==ch[0]->r-l+1||pos<ch[0]->f[i])
					f[i+cur]=min(f[i+cur],max(i>0?ch[0]->f[i-1]:-inf,pos));
				else break;
			}
			cur-=2;
			if(cur<0) cur=0;
		}
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
			s=a[r];
			f.push_back(p-a[r]);
		}
	}
	ll query(int ql,int qr,ll r0){
		if(ql==l&&qr==r){
			int pos=upper_bound(f.begin(),f.end(),r0)-f.begin();
			return r0+s-1ll*p*pos;
		}
		else{
			if(qr<=ch[0]->r) return ch[0]->query(ql,qr,r0);
			else if(ql>=ch[1]->l) return ch[1]->query(ql,qr,r0);
			else return ch[1]->query(ch[1]->l,qr,ch[0]->query(ql,ch[0]->r,r0));
		}	
	}
}*rt;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    p=readint();
    for(int i=1;i<=n;i++) a[i]=readint();
    rt=new node(1,n);
    while(m--){
    	int l,r;
    	l=readint();
    	r=readint();
    	printf("%lld\n",rt->query(l,r,0));
	}
    return 0;
}