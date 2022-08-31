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
typedef long double ld;
 
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
 
int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
 
int n,m,q,cnt;
int c[5005][10005];
 
void chn(int x,int y,int ch){
	for(;x<=n;x+=(x&(-x))) for(int t=y;t<=m;t+=(t&(-t))) c[x][t]+=ch;
}
 
void add(int x1,int y1,int x2,int y2,int ch){
	if(x1>x2||y1>y2) return;
	chn(x2+1,y2+1,ch);
	chn(x1,y2+1,-ch);
	chn(x2+1,y1,-ch);
	chn(x1,y1,ch);
}
 
int ask(int x,int y){
	int ret=0;
	for(;x;x-=(x&(-x))) for(int t=y;t;t-=(t&(-t))) ret+=c[x][t];
	return ret;
}
 
struct node{
	int x1,y1,x2,y2,ch,tp;
	node(int x1=0,int y1=0,int x2=0,int y2=0,int ch=0,int tp=0):x1(x1),y1(y1),x2(x2),y2(y2),ch(ch),tp(tp){}
};
 
int ans[100005];
queue<node> t[5];
 
//0: (x,y) 1: (x,x-y+n) 2: (y,x-y+n) 3: (x,x+y-1) 4: (y,x+y-1) 
int main(){
	memset(c,0,sizeof(c));
	n=readint(); q=readint();
	m=n+n-1;
	int opt,x,y,z,w;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			z=readint(); w=readint();
			if(x==1){
				t[0].push(node(y,z,n,n,1,1));
				t[4].push(node(1,y+z+w,n,n+n-1,-1,1));
				t[4].push(node(1,y+z+w,z-1,n+n-1,1,1));
				t[3].push(node(1,y+z+w,y-1,n+n-1,1,1));
			}
			else if(x==2){
				t[0].push(node(y,1,n,z,1,1));
				t[2].push(node(1,y-z+w+n+1,n,n+n-1,-1,1));
				t[2].push(node(z+1,y-z+w+n+1,n,n+n-1,1,1));
				t[1].push(node(1,y-z+w+n+1,y-1,n+n-1,1,1));
			}
			else if(x==3){
				t[0].push(node(1,z,y,n,1,1));
				t[2].push(node(1,1,n,y-z-w+n-1,-1,1));
				t[2].push(node(1,1,z-1,y-z-w+n-1,1,1));
				t[1].push(node(y+1,1,n,y-z-w+n-1,1,1));
			}
			else{
				t[0].push(node(1,1,y,z,1,1));
				t[4].push(node(1,1,n,y+z-w-2,-1,1));
				t[4].push(node(z+1,1,n,y+z-w-2,1,1));
				t[3].push(node(y+1,1,n,y+z-w-2,1,1));
			}
		}
		else{
			cnt++;
			t[0].push(node(x,y,0,0,cnt,2));
			t[1].push(node(x,x-y+n,0,0,cnt,2));
			t[2].push(node(y,x-y+n,0,0,cnt,2));
			t[3].push(node(x,x+y-1,0,0,cnt,2));
			t[4].push(node(y,x+y-1,0,0,cnt,2));
		}
	}
	for(int i=0;i<5;i++){
		while(!t[i].empty()){
			node x=t[i].front(); t[i].pop();
			if(x.tp==1) add(x.x1,x.y1,x.x2,x.y2,x.ch);
			else ans[x.ch]+=ask(x.x1,x.y1);
		}
		if(i<4) memset(c,0,sizeof(c));
	}
	for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
	return 0;
}