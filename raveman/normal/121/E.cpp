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
int a[111111];
char s[11];

int d[31],cnt;
void go(int c){
	if(c) d[cnt++]=c;
	if(c<=1000){
		go(c*10+4);
		go(c*10+7);
	}
}

struct Node{
	int val;
	int l,r;
	int mn;
	int cnt;
	int frst;
	Node *ln;
	Node *rn;
	Node(){ln=rn=0;val=0;}
};


void update(Node *curr){
	curr->mn = min(curr->ln->mn-curr->ln->val, curr->rn->mn-curr->rn->val);
	curr->cnt = 0;
	if(curr->mn == curr->ln->mn - curr->ln->val) curr->cnt += curr->ln->cnt;
	if(curr->mn == curr->rn->mn - curr->rn->val) curr->cnt += curr->rn->cnt;
	if(curr->mn == curr->ln->mn - curr->ln->val) curr->frst = curr->ln->frst;
	else curr->frst = curr->rn->frst;
}

void add(Node *root, int l,int r,int d){
	if(root->r < l || root->l > r) return;
	if(root->l >= l && root->r <= r){
		root->val += d;
	}else{
		add(root->ln, l, r, d);
		add(root->rn, l, r, d);
		update(root);
	}
}

const int inf = 1000000000;

typedef pair<int,pii> p3;

p3 getMin(Node *root,int l,int r){
	if(root->r < l || root->l > r) return p3(inf,pii(0,0)); 
	if(l <= root->l && root->r <= r) return p3(root->mn - root->val, pii(root->frst, root->cnt));
	else{
		if(root->val){
			root->ln->val += root->val;
			root->rn->val += root->val;
			root->val=0;
		}
		update(root);
		
		p3 v1 = getMin(root->ln, l, r);
		p3 v2 = getMin(root->rn, l, r);

		p3 res;
		res.first = min(v1.first,v2.first);
		if(res.first == v2.first) res.second.first = v2.second.first, res.second.second += v2.second.second;
		if(res.first == v1.first) res.second.first = v1.second.first, res.second.second += v1.second.second;
		
		return res;
	}
}

void setVal(Node *root,int pos, int val){
	if(root->r < pos || root->l > pos) return; 
	if(root->l == pos && root->r == pos){
		root->val = 0;
		root->mn = val;
	}else{
		if(root->val){
			root->ln->val += root->val;
			root->rn->val += root->val;
			root->val=0;
		}
		setVal(root->ln, pos, val);
		setVal(root->rn, pos, val);
		update(root);
	}
}


Node *root;

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l, curr->r = r;
	if(l==r){
		curr->val = 0;
		curr->mn = d[lower_bound(d,d+30,a[l])-d]-a[l];
		curr->cnt = 1;
		curr->frst = l;
	}else{
		curr->ln = buildTree(l, (r+l)/2);
		curr->rn = buildTree((r+l)/2+1,r);
		update(curr);
	}
	return curr;
}

void out(Node *root){
	if(root->l!=root->r){
		out(root->ln);
		out(root->rn);
	}
	cout<<root->l<<' '<<root->r<<' '<<root->mn<<' '<<root->val<<' '<<root->cnt<<' '<<root->frst<<endl;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	d[30] = 1000000000;
	go(0);
	sort(d,d+30);
	cin>>n>>m;
	REP(i,n) scanf("%d",a+i);

	root = buildTree(0,n-1);

	REP(i,m){
		int l,r;
		scanf(" %s %d %d",s,&l,&r);
		l--,r--;
		if(s[0]=='c'){
			while(1){
				p3 val = getMin(root, l, r);
				//cout<<val.first<<' '<<val.second.first<<' '<<val.second.second<<endl;    
				if(val.first<0){
					int t = d[lower_bound(d,d+30,a[val.second.first])-d] - val.first;
					a[val.second.first] = t;
					t = d[lower_bound(d,d+30,t)-d] - t;
					setVal(root, val.second.first, t);
					//puts("after2");
					//out(root);
				}else if(val.first==0){
					printf("%d\n",val.second.second);
					break;
				}else{
					puts("0");
					break;
				}
			}
		}else if(s[0]=='a'){
			int d;
			scanf("%d",&d);
			//out(root);
			add(root, l, r, d);
			//puts("after");
			//out(root)
		}
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}