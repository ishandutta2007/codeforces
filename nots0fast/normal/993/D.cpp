#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define lli long long int
#define MAX 5050
#define double long double
#define ch 51
lli inf = 5*pow(10,12);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
bool J(pair<lli,lli> & a,pair<lli,lli> & b){
	if(a.ff!=b.ff)	return a.ff > b.ff;
	return a.ss > b.ss;
}
lli dp[ch][MAX];
lli dp1[ch][MAX];
void deal(){
	lli n;
	cin>>n;
	vector<pair<lli,lli> > all(n);
	fori(n)	cin>>all[i].ff;
	fori(n)	cin>>all[i].ss;
	fori(ch)	forj(MAX)	dp[i][j] = inf;
	dp[0][0] = 0;
	sort(all.begin(),all.end(),J);
	lli i = 0;
	for( ; i<all.size(); ){
		lli st = i;
		vector<pair<lli,lli> > cur;
		lli s1 = 0, s2 = 0;
		while(st<all.size() && all[st].ff == all[i].ff){
			s1+=all[st].ff, s2+=all[st].ss;
			cur.push_back(mp(s1,s2));
			++st;
		}
		lli nece = st - i;
		forj(ch)
			fork(MAX)
				dp1[j][k] = inf;
		forj(ch)
			fork(MAX){
				forl(cur.size()){
					if(j>=nece-(l+1)){
						lli updated = j - (nece-(l+1)) + (l+1);
						lli sum = k + cur[l].ss;
						if(sum>=MAX || updated>=ch)	continue;
//						if(dp[j][k]!=inf){
//							cout<<"look we can save "<<updated<<" and the sum "<<cur[l].ff+dp[j][k]<<" will be stored at "<<sum<<endl;
//						}
						dp1[updated][sum] = min(dp1[updated][sum],cur[l].ff+dp[j][k]);
					}
				}
				if(j>=nece)
					dp1[j-nece][k] = min(dp1[j-nece][k],dp[j][k]);
			}
		forj(ch)
			fork(MAX)
				dp[j][k] = dp1[j][k];
		i = st;
	}
	lli mn1 = 5*pow(10,12);
	lli mn2 = 1;
	fori(ch)
		forj(MAX){
			if(mn1*j > mn2*dp[i][j])
				mn1 = dp[i][j], mn2 = j;
		}
	mn1*=1000;
	if(!(mn1%mn2))
		mn1/=mn2;
	else{
		mn1/=mn2;
		++mn1;
	}
	cout<<mn1;
}
int main() {
//	while(1)
	deal();
}