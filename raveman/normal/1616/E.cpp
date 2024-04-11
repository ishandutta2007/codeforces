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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

struct Node{
	int l;
	int r;
	int sum;
	Node* lf;
	Node* rg;
	Node(){
		l=r=0;
		lf=0;
		rg=0;
		sum=0;
	}

	void add(int pos){
		if(pos<l || pos>r)return;
		sum++;
		if(lf)lf->add(pos);
		if(rg)rg->add(pos);
	}
	int get_sum(int from){
		if(r<from)return 0;
		if(from<=l) return sum;
		return lf->get_sum(from)+rg->get_sum(from);
	}
};

Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l, (l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
	}
	return curr;
}

vi v[26];
Node* root;


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	string s,t;

	int tc;
	cin>>tc;

	REP(TC,tc){
		cin>>n;
		getline(cin,s);
		getline(cin,s);
		getline(cin,t);

		root = buildTree(0,n-1);

		REP(i,26)v[i].clear();
		REP(i,s.size())v[s[i]-'a'].pb(i);
		REP(i,26)reverse(v[i].begin(),v[i].end());
		
		ll res = -1;
		ll currsum=0;
		REP(i,s.size()){
			//cout<<i<<": "<<currsum<<endl;
			int CURR = t[i]-'a';
			REP(j,CURR){
				if(v[j].empty()) continue;
				int pos = v[j].back();
				pos += root->get_sum(pos);
				if(res==-1 || res > currsum + pos - i)res=currsum+pos-i;
			}
			if(v[CURR].empty()) break;
			int pos = v[CURR].back();
			v[CURR].pop_back();
			//cout<<"add "<<pos<<endl;
			root->add(pos);
			pos += root->get_sum(pos+1);
			currsum += pos - i;
		}
		cout<<res<<endl;
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}