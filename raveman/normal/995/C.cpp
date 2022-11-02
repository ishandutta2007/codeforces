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

int n;

struct V{
	V(){
		x=y=sign1=sign2=0;
		id=-1;
		next1=next2=0;
	}
	int x,y;
	int id;
	int sign1;
	V* next1;
	int sign2;
	V* next2;
};
vector<V*> v;

int a[111111];

void gomark(V* node,bool w){
	if(node->id!=-1)a[node->id]=(w?1:-1);
	if(node->next1){
		gomark(node->next1,w ^(node->sign1==-1));
	}
	if(node->next2){
		gomark(node->next2,w ^(node->sign2==-1));
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll limit = 1000000;limit *= limit;

	cin>>n;
	REP(i,n){
		int x,y;
		scanf("%d %d",&x,&y);
		V* tmp = new V();
		tmp->x=x;
		tmp->y=y;
		tmp->id=i;

		V* curr = tmp;

		REP(j,v.size()){
			ll x1 = v[j]->x + curr->x;
			ll y1 = v[j]->y + curr->y;
			if (x1*x1+y1*y1<=limit){
				V* nw = new V();
				nw->sign1=1;
				nw->next1=curr;
				nw->sign2=1;
				nw->next2=v[j];
				nw->x = x1;
				nw->y = y1;

				curr = nw;

				swap(v[j],v.back());
				v.pop_back();

				j--;
				continue;
			}
			x1 -= 2 * v[j]->x;
			y1 -= 2 * v[j]->y;

			if (x1*x1 + y1*y1<=limit){
				V* nw = new V();
				nw->sign1=1;
				nw->next1=curr;
				nw->sign2=-1;
				nw->next2=v[j];
				nw->x = x1;
				nw->y = y1;

				curr = nw;

				swap(v[j],v.back());
				v.pop_back();
				j--;
				continue;
			}
		}
		v.pb(curr);
	}
	//cout<<v.size()<<endl;
	int t = v.size();
	REP(i,1<<(t-1)){
		ll sx=0,sy=0;
		REP(j,t){
			if(i&(1<<j))sx+=v[j]->x,sy+=v[j]->y;
			else sx-=v[j]->x,sy-=v[j]->y;
		}
		if(sx*sx + sy*sy <= 2250000000000ll){
			REP(j,t)gomark(v[j],(i&(1<<j)));
			break;
		}
	}

	REP(i,n)printf("%d ",a[i]);puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}