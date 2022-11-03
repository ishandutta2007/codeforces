#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,fa[200010],ch[200010][2],siz[200010],_siz[200010],W[200010],MX[200010];
bool rev[200010];
bool isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void upd(int x){
	if(!x)return;
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+(x<=n)+_siz[x];
	MX[x]=x;
	if(W[MX[ch[x][0]]]>W[MX[x]])MX[x]=MX[ch[x][0]];
	if(W[MX[ch[x][1]]]>W[MX[x]])MX[x]=MX[ch[x][1]];
}
void Rev(int x){if(x)rev[x]^=1,std::swap(ch[x][0],ch[x][1]);}
void down(int x){if(x&&rev[x])Rev(ch[x][0]),Rev(ch[x][1]),rev[x]=0;}
void rotate(int x){
	int y=fa[x],z=fa[y],o=x==ch[y][1];
	fa[x]=z;if(!isrt(y))ch[z][y==ch[z][1]]=x;
	ch[y][o]=ch[x][!o],fa[ch[x][!o]]=y;
	fa[y]=x,ch[x][!o]=y;
	upd(y);
}
void Down(int x){if(!x)return;if(!isrt(x))Down(fa[x]);down(x);}
void splay(int x){
	Down(x);
	int y,z;
	while(!isrt(x)){
		y=fa[x],z=fa[y];
		if(!isrt(y))rotate(((x==ch[y][0])^(y==ch[z][0]))?x:y);
		rotate(x);
	}
	upd(x);
}
void access(int x){for(int y=0;x;x=fa[y=x])splay(x),_siz[x]-=siz[y]-siz[ch[x][1]],ch[x][1]=y,upd(x);}
int find(int x){access(x);splay(x);while(ch[x][0])down(x),x=ch[x][0];return splay(x),x;}
void makert(int x){access(x),splay(x),Rev(x);}
void link(int x,int y){makert(x),makert(y);fa[x]=y,_siz[y]+=siz[x],upd(x);}
void cut(int x,int y){makert(x),access(y),splay(y),fa[x]=ch[y][0]=0;upd(y);}
std::priority_queue<std::pair<int,int>>E,del;
int eA[200010],eB[200010],stk[100010],tp;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();int m=gi(),a,b,c,cp=n;
	for(int i=1;i<=n;++i)siz[i]=1,MX[i]=i;
	for(int i=1;i<n;++i)stk[++tp]=i+n;
	while(m--){
		a=gi(),b=gi(),c=gi();
		if(find(a)!=find(b)){
			int x=stk[tp--];
			W[x]=c;siz[x]=_siz[x]=0;
			makert(a),makert(b);
			cp-=(siz[a]&1)+(siz[b]&1)-(siz[a]+siz[b]&1);
			link(eA[x]=a,x),link(eB[x]=b,x);
			E.push({c,x});
		}else{
			makert(a),access(b),splay(b);
			int p=MX[b];
			if(W[p]>c){
				cut(p,eA[p]);cut(p,eB[p]);
				del.push({W[p],p});
				W[p]=c;
				link(p,eA[p]=a),link(p,eB[p]=b);
				E.push({W[p],p});
			}
		}
		if(cp)puts("-1");
		else{
			while(1){
				while(!E.empty()&&!del.empty()&&E.top()==del.top())E.pop(),del.pop();
				int x=E.top().second;a=eA[x],b=eB[x];
				cut(x,a),cut(x,b);
				makert(a);
				if(siz[a]&1){link(x,a),link(x,b);break;}
				E.pop();stk[++tp]=x;
			}
			printf("%d\n",E.top().first);
		}
	}
	return 0;
}