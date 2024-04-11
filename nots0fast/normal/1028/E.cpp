#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(6)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 220020
#define ld long double
#define pb push_back
lli inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	lli n;
	cin>>n;
	lli b[n];
	set<lli> ch;
	fori(n)
		cin>>b[i],ch.insert(b[i]);
	if(ch.size()==1){
		if(*ch.begin() == 0){
			cout<<"YES\n";
			fori(n)
				cout<<2<<' ';
		}
		else
			cout<<"NO\n";
	}
	else{
		bool ok[n] = {};
		lli a[n];
		if(b[0] > b[n-1])
			ok[0] = 1, a[0] = b[0];
		for(lli i=1; i<n; i++)
			if(b[i] > b[i-1])
				ok[i] = 1, a[i] = b[i];
		vector<pair<lli,lli> > all;
		fori(n){
			if(ok[i])
				continue;
			lli st = i;
			while(i<n && !ok[i])
				++i;
			all.pb(mp(st,i-1));
		}
		if(all.size()>1 && all[0].ff == 0 && all[all.size()-1].ss == n)
			all[0].ff = all[all.size()-1].ff, all.erase(all.end()-1);
		fori(all.size()){
			lli pt = all[i].ss, nx = (pt+1)%n;
//			cout<<pt<<" "<<nx<<" "<<inf<<" "<<inf/a[nx]<<" "<<(inf/a[nx]+1)<<" "<<(inf/a[nx]+1)*a[nx]<<endl;
			a[pt] = ( inf/a[nx] + 1 )*a[nx] + b[pt];
//			cout<<a[pt]<<endl;
			if(all[i].ff == all[i].ss)
				continue;
			do{
				--pt;
				if(pt<0)
					pt = n-1;
//				cout<<pt<<" "<<nx<<endl;
				nx = (pt+1)%n;
				a[pt] = a[nx] + b[pt];
			}while(pt!=all[i].ff);
		}
		cout<<"YES\n";
		fori(n)
			cout<<a[i]<<' ';
	}
}
int main() {
	deal();
}