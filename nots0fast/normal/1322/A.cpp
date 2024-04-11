#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long 
#define MAX (int)(pow(10,2) + 10)
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

void deal(){
	ll n;
	cin>>n;
	vector<pair<ll,ll> > all;
	set<ll> avail;
	vector<bool> del(n, 0);
	string a;
	cin>>a;
	ll s= 0;
	fori(n){
		if(a[i] == '('){
			avail.insert(i);
			++s;
		}
		else{
			--s;
		}
	}
	if(s!=0){
		cout<<-1;
		return;
	}
	s = 0;
	fori(n){
		if(del[i]){
			continue;
		}
		if(a[i]=='('){
			++s;
		}
		else{
			--s;
		}
		if(s<0){
			s = 0;
			auto it = avail.lower_bound(i);
//			cout<<"for "<<i<<" which is now "<<i<<" we picked "<<*it<<endl;
			del[*it] = 1;
			all.pb(mp(i, *it));
			avail.erase(it);
		}
	}
	sort(all.begin(), all.end());
	ll mn = -1, mx = -2;
	ll ans = 0;
	fori(all.size()){
		if(all[i].ff <= mx){
			mx = max(mx, all[i].ss);
		}
		else{
		//	cout<<mn<<" "<<mx<<endl;
			ans+=(mx-mn+1);
			mn = all[i].ff;
			mx = all[i].ss;
		}
	}
//	cout<<"mn mx "<<mn<<" "<<mx<<endl;
	ans+=(mx-mn+1);
	cout<<ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}



/* 
6 8 
1 2
2 3
3 4
4 1
2 5
3 5
1 6
4 6
*/