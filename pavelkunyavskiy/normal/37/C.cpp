#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

struct node{
	node *l,*r;
	int num;
	node(node* L,node* R){
		l=L;
		r=R;
	}
	node(node* L){
		l=L;
		r=0;
	}
	node(){
		l=r=0;
	}
};

vector<node*> a[1010];

string s;
string ans[1010];

void print(node* v){
	if (!v->l && !v->r){
		ans[v->num]=s;
		return;
	}	
	s=s+'0';
	if (v->l)
		print(v->l);
	s[s.size()-1]='1';
	if (v->r)	
		print(v->r);
	s.erase(--s.end());
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		node* tmp=new node();
		tmp->num=i;
		a[l].pb(tmp);
	}	
	for (int i=1002;i>0;i--){
		int sz=a[i].size();
		for (;sz>=2;sz-=2)
			a[i-1].pb(new node(a[i][sz-1],a[i][sz-2]));
		if (sz)
			a[i-1].pb(new node(a[i][0]));		
	}
	if (a[0].size()>1){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	print(a[0][0]);
	for (int i=0;i<n;i++)
		puts(ans[i].data());		
    return 0;
}