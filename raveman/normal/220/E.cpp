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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

struct Node{
	int l,r;
	int num;
	Node *lf;
	Node *rg;
	Node(){
		lf = rg = 0;
		num = 0;
	}
};

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
	}
	return curr;
}

void add(Node *curr,int val,int aaa=1){
	if(curr->l > val) return;
	if(curr->r < val) return;
	curr->num += aaa;
	if(curr->lf){
		add(curr->lf, val, aaa);
		add(curr->rg, val, aaa);
	}
}

int numBigger(Node *curr,int val){
	if(curr->num==0) return 0;
	if(val < curr->l) return curr->num;
	if(curr->r <= val) return 0;
	return numBigger(curr->lf,val)+numBigger(curr->rg,val);
}

int numSmaller(Node *curr,int val){
	if(curr->num==0) return 0;
	if(val <= curr->l) return 0;
	if(curr->r < val) return curr->num;
	return numSmaller(curr->lf,val)+numSmaller(curr->rg,val);
}

Node *root1;
Node *root2;

int n;
ll k;
int a[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	vi v;
	REP(i,n) scanf("%d",a+i),v.pb(a[i]);
	UN(v);
	REP(i,n) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();

	root1 = buildTree(0,100000);
	root2 = buildTree(0,100000);

	ll total = 0;
	for(int i=n-1;i>=0;i--){
		total += numSmaller(root2, a[i]);
		add(root2, a[i]);
	}
	int r = 0;

	ll res = 0;

	int l=0;
	while(l<n){
		if(r<=l){
			total -= numSmaller(root2, a[r]);
			total -= numBigger(root1, a[r]);
			add(root2, a[r], -1);
			r++;
		}
		total += numBigger(root1, a[l]);
		total += numSmaller(root2, a[l]);
		add(root1, a[l], 1);
		l++;

		while(total>k && r<n){
			total -= numSmaller(root2, a[r]);
			total -= numBigger(root1, a[r]);
			add(root2, a[r], -1);
			r++;
		}
		res += (n-r);
	}

	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}