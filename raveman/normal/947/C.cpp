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

struct Node{
	Node(){
		lf=rg=0;
		sum=0;
	}
	Node* lf;
	Node* rg;
	int sum;
};

int n;
int a[333333];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	Node* root = new Node();
	REP(i,n){
		int x;
		scanf("%d",&x);
		Node* c = root;
		c->sum++;
		for(int j=29;j>=0;j--){
			if (x&(1<<j)){
				if(!c->rg) c->rg=new Node();
				c=c->rg;
			}else{
				if(!c->lf) c->lf=new Node();
				c=c->lf;
			}
			c->sum++;
		}
	}
	REP(i,n){
		int w = a[i];
		Node* c = root;
		c->sum--;
		for(int j=29;j>=0;j--){
			int c2 = w^(1<<j);
			int c1 = w; 
			if ((c1<c2 && c->lf && c->lf->sum) || !c->rg || !c->rg->sum){
				w=c1;
				c=c->lf;
			}else{
				w=c2;
				c=c->rg;
			}
			c->sum--;
		}
		cout<<w<<' ';
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}