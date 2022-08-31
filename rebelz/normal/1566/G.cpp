// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct edge{
	int x,y,z;
	bool operator<(const edge c)const{return z==c.z?mp(x,y)<mp(c.x,c.y):z<c.z;}
}e[200005];

int n,m,q,ncnt,ecnt;
int val[10000005],lch[10000005],rch[10000005],rt[100005],opt[200005],a[200005];
ll p[200005];
map<pii,int> now;
set<edge> st;
set<edge> fr[100005];

void change(int &id,int l,int r,int x,int c){
	if(!id) id=++ncnt;
	val[id]+=c;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) change(lch[id],l,mid,x,c);
	else change(rch[id],mid+1,r,x,c);
}

ll query(int id1,int id2,int id3,int l,int r){
	if(l==r) return val[id1]==val[id2]+val[id3]?r+1:r;
	int mid=(l+r)/2;
	if(val[lch[id1]]==val[lch[id2]]+val[lch[id3]]) return query(rch[id1],rch[id2],rch[id3],mid+1,r);
	else return query(lch[id1],lch[id2],lch[id3],l,mid);
}

ll find(int x,int y){
	if(x>y) swap(x,y);
	if(now.count(mp(x,y))){
		int id=now[mp(x,y)];
		change(rt[x],1,ecnt,e[id].z,-1);
	}
	ll ret=p[query(rt[0],rt[x],rt[y],1,ecnt)];
	if(now.count(mp(x,y))){
		int id=now[mp(x,y)];
		change(rt[x],1,ecnt,e[id].z,1);
	}
	return ret;
}

ll getans(){
	auto it1=st.begin(),it2=it1; it2++;
	if(it1->x!=it2->x&&it1->x!=it2->y&&it1->y!=it2->x&&it1->y!=it2->y) return p[it1->z]+p[it2->z];
	int w=0;
	if(it1->x==it2->x||it1->x==it2->y) w=it1->x;
	else w=it1->y;
	int v=it1->x==w?it1->y:it1->x,u=it2->x==w?it2->y:it2->x;
	ll ans=1ll<<60;
	chkmin(ans,find(v,w)+p[it1->z]);
	chkmin(ans,find(u,w)+p[it2->z]);
	auto it=++(++fr[w].begin());
	ll tmp=1ll<<60;
	if(it!=fr[w].end()) tmp=p[it->z];
	if(now.count(mp(min(u,v),max(u,v)))) chkmin(ans,tmp+p[e[now[mp(min(u,v),max(u,v))]].z]);
	chkmin(ans,p[it1->z]+p[it2->z]+tmp);
	return ans;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		e[i].x=readint(),e[i].y=readint(),e[i].z=readint();
		if(e[i].x>e[i].y) swap(e[i].x,e[i].y);
		opt[i]=1,a[i]=i;
		now[mp(e[i].x,e[i].y)]=i;
	}
	ecnt=m;
	q=readint();
	int op,x,y;
	for(int i=m+1;i<=m+q;i++){
		op=readint();
		if(op==0){
			x=readint(); y=readint();
			if(x>y) swap(x,y);
			opt[i]=0,a[i]=now[mp(x,y)];
			now.erase(mp(x,y));
		}
		else{
			e[++ecnt].x=readint(); e[ecnt].y=readint(); e[ecnt].z=readint();
			if(e[ecnt].x>e[ecnt].y) swap(e[ecnt].x,e[ecnt].y);
			opt[i]=1,a[i]=ecnt;
			now[mp(e[ecnt].x,e[ecnt].y)]=ecnt;
		}
	}
	for(int i=1;i<=ecnt;i++) p[i]=e[i].z;
	sort(p+1,p+ecnt+1);
	for(int i=1;i<=ecnt;i++) e[i].z=lower_bound(p+1,p+ecnt+1,e[i].z)-p;
	p[ecnt+1]=1ll<<60;
	now.clear();
	for(int i=1;i<=m+q;i++){
//		cout<<"test "<<a[i]<<endl;
		if(opt[i]==1){
			int id=a[i];
			now[mp(e[id].x,e[id].y)]=id;
			st.insert(e[id]);
			change(rt[e[id].x],1,ecnt,e[id].z,1);
			change(rt[e[id].y],1,ecnt,e[id].z,1);
			change(rt[0],1,ecnt,e[id].z,1);
			fr[e[id].x].insert(e[id]);
			fr[e[id].y].insert(e[id]);
		}
		else{
			int id=a[i];
			now.erase(mp(e[id].x,e[id].y));
			st.erase(e[id]);
			change(rt[e[id].x],1,ecnt,e[id].z,-1);
			change(rt[e[id].y],1,ecnt,e[id].z,-1);
			change(rt[0],1,ecnt,e[id].z,-1);
			fr[e[id].x].erase(e[id]);
			fr[e[id].y].erase(e[id]);
		}
		if(i>=m) printf("%lld\n",getans());
	}
	return 0;
}