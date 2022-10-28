/*input
3
101

*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

int n;
string s;
string ans="$";

void check(int len){
	string a=string(s,0,len);
	string b=string(s,len,n-len);
	// cout<<a<<' '<<b<<'\n';
	reverse(ALL(a));
	reverse(ALL(b));
	while(SZ(a)<SZ(b)) a.pb('0');
	while(SZ(b)<SZ(a)) b.pb('0');
	int car=0;
	REP(i,SZ(a)){
		int tmp=a[i]-'0'+b[i]-'0'+car;
		car=tmp/10;
		a[i]='0'+tmp%10;
	}
	if(car) a.pb(char('0'+car));
	reverse(ALL(a));

	if(ans[0]=='$'){
		ans=a;
		return;
	}

	if(SZ(ans)>SZ(a)) ans=a;
	else if(SZ(ans)==SZ(a)){
		int i=0;
		while(i<SZ(a)&&a[i]==ans[i]) i++;
		if(a[i]<ans[i]){
			ans=a;
		}
	}
}


int main(){
	IOS;
	cin>>n>>s;

	int mn=INF;

	for(int i=1;i<n;i++){
		if(s[i]=='0') continue;
		mn=min(mn,max(i,n-i)+1);
	}
	assert(mn!=INF);
	for(int i=1;i<n;i++){
		if(s[i]=='0') continue;
		if(max(i,n-i)+1==mn) check(i);
	}
	cout<<ans<<'\n';
	return 0;
}