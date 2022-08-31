#include<bits/stdc++.h>

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

struct node{
	int x,be,pre,opt;
	node(int xx=0,int bb=0,int pp=0,int oo=0):x(xx),be(bb),pre(pp),opt(oo){}
}q[1000005];

int st,en,cys;
vector<int> ans;
map<int,int> vis[2];

int mod(int x){return x>=cys?x-cys:x;}

int qpow(int x,int p){
	int ret=1;
	for(;p;p>>=1,x=1ll*x*x%cys) if(p&1) ret=1ll*ret*x%cys;
	return ret;
}

void getans0(int x){
	if(q[x].opt==-1) return;
	getans0(q[x].pre);
	ans.push_back(q[x].opt);
}

void getans1(int x){
	if(q[x].opt==-1) return;
	ans.push_back(q[x].opt);
	getans1(q[x].pre);
}

int main(){
	st=readint(),en=readint(),cys=readint();
	int front=0,rear=0;
	q[rear++]=node(st,0,-1,-1),q[rear++]=node(en,1,-1,-1);
	vis[0][st]=0,vis[1][en]=1;
	while(front<rear){
		node t=q[front++];
		for(int i=1;i<=3;i++){
			node tmp=node(0,t.be,front-1,i);
			if(i==1) tmp.x=t.be==0?mod(t.x+1):mod(t.x+cys-1);
			else if(i==2) tmp.x=t.be==0?mod(t.x+cys-1):mod(t.x+1);
			else tmp.x=qpow(t.x,cys-2);
			if(vis[tmp.be][tmp.x]) continue;
			if(vis[tmp.be^1].count(tmp.x)){
				if(tmp.be==0) getans0(front-1),ans.push_back(i),getans1(vis[tmp.be^1][tmp.x]);
				else getans0(vis[tmp.be^1][tmp.x]),ans.push_back(i),getans1(front-1);
				printf("%d\n",ans.size());
				for(auto pt:ans) printf("%d ",pt);
				printf("\n");
				return 0;
			}
			vis[tmp.be][tmp.x]=rear;
			q[rear++]=node(tmp);
		}
	}
	return 0;
}