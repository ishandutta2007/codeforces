#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

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

const int mod = 95542721;

int a[111111];
int n;

struct Node{
	int a[48];
	int l,r,curr;
	Node *lf;
	Node *rg;
	Node(){lf=rg=0;}
};

Node* root;

Node* buildTree(int L,int R){
	Node* curr = new Node();
	curr->l=L;
	curr->r=R;
	curr->curr=0;
	if(L==R){
		ll x = a[L]%mod;
		REP(i,48){
			curr->a[i]=x;
			x= x*x%mod*x%mod;
		}
	}else{
		curr->lf = buildTree(L,(L+R)/2);
		curr->rg = buildTree((L+R)/2+1,R);
		REP(i,48){
			curr->a[i]=curr->lf->a[i]+curr->rg->a[i];
			if(curr->a[i]>=mod) curr->a[i]-=mod;

		}
	}
	return curr;
}

void pushSh(Node *curr,int sh){
	curr->curr+=sh;
	if(curr->curr>=48)curr->curr-=48;
}

void update(Node *curr){	
	REP(i,48){
		int t1 = (curr->lf->curr+i);if(t1>=48)t1-=48;
		int t2 = (curr->rg->curr+i);if(t2>=48)t2-=48;
		curr->a[i] = (curr->lf->a[t1]+curr->rg->a[t2])%mod;
	}
}

int getSum(Node *curr,int L,int R){
	if(curr->l>R) return 0;
	if(curr->r<L) return 0;
	if(L<=curr->l && curr->r<=R) return curr->a[curr->curr];
	else {
		int t = curr->curr;
		if(t){
			curr->curr=0;
			pushSh(curr->lf,t);
			pushSh(curr->rg,t);
		}
		int res = 0;
		res += getSum(curr->lf,L,R);
		res += getSum(curr->rg,L,R);
		if(res>=mod) res-=mod;
		
		update(curr);
		return res;
	}
}

void shiftTree(Node *curr,int L,int R){
	if(curr->l>R) return;
	if(curr->r<L) return;
	if(L<=curr->l && curr->r<=R){
		curr->curr++;
		if(curr->curr==48)curr->curr=0;
		return;
	}else {
		int t = curr->curr;
		if(t){
			curr->curr=0;
			pushSh(curr->lf,t);
			pushSh(curr->rg,t);
		}
		shiftTree(curr->lf,L,R);
		shiftTree(curr->rg,L,R);
		update(curr);
	}
}

int stupid(int t,int l,int r){
	if(t==1){
		int res = 0;
		FOR(i,l,r+1){
			res=(res+a[i])%mod;
		}

		cout<<"ST "<<res<<endl;
		return res;
	}else{
		FOR(i,l,r+1){
			ll x = a[i];
			x=x*x%mod*x%mod;
			a[i]=x;
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	//srand(0);
	cin>>n;
	//n=100000;
	REP(i,n){
		scanf("%d",a+i);
		//a[i]=1000000000-i;
	}
	root = buildTree(0,n-1);
	int q;
	cin>>q;
	//q=100000;
	REP(i,q){
		int t,l,r;
		scanf("%d %d %d",&t,&l,&r);
		//t=rand()%2+1;
		//l=rand()%n+1;
		//r=rand()%n+1;
		//if(l>r)swap(l,r);
		l--,r--;
		int tt = 0;
		if(t==1) printf("%d\n",getSum(root,l,r));
		else shiftTree(root,l,r);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}