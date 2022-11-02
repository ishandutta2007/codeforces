#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

bool OUTPUT_TO_FILE = 0;

double v[333333];

struct Node{
	int l,r;
	double sum,mx,endsWith,startsWith;
	Node *lf;
	Node *rg;
	Node(){l=r=0;lf=rg=0;sum=mx=startsWith=endsWith=0;}
};

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
		
		curr->sum = curr->lf->sum + curr->rg->sum;
		curr->mx  = max(curr->lf->mx, curr->rg->mx);
		curr->mx = max(curr->mx, curr->lf->endsWith + curr->rg->startsWith);

		curr->endsWith = max(curr->rg->endsWith, curr->rg->sum + curr->lf->endsWith);
		curr->startsWith = max(curr->lf->startsWith, curr->lf->sum + curr->rg->startsWith);


	}else{
		curr->sum = v[l]; 
		curr->mx = max(0., v[l]);
		curr->endsWith = curr->mx;
		curr->startsWith = curr->mx;
	}
	return curr;
}

double getMaxEnds(Node *curr,int l){
	if(l<=curr->l) return curr->endsWith;
	if(l>curr->r) return 0;

	double val = getMaxEnds(curr->rg, l);
	if(l <= curr->rg->l)
		val = max(val, getMaxEnds(curr->lf, l) + curr->rg->sum);
	return val;
}


double getMaxStarts(Node *curr,int r){
	if(r>=curr->r) return curr->startsWith;
	if(r<curr->l) return 0;

	double val = getMaxStarts(curr->lf, r);
	if(r >= curr->lf->r)
		val = max(val, getMaxStarts(curr->rg, r) + curr->lf->sum);
	return val;
}

double getMax(Node *curr, int l,int r){
	if(curr->l > r || curr->r < l) return 0;
	if(l <= curr->l && curr->r <= r) return curr->mx;

	double val = 0;
	val = max(val, getMax(curr->lf, l, r));
	val = max(val, getMax(curr->rg, l, r));

	if(r>=curr->rg->l && l<=curr->lf->r){
		val = max(val, getMaxEnds(curr->lf, l) + getMaxStarts(curr->rg, r));
	}

	return val;

}

int n,m,c;
int x[333333];
int p[333333];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>c;
	REP(i,n) scanf("%d",x+i);
	REP(i,n-1){
		scanf("%d",p+i);
		v[i] = (x[i+1]-x[i])/2. - p[i]/100.*c;
	}
	Node *root = buildTree(0,n-2);
	double res = 0;
	REP(i,m){
		int X,Y;
		scanf("%d %d",&X,&Y);
		res += getMax(root, X-1,Y-2);
	}
	printf("%.10lf\n",res);
	
#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}