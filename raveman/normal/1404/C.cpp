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
typedef pair<int,pii>	p3;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,q;
int a[333333];
int b[333333];
p3  Q[333333];
int r[333333];

int s[1<<20];
void add(int pos){
	pos+=(1<<19);
	while(pos){
		s[pos]++;
		pos>>=1;
	}
}
int getsum(int p2){
	int p1=(1<<19);
	p2=(1<<19)+p2;
	int res=0;
	while(p1<=p2){
		if(p1&1)res+=s[p1];
		if(!(p2&1))res+=s[p2];
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return res;
}

struct Node{
	Node(){
		lf=0;
		rg=0;
		l=r=0;
		subtract=0;
		bestval=1000000000;
	}
	int subtract;
	int bestval;

	int l,r;
	Node* lf;
	Node* rg;
};

Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l=l;
	curr->r=r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
	}
	return curr;
}

void updateVal(Node* curr,int pos,int val){
	if(pos<curr->l || pos>curr->r)return;
	if(curr->l==curr->r){
		curr->bestval = val - curr->subtract;
	}else{
		updateVal(curr->lf, pos,val);
		updateVal(curr->rg, pos,val);
		curr->bestval = min(curr->lf->bestval, curr->rg->bestval) - curr->subtract;
	}
}
void subtractOne(Node* curr,int pos){
	//cout<<"!"<<pos<<endl;
	if(pos>curr->r)return;
	if(pos<=curr->l){
		curr->subtract++;
		curr->bestval--;
		return;
	}
	subtractOne(curr->lf,pos);
	subtractOne(curr->rg,pos);
	curr->bestval = min(curr->lf->bestval, curr->rg->bestval) - curr->subtract;

	//cout<<curr->l<<" "<<curr->r<<" = "<<curr->bestval<<endl;
}

int getNonPos(Node* curr,int threshold=0){
	//cout<<"gnp "<<threshold<<" "<<curr->bestval<<endl;
	if(curr->bestval > threshold)return -1;
	if(curr->l == curr->r) return curr->l;
	threshold+=curr->subtract;
	if(curr->lf->bestval<=threshold)return getNonPos(curr->lf,threshold);
	return getNonPos(curr->rg,threshold);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n)scanf("%d",a+i),a[i]--;

	REP(i,n){
		b[i] = i - a[i];
		if(b[i]<0)b[i]=1000000000;
	}
	//REP(i,n)cout<<b[i]<<' ';puts("");
	REP(i,q)	scanf("%d %d",&Q[i].first,&Q[i].second.first),Q[i].second.second=i;
	sort(Q,Q+q);
	int pos = q-1;
	Node* root = buildTree(0,n-1);
	for(int i=n-1;i>=0;i--){
		if(b[i]==0){
			int rp = i;
			while(rp!=-1){
				add(rp);
				subtractOne(root,rp);
				//cout<<"sb "<<rp<<endl;
				updateVal(root,rp,1000000000);
				rp=getNonPos(root);
				//cout<<"rp "<<rp<<endl;
			}
		}else{
			updateVal(root,i,b[i]);
		}

		while(pos>=0 && Q[pos].first==i){
			r[Q[pos].second.second]=getsum(n-Q[pos].second.first-1);
			pos--;
		}
	}
	REP(i,q)printf("%d\n",r[i]);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}