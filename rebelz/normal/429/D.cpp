#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,D,ans,rt;
ll a[100005];

struct node{
	ll d[2],ch[2],mina[2],maxa[2];
	bool operator<(const node c)const{return d[D]<c.d[D];}
	void init(){for(int i=0;i<2;i++)mina[i]=maxa[i]=d[i],ch[i]=0;}
}t[100005];

void update(int id){
	for(int i=0;i<2;i++){
		if(t[id].ch[i]){
			for(int j=0;j<2;j++){
				t[id].mina[j]=min(t[id].mina[j],t[t[id].ch[i]].mina[j]);
				t[id].maxa[j]=max(t[id].maxa[j],t[t[id].ch[i]].maxa[j]);
			}
		}
	}
}

int build(int l,int r,int d){
	D=d; int mid=(l+r)/2; nth_element(t+l,t+mid,t+r+1);
	t[mid].init();
	if(l!=mid) t[mid].ch[0]=build(l,mid-1,d^1);
	if(r!=mid) t[mid].ch[1]=build(mid+1,r,d^1);
	update(mid);
	return mid;
}

ll getdis(int id,ll x,ll y){
	if(!id) return 1ll<<60;
	if(x<=t[id].maxa[0]&&x>=t[id].mina[0]&&y<=t[id].maxa[1]&&y>=t[id].mina[1]) return 0;
	return min((t[id].mina[0]-x)*(t[id].mina[0]-x),(x-t[id].maxa[0])*(x-t[id].maxa[0]))+min((t[id].mina[1]-y)*(t[id].mina[1]-y),(y-t[id].maxa[1])*(y-t[id].maxa[1]));
}

ll dist(ll x1,ll y1,ll x2,ll y2){return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);}

void query(int id,ll x,ll y){
	if(!id) return;
	if(t[id].d[0]!=x||t[id].d[1]!=y) ans=min(ans,dist(t[id].d[0],t[id].d[1],x,y));
	ll dl=getdis(t[id].ch[0],x,y),dr=getdis(t[id].ch[1],x,y);
	if(dl<dr){
		if(dl<ans) query(t[id].ch[0],x,y);
		if(dr<ans) query(t[id].ch[1],x,y);
	}
	else{
		if(dr<ans) query(t[id].ch[1],x,y);
		if(dl<ans) query(t[id].ch[0],x,y);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint()+a[i-1];
	for(int i=1;i<=n;i++) t[i].d[0]=i,t[i].d[1]=a[i];
	rt=build(1,n,0);
	ans=1ll<<60;
	for(int i=1;i<=n;i++) query(rt,i,a[i]);
	cout<<ans<<endl;
	return 0;
}