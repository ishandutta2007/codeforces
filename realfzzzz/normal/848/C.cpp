#include<set>
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
const int maxn=1e5+5;
int n,m,a[maxn];
set<int> s[maxn];
typedef set<int>::iterator iter;
int pre[maxn],suc[maxn];
int get_pre(int x){
	iter it=s[a[x]].lower_bound(x);
	if(it==s[a[x]].begin()) return 0;
	else return *(--it);
}
int get_suc(int x){
	iter it=s[a[x]].upper_bound(x);
	if(it==s[a[x]].end()) return n+1;
	else return *it;
}
struct point{
	int x,y,w,id;
	bool flag;
	point(int x,int y,int w,int id,bool flag)
	:x(x),y(y),w(w),id(id),flag(flag){}
};
vector<point> q1,q2;
void modify(int x){
	q1.push_back(point(x,pre[x],x,-1,0));
	q1.push_back(point(x,pre[x]=get_pre(x),-x,-1,0));
	q2.push_back(point(n+1-x,n+1-suc[x],-x,-1,0));
	q2.push_back(point(n+1-x,n+1-(suc[x]=get_suc(x)),x,-1,0));
}
typedef long long ll;
ll c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,ll k){
	while(x<=n+1){
		c[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
int ord[maxn*11];
ll ans[maxn];
void solve(vector<point>& q,int l,int r){
	if(l==r){
		ord[r]=r;
		return;
	}
	int mid=l+(r-l)/2;
	solve(q,l,mid);
	solve(q,mid+1,r);
	int cur=l;
	vector<int> res;
	for(int i=mid+1;i<=r;i++){
		while(cur<=mid&&q[ord[cur]].x<=q[ord[i]].x){
			modify(q[ord[cur]].y+1,q[ord[cur]].w);
			res.push_back(ord[cur]);
			cur++;
		}
		if(q[ord[i]].id>=0){
			ll s=query(q[ord[i]].y+1);
			if(q[ord[i]].flag) ans[q[ord[i]].id]+=s;
			else ans[q[ord[i]].id]-=s;
		}
		res.push_back(ord[i]);
	}
	for(int i=cur;i<=mid;i++) res.push_back(ord[i]);
	for(int i=l;i<cur;i++) modify(q[ord[i]].y+1,-q[ord[i]].w);
	for(int i=l;i<=r;i++) ord[i]=res[i-l];
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    for(int i=1;i<=n;i++) s[a[i]=readint()].insert(i);
    for(int i=1;i<=n;i++){
    	q1.push_back(point(i,pre[i]=get_pre(i),-i,-1,0));
    	q2.push_back(point(n+1-i,n+1-(suc[i]=get_suc(i)),i,-1,0));
	}
	int cnt=0;
	while(m--){
		int opt=readint();
		if(opt==1){
			int b,c;
			b=readint();
			c=readint();
			s[a[b]].erase(b);
			s[a[b]=c].insert(b);
			modify(pre[b]);
			modify(suc[b]);
			modify(b);
			modify(pre[b]);
			modify(suc[b]);
		}
		else{
			int b,c;
			b=readint();
			c=readint();
			q1.push_back(point(c,b-1,0,cnt,1));
			q1.push_back(point(b-1,b-1,0,cnt,0));
			q2.push_back(point(n+1-b,n-c,0,cnt,1));
			q2.push_back(point(n-c,n-c,0,cnt,0));
			cnt++;
		}
	}
	solve(q1,0,q1.size()-1);
	solve(q2,0,q2.size()-1);
	for(int i=0;i<cnt;i++) printf("%lld\n",ans[i]);
    return 0;
}