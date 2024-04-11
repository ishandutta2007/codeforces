#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<(lli)v; i++)
#define forj(v) for(lli j=0; j<(lli)v; j++)
#define fork(v) for(lli k=0; k<(lli)v; k++)
#define forl(v) for(lli l=0; l<(lli)v; l++)
#define fort(v) for(lli t=0; t<(lli)v; t++)
#define forz(v) for(lli z=0; z<(lli)v; z++)
#define lli long long int
#define MAX 3030
#define double long double
#define ch  1430
#define pb push_back
lli inf = 8*pow(10,18);
lli modulo = pow(10,9)+7;
double eps = 1e-8;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
deque<lli> voters[MAX];
pair<lli,lli> tot_sum(lli m, lli c, lli total){
	lli s = 0;
	for(lli j=1; j<m; j++){
		lli nece = voters[j].size();
		lli st = 0;
		while(nece>c){
			s+=voters[j][st];
			++total, ++st;
			--nece;
		}
	}
	return mp(total,s);
}
bool J(pair<lli,lli>& a, pair<lli,lli>& b){
	return a.ff < b.ff;
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	lli n,m;
	cin>>n>>m;
	vector<pair<lli,lli> > all;
	fori(n){
		lli vt, num;
		cin>>vt>>num;
		--vt;
		voters[vt].pb(num);
		if(vt)
			all.pb(mp(num,vt));
	}
	sort(all.begin(),all.end(),J);
	fori(m)
		sort(voters[i].begin(),voters[i].end());
	lli mn = inf;
	lli s = 0;
	for(lli i=0; i<=n/2 + 1; i++){
		lli a = 0 , b = n+1;
		while(a<b){
			lli c = (a+b)/2+1;
			pair<lli,lli> cav = tot_sum(m,c,i+voters[0].size());
			if(cav.ff > c)
				a=c;
			else
				b=c-1;
		}
		pair<lli,lli> cav = tot_sum(m,a,i+voters[0].size());
//		cout<<"the tot: "<<cav.ff<<" the sum: "<<cav.ss<<" the s: "<<s<<endl;
		mn = min(mn,cav.ss + s);
		if(i >= (lli)all.size())
			break;
		s+=all[i].ff;
		voters[all[i].ss].pop_front();
	}
	cout<<mn;
}
int main(){
	srand(time(NULL));
	in.open("i.txt");
	out.open("o.txt");
	deal();
}