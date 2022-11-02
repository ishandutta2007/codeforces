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
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

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

struct Node{
	int l,r;
	Node* lf;
	Node* rg;
	double d;
	int angle;
	double sumdcos;
	double sumdsin;
	Node(){
		l=r=0;
		lf=rg=0;
		d=1;
		sumdcos=sumdsin=0;
		angle=0;
	}
};

void update(Node* curr){
	curr->sumdcos = curr->lf->sumdcos+curr->rg->sumdcos;
	curr->sumdsin = curr->lf->sumdsin+curr->rg->sumdsin;
}

Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l=l;
	curr->r=r;
	if(l==r){
		curr->d = 1;
		curr->sumdcos = curr->d;
		curr->sumdsin = 0;
	}else{
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
		update(curr);
	}
	return curr;
}
const double MULT = acos(-1.) / 180;

void rotateSingle(Node* curr, int angle){
	double tcs = curr->sumdcos;
	double tss = curr->sumdsin;

	curr->sumdcos = tcs * cos(angle * MULT) - tss * sin(angle * MULT);
	curr->sumdsin = tss * cos(angle * MULT) + tcs * sin(angle * MULT);

	curr->angle += angle;
	while(curr->angle>=360)curr->angle-=360;
}

void push(Node* curr){
	if(curr->angle){
		rotateSingle(curr->lf,curr->angle);
		rotateSingle(curr->rg,curr->angle);
		update(curr);
		curr->angle = 0;
	}
}

void rotateNode(Node* curr, int pos, int angle){
	if (pos <= curr->l) {
		rotateSingle(curr, angle);
		return;
	}
	if (pos > curr->r) return;
	push(curr);
	rotateNode(curr->lf,pos,angle);
	rotateNode(curr->rg,pos,angle);
	update(curr);
}

void increaseLen(Node* curr, int pos, int len){
	if(curr->l == curr->r && curr->l == pos){
		curr->d += len;
		curr->sumdcos = curr->d * cos(curr->angle * MULT);
		curr->sumdsin = curr->d * sin(curr->angle * MULT);
	}else if(curr->l<=pos && pos<=curr->r){
		push(curr);
		increaseLen(curr->lf,pos,len);
		increaseLen(curr->rg,pos,len);
		update(curr);
	}
}
int n,m;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	Node* root = buildTree(0,n-1);
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		y--;
		if(x==1){
			increaseLen(root,y,z); 
		}else{
			rotateNode(root,y,360-z);
		}
		printf("%.10lf %.10lf\n",root->sumdcos,root->sumdsin);
	}


#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}