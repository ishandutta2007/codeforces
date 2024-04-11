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
#define MAX 400010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;


void deal(){
	int t;
	cin>>t;
	forl(t){
		int n;
		cin>>n;
		int mx = 0;
		fori(8){
			vector<int> all[2];
			forj(n)
				all[(j/((int)pow(2,i)))&1 ].pb(j);
			if(!all[0].size() || !all[1].size())
				continue;
			forj(2)
				cout<<all[j].size()<<" ";
			forj(2)
				fork(all[j].size()){
					cout<<all[j][k] + 1;
					if(j!=2 || k!=all[j].size()-1)
						cout<<" ";
				}
			cout<<endl;
			int dist;
			cin>>dist;
			mx = max(mx, dist);
		}
		cout<<-1<<" "<<mx<<endl;
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}