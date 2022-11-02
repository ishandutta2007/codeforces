#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int MAX = 300;

struct List{
	List *prev;
	List(){prev=0;maxEl=numEl=0;}
	int a[601];
	int d[601];
	int maxEl;
	int numEl;

	void addEl(int A,int c,int id){
		a[numEl]=A;d[numEl]=id;numEl++;maxEl=max(maxEl,A);
		int pos = numEl-1;
		while(pos && a[pos-1] < a[pos] && c){
			swap(a[pos-1],a[pos]);
			swap(d[pos-1],d[pos]);
			pos--;
			c--;
		}
	}
	List *split(){
		List *nl = new List();
		REP(i,MAX){
			nl->a[i] = a[i];
			nl->d[i] = d[i];
			nl->maxEl = max(nl->maxEl, a[i]);
		}
		nl->numEl = MAX;
		maxEl = 0;
		REP(i,MAX){
			maxEl = max(maxEl, a[i] = a[i+MAX]);
			d[i] = d[i+MAX];
		}
		numEl = MAX;
		return nl;
	}
};

List head;

void add(vi &v, List * a){
	for(int i = a->numEl-1;i>=0;i--)
		v.pb(a->d[i]);
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin>>n;
	REP(i,n){
		int a,c;
		scanf("%d %d",&a,&c);
		List *curr = &head;
		while(1){
			if(curr->prev==0 || curr->maxEl > a || curr->numEl > c){
				curr->addEl(a,c,i+1);
				if(curr->numEl == 2*MAX){
					List *newList = curr->split();
					newList->prev = curr->prev;
					curr->prev = newList;
				}
				break;
			}else c -= curr->numEl, curr=curr->prev;
		}
	}
	vi res;
	List *curr = &head;
	while(1) {add(res,curr);if(curr->prev) curr=curr->prev;else break;}
		
	reverse(all(res));
	REP(i,res.size()){
		if(i) printf(" ");
		printf("%d",res[i]);
	}
	puts("");
	return 0;
}