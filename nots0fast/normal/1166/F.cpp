#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX (int)(2*pow(10,5)+10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
const char nl = '\n';
ll modulo = pow(10,9)+7;
// 2 maps :
// from individuals to components
// from components to individuals

namespace dsu{
	int aid[MAX];
	vector<int>  dsu[MAX];
	set<int>* 	 cmp[MAX]; // from components to individuals
	map<int,int> all[MAX]; // from individuals to individuals ( their components is important )
	void ini(int n){
		fori(n)
			aid[i] = i, dsu[i].push_back(i), cmp[i] = new set<int> ();
	}
	bool join(int a,int b){ // 1 if joined, 0 otherwise
		int aid1 = aid[a], aid2 = aid[b];
		if(aid1==aid2)
			return 0;
		if(dsu[aid2].size() > dsu[aid1].size())
			swap(aid1, aid2);	
		for(auto hd : dsu[aid2]){
			aid[hd] = aid1;
			dsu[aid1].push_back(hd);
		}
		if(cmp[aid2]->size() > cmp[aid1]->size())
			swap(cmp[aid1], cmp[aid2]);
		for(auto ind : *cmp[aid2])
			(*cmp[aid1]).insert(ind);
		return 1;
	}
	void add_edge(int a,int b, int c){
		(*cmp[aid[a]]).insert(b);
		(*cmp[aid[b]]).insert(a);
		if(all[a].find(c) != all[a].end()){
			int wh = all[a][c];
			int wh1 = b;
			join(wh, wh1);
		}
		else
			all[a][c] = b;
		if(all[b].find(c) != all[b].end()){
			int wh = all[b][c];
			int wh1 = a;
			join(wh,wh1);
		}
		else
			all[b][c] = a;	
	}
};

void deal(){
	int n,m,c,q;
	cin>>n>>m>>c>>q;
	dsu::ini(n);
	fori(m){
		int x,y,z;
		cin>>x>>y>>z; --x,--y;
	//	cout<<"we gon "<<endl;
		dsu::add_edge(x,y,z);
	//	dsu::display(n);
	//	cout<<"we did"<<endl;
	}
	fori(q){
		char f;
		cin>>f;
		if(f == '?'){
			int x,y;
			cin>>x>>y; --x,--y;
		//	cout<<" bruh "<<x<<" "<<y<<endl;
			int aid1 = dsu::aid[x];
		//	cout<<x<<" "<<aid1<<endl;
			if(dsu::aid[x] == dsu::aid[y] ||  (dsu::cmp[aid1])->find(y)!=(dsu::cmp[aid1])->end() )
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		else{
			int x,y,z;
			cin>>x>>y>>z; --x,--y;
			dsu::add_edge(x,y,z);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1