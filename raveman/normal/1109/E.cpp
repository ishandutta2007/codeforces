#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int mod;
ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1){
			r*=c;
			r%=mod;
		}
		st>>=1;
		c*=c;c%=mod;
	}
	return r;
}

int n;
int a[100000];
vi p;
vi ptmp;

struct Node{
	Node(){
		lf=0,rg=0;
		sum=0;CL(pp,0);
		other=1;
	}

	Node* lf;
	Node* rg;
	int l,r;
	int other;
	int pp[9];
	int sum;
};

Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l=l;
	curr->r=r;
	if(l==r){
		curr->sum = a[l] % mod;
		REP(i,p.size()){
			while(a[l]%p[i]==0){
				a[l]/=p[i];
				curr->pp[i]++;
			}
		}
	}else{
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
		curr->sum = curr->lf->sum + curr->rg->sum;
		curr->sum %= mod;
	}
	return curr;
}

int getSum(Node* curr,int l,int r){
	if(curr->l > r || curr->r < l) return 0;
	if (l <= curr->l && curr->r <= r){
		return curr->sum;
	}
	ll v = getSum(curr->lf, l,r) + getSum(curr->rg,l,r);
	v %= mod;
	if(curr->other != 1){
		v *= curr->other; v%= mod;
	}
	REP(i,p.size())if(curr->pp[i]) v*=qp(p[i],curr->pp[i]),v%=mod;
	return v;
}

void update(Node* curr){
	if(curr->l==curr->r){
		curr->sum = a[curr->l] * ll(curr->other) % mod;
	}else{
		curr->sum = (curr->lf->sum + curr->rg->sum) * ll(curr->other) % mod;
	}
	REP(i,p.size()) curr->sum = curr->sum * qp(p[i],curr->pp[i]) % mod;
}

void mul(Node* curr, int l, int r,int other,const vi& ptmp,int fx){
	if(curr->l > r || curr->r < l) return;
	if(l<=curr->l && curr->r<=r){
		curr->other = curr->other * ll(other) % mod;
		REP(i,ptmp.size()) curr->pp[i] += ptmp[i];
		curr->sum = curr->sum * ll(fx) % mod;
	}else{
		mul(curr->lf, l,r,other,ptmp,fx);
		mul(curr->rg, l,r,other,ptmp,fx);

		update(curr);
	}
}

void push(Node* curr){
	REP(i,p.size()){
		curr->lf->pp[i] += curr->pp[i];
		curr->rg->pp[i] += curr->pp[i];
		curr->pp[i] = 0;
	}
	update(curr->lf);
	update(curr->rg);
	update(curr);
}

void divide(Node* curr,int pos,int fx,const vi& ptmp){
	if(curr->l > pos || curr->r < pos) return;
	if(curr->l==curr->r){
		REP(i,p.size())curr->pp[i] -= ptmp[i];
		curr->other = curr->other * ll(fx) % mod;
		update(curr);
	}else{
		push(curr);
		divide(curr->lf,pos,fx,ptmp);
		divide(curr->rg,pos,fx,ptmp);
		update(curr);
	}
}



int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>mod;
	REP(i,n)scanf("%d",a+i);

	int tmod=mod;
	int ef = 1;
	for(int i=2;i*i<=tmod;i++)
		if(tmod%i==0){
			p.pb(i);
			int tmp=1;
			while(tmod%i==0)tmod/=i,tmp*=i;
			ef *= tmp/i*(i-1);
		}
	if(tmod>1)p.pb(tmod),ef*=(tmod-1);

	Node* root = buildTree(0,n-1);

	int q,t,l,r,x,pos;
	cin>>q;
	REP(i,q){
		scanf("%d",&t);
		if(t==1){
			scanf("%d %d %d",&l,&r,&x);
			l--,r--;
			int fx = x;
			ptmp.clear();
			ptmp.resize(p.size());
			REP(j,p.size())while(x%p[j]==0)x/=p[j],ptmp[j]++;
			mul(root,l,r,x,ptmp,fx);
		}else if(t==2){
			scanf("%d %d",&pos,&x);
			pos--;

			ptmp.clear();
			ptmp.resize(p.size());
			REP(j,p.size())while(x%p[j]==0)x/=p[j],ptmp[j]++;

			int fx = qp(x, ef-1);

			//cout<<x<<' '<<ef<<' '<<fx<<endl;

			divide(root,pos,fx,ptmp);
		}else if(t==3){
			scanf("%d %d",&l,&r);
			l--,r--;
			printf("%d\n",getSum(root,l,r));
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}