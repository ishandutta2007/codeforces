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

struct S{
	vi v;
	ll s[5];
	S* next;
	S(){
		next=0;
		REP(i,5) s[i]=0;
	}
	void remove(int x){
		REP(i,v.size()) if(v[i]==x){
			v.erase(v.begin()+i);			
			return;
		}
	}
	void add(int x){
		REP(i,v.size()) if(v[i]>x){
			v.insert(v.begin()+i,x);
			return;
		}
		v.pb(x);
		
	}
	void recalc(){
		REP(i,5) s[i]=0;
		REP(i,v.size()) s[i%5] += v[i];
	}
};


int n;
char s[10];

S *head;

void add(int x){
	S *curr = head;
	while(curr){
		if(curr->next == 0 || curr->next->v.size() && curr->next->v[0] > x || curr->v.size() && curr->v[0] <= x && curr->v.back() >= x){
			curr->add(x);
			
			if(curr->v.size() > 444){
				S *nw = new S();
				FOR(i,222,curr->v.size())
					nw->v.pb(curr->v[i]);
				nw->recalc();
				nw->next = curr->next;
				curr->next = nw;
				curr->v.resize(222);	
			}

			curr->recalc();
			return;
		}
		curr = curr->next;
	}
}

void rem(int x){
	S *curr = head;
	while(curr){
		if(curr->v.size() && curr->v[0] <= x && curr->v.back() >= x){
			curr->remove(x);
			curr->recalc();
			break;
		}
		curr = curr->next;
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	head = new S();

	cin>>n;
	REP(i,n){
		scanf(" %s",s);
		if(s[0]=='s'){
			ll res = 0;
			S *curr = head;
			int now = 0;
			while(curr){
				res += curr->s[((2 - now)%5+5)%5];
				now += curr->v.size();
				curr = curr->next;
			}
			printf("%I64d\n",res);
			
		}else if(s[0]=='a'){
			int x;
			scanf("%d",&x);
			add(x);
		}else if(s[0]=='d'){
			int x;
			scanf("%d",&x);
			rem(x);
		}
	}

	return 0;
}