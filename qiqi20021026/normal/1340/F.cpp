#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 100500

const LL B=140,C=123457;
LL n,m,q,a[N],pw[B+5];
bool bad[N];
stack<LL> s;

LL blk(LL x){return x/B;}

struct hash{
	LL n,now,f[B+5];
	hash(){n=now=0; memset(f,0,sizeof f);}
	void clear(){n=now=0; memset(f,0,sizeof f);}
	void push(LL x){
		x=abs(x); ++n;
		f[n]=f[n-1]*C+x;
	}
	LL qry(LL l,LL r){
		return f[r]-f[l-1]*pw[r-l+1];
	}
}L[N],R[N];

void build(LL k){
	L[k].clear(); R[k].clear(); bad[k]=0;
	stack<LL> stk;
	for (LL i=k*B;i<(k+1)*B;++i){
		if (a[i]>0) stk.push(a[i]);
		else{
			if (stk.empty()){
				R[k].push(a[i]);
			}
			else{
				if (stk.top()+a[i]==0) stk.pop();
				else{bad[k]=1; return;}
			}
		}
	}
	for (;!stk.empty();stk.pop()) L[k].push(stk.top());
}

bool eli(LL i){
	while (R[i].now<=R[i].n){
		if (s.empty()) return 0;
		LL j=s.top();
		LL k=min(R[i].n-R[i].now,L[j].n-L[j].now);
		if (R[i].qry(R[i].now,R[i].now+k)!=L[j].qry(L[j].now,L[j].now+k)) return 0;
		R[i].now+=k+1;
		L[j].now+=k+1;
		if (L[j].now>L[j].n) s.pop();
	}
	return 1;
}

bool qry(LL l,LL r){
	stack<LL> stk;
	#define pb(x)\
		if (x>0) stk.push(x);\
		else{\
			if (stk.empty()) return 0;\
			else{\
				if (stk.top()+x==0) stk.pop();\
				else return 0;\
			}\
		}
	LL bl=blk(l),br=blk(r);
	if (bl==br){
		for (LL i=l;i<=r;++i) pb(a[i]);
		return stk.empty();
	}
	for (LL i=l;i<(bl+1)*B;++i) pb(a[i]);
	L[0].clear(); R[m+1].clear();
	for (;!stk.empty();stk.pop()) L[0].push(stk.top());
	for (LL i=r;i>=br*B;--i) pb(-a[i]);
	for (;!stk.empty();stk.pop()) R[m+1].push(stk.top());
	for (LL i=bl+1;i<br;++i){
		if (bad[i]) return 0;
	}
	for (;!s.empty();s.pop());
	L[0].now=1;
	if (L[0].n) s.push(0);
	for (LL i=bl+1;i<br;++i){
		R[i].now=1;
		if (!eli(i)) return 0;
		L[i].now=1;
		if (L[i].n) s.push(i);
	}
	R[m+1].now=1;
	if (!eli(m+1)) return 0;
	return s.empty();
}

int main(){
	scanf("%lld%*d",&n);
	pw[0]=1; for (LL i=1;i<=B;++i) pw[i]=pw[i-1]*C;
	for (LL i=0;i<n;++i) scanf("%lld",a+i);
	m=blk(n-1);
	for (LL i=0;i<=m;++i) build(i);
	scanf("%lld",&q);
	while (q--){
		LL op,x,y; scanf("%lld%lld%lld",&op,&x,&y);
		if (op==1){
			a[--x]=y; build(blk(x));
		}
		else{
			puts(qry(--x,--y)?"Yes":"No");
		}
	}
	
	return 0;
}