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

int n,m;
char s[1111111];
char t[11];

struct Node{
	int l,r;
	Node *lf;
	Node *rg;
	int n4,n7;
	int inc,dec;
	bool hasinverse;
	Node(){lf=rg=0;inc=dec=n4=n7=0;hasinverse=0;}
};

int getN4(Node *curr){
	return 	curr->hasinverse? curr->n7: curr->n4;
}
int getN7(Node *curr){
	return 	curr->hasinverse? curr->n4: curr->n7;
}

int getInc(Node *curr){
	return 	curr->hasinverse? curr->dec: curr->inc;
}

int getDec(Node *curr){
	return 	curr->hasinverse? curr->inc: curr->dec;
}
void update(Node *curr){
	curr->n4 = getN4(curr->lf) + getN4(curr->rg);
	curr->n7 = getN7(curr->lf) + getN7(curr->rg);
	
	curr->inc = max(getN4(curr->lf) + getInc(curr->rg), getInc(curr->lf) + getN7(curr->rg));
	curr->dec = max(getN7(curr->lf) + getDec(curr->rg), getDec(curr->lf) + getN4(curr->rg));
}

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree(1+(l+r)/2,r);
		update(curr);
	}else{
		if(s[l]=='4') curr->n4++;
		else curr->n7++;
		curr->inc = curr->dec = 1;
	}
	return curr;
}

int solve(Node *root){
	return getInc(root);
}

void inverse(Node *root,int x,int y){
	if(root->l > y) return;
	if(root->r < x) return;
	//cout<<"inv "<<x<<' '<<y<<endl;
	if(root->l >= x && root->r <= y){
		//swap(root->n4, root->n7);
		//puts("her1");
		root->hasinverse^=1;
		
		//cout<<root->l<<' '<<root->r<<' '<<getN4(root)<<' '<<getN7(root)<<' '<<getInc(root)<<' '<<getDec(root)<<' '<<root->hasinverse<<endl;
	}else{
		//puts("her2");
		if(root->hasinverse){
			root->hasinverse = false;
			inverse(root->lf, root->lf->l,root->lf->r);
			inverse(root->rg, root->rg->l,root->rg->r);

			update(root);
		}
		inverse(root->lf,x,y);
		inverse(root->rg,x,y);

		update(root);

		//cout<<root->l<<' '<<root->r<<' '<<getN4(root)<<' '<<getN7(root)<<' '<<getInc(root)<<' '<<getDec(root)<<' '<<root->hasinverse<<endl;
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m;
	gets(s);gets(s);
	Node *root = buildTree(0,n-1);
	REP(i,m){
		scanf(" %s",t);
		if(t[0]=='c'){
			printf("%d\n",solve(root));
		}else{
			int x,y;
			scanf("%d %d",&x,&y);
			inverse(root,x-1,y-1);
		}
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}