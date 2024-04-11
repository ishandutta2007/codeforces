#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
class Node_t {
public:
	Node_t *l, *r, *p, *u,*par;
	bool rev;
	pii idx;
	Node_t() :l(NULL), r(NULL), p(NULL), u(NULL), par(NULL), rev(false){}
	Node_t* find(){
		if(par==NULL)return this;
		else return par=par->find();
	}
	void push(){
		if(!rev)return;
		swap(l,r);
		if(l)l->rev=!l->rev;
		if(r)r->rev=!r->rev;
		rev=false;
	}
};
typedef Node_t* Np;
Np& L(Np nd) { return nd->l; }
Np& R(Np nd) { return nd->r; }
Np& U(Np nd) {
	if(nd->u)nd->u=nd->u->find();
	return nd->u;
}
template<typename A>
void rot(Np nd, A L, A R) {
	Np p = nd->p; Np g = p->p;
	nd->p = g; if (g) ((L(g) == p) ? L(g) : R(g)) = nd;
	p->p = nd;
	L(p) = R(nd); if (R(nd)) R(nd)->p = p;
	R(nd) = p;
}
void splay(Np nd) {
	while (nd->p) {
		Np p = nd->p;
		if (!(p->p)) {
			p->push();nd->push();
			if (L(p) == nd) rot(nd, L, R);
			else rot(nd, R, L);
		}
		else {
			Np g = p->p;
			g->push();p->push();nd->push();
			if (L(g) == p) {
				if (L(p) == nd) {
					rot(p, L, R); rot(nd, L, R);
				}
				else {
					rot(nd, R, L); rot(nd, L, R);
				}
			}
			else {
				if (R(p) == nd) {
					rot(p, R, L); rot(nd, R, L);
				}
				else {
					rot(nd, L, R); rot(nd, R, L);
				}
			}
		}
	}
	nd->push();
}
template<typename A>
Np getEx(Np a, A R) {
	a->push();
	while (R(a)) {
		a = R(a);
		a->push();
	}
	splay(a);
	return a;
}
Np getMax(Np a) {
	return getEx(a, R);
}
Np getMin(Np a) {
	return getEx(a, L);
}
void cutpc(Np a) {
	splay(a);
	if (R(a)) {
		R(a)->p = NULL;
		U(getMin(R(a))) = a;
		R(a) = NULL;
	}
}
void access(Np a) {
	cutpc(a);
	for (Np it = getMin(a); U(it);) {
		Np u = U(it);
		cutpc(u);
		R(u) = it; it->p = u; U(it) = NULL;
		it = getMin(u);
	}
	splay(a);
}
void toroot(Np u) {
	access(u);
	u->rev = true;
}
void link(Np c, Np p) {
	toroot(c);
	access(c); access(p);
	R(p) = c; c->p = p;
}
void cut(Np v) {
	access(v);
	L(v)->p = NULL;
	L(v) = NULL;
}
void merge(Np u,Np v){
	toroot(v);
	access(v);
	v->par=u;
}
pii Do(Np u,Np v){
	toroot(u);
	access(v);
	splay(u);
	Np nd=getMin(R(u));
	pii ret=nd->idx;
	cut(nd);
	access(v);
	splay(nd);
	nd=getMin(R(nd));
	cut(nd);
	merge(u,v);
	return ret;
}
const int N=252525;
Node_t np[N], ed[N];
vector<int> adj[N];
void dfs(int u,int p=-1){
	for(auto &x:adj[u]){
		if(x==p)continue;
		dfs(x,u);
		pii ret=Do(np[x].find(),np[u].find());
		printf("%d %d %d %d\n",u+1,x+1,ret.first+1,ret.second+1);
	}
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);u--;v--;
		ed[i-1].idx={u,v};
		link(&np[u],&ed[i-1]);
		link(&np[v],&ed[i-1]);
	}
	printf("%d\n",n-1);
	dfs(0);
}