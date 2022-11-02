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

int now;
struct Node{
	Node(){
		next[0]=next[1]=prev=shorten=0;
		used=0;
		terminal=-1;
	}
	int used;
	int terminal;
	Node* next[2];
	Node* prev;
	Node* shorten;
};

int n;
string s[777];
Node* root;

bool u[777][777];
int wm[777];
int mw[777];
bool v[777];

bool dfs(int ver){
	if(ver<0)  return 1;
	if(v[ver]) return 0;
	v[ver]=1;
	REP(i,n)if(u[ver][i])
		if(dfs(wm[i])) return mw[ver]=i,wm[i]=ver,1;
	return 0;
}

int maxpar(){
	CL(wm,-1);
	CL(mw,-1);
	int res = 0;
	REP(i,n){
		CL(v,0);
		if(dfs(i)) res++;
	}
	return res;
}

void process(Node* curr, int g){	
	if(curr==root || !curr)return;
	if(curr->used==now) return;
	curr->used=now;
	process(curr->shorten, g);
	if (curr->terminal!=-1){
		if(curr->terminal!=g)u[g][curr->terminal]=1;
	}
}

void go(Node* root){
	REP(i,n){
		now++;
		Node* curr = root;
		REP(j,s[i].size()){
			curr = curr->next[s[i][j]-'a'];
			process(curr, i);
		}
	}
}

bool qq[777];
bool tt[777];

void dfs2(int ver){
	if(qq[ver])return;
	qq[ver]=1;
	REP(i,n)if(u[ver][i]){
		tt[i]=1;
		dfs2(wm[i]);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	getline(cin,s[0]);
	REP(i,n){
		getline(cin,s[i]);
		//cout<<"|"<<s[i]<<"|"<<endl;
//		if(i>=8)while(s[i].size()<i+5000000)s[i].pb('a');
	}
	CL(u,0);
	root=new Node();
	root->prev=root;
	REP(i,n){
		Node* curr = root;
		REP(j,s[i].size()){
			int tt = s[i][j]-'a';
			//cout<<tt<<endl;
			if(curr->next[tt] == 0) curr->next[s[i][j]-'a'] = new Node();
			curr = curr->next[s[i][j]-'a'];
		}
		curr->terminal=i;
	}

	queue<pair<Node*,Node*>> q;
	q.push(make_pair(root,nullptr));
	while(!q.empty()){
		Node* curr = q.front().first;
		Node* par = q.front().second;
		q.pop();

		if (curr->next[0]) q.push(make_pair(curr->next[0], curr));
		if (curr->next[1]) q.push(make_pair(curr->next[1], curr));

		if(par) {
			int d = (par->next[0] == curr) ? 0 : 1;
			par = par->prev;
			if(!par)par=root;
			while (par){
				if (par->next[d]) {
					par=par->next[d];
					break;
				}				
				if (par == root) break;
				par = par->prev;
			}
			curr->prev = par == curr ? root : par;
		}
	}
	queue<Node*> q2;
	q2.push(root);
	while(!q2.empty()){
		Node* curr = q2.front();
		q2.pop();

		if (curr->next[0]) q2.push(curr->next[0]);
		if (curr->next[1]) q2.push(curr->next[1]);
		curr->shorten = curr->prev;
		while(curr->shorten && curr->shorten != root && curr->shorten->terminal==-1){
			curr->shorten = curr->shorten->shorten;
		}
	}

	go(root);

	cout<<n-maxpar()<<endl;

	REP(i,n)if(mw[i]==-1)dfs2(i);

	bool f = 1;
	REP(i,n)if(qq[i] && !tt[i]){
		if(!f)printf(" ");
		printf("%d",i+1);
		f=0;
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}