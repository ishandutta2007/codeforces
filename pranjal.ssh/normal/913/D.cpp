#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int K = 1e4;
pair<ll,int> tt[K*5];
void upd(int no, int l, int r, int pos) {
	if (l == r) {
		tt[no].S++;
		tt[no].F+=l;
		return;
	}
	int mid = (l+r)>>1;
	if (pos <= mid) upd(2*no,l,mid,pos);
	else upd(2*no+1,mid+1,r,pos);
	tt[no].F=tt[2*no].F+tt[2*no+1].F;
	tt[no].S=tt[2*no].S+tt[2*no+1].S;
}
int T;
pair<ll,int> qry(int no, int l, int r, int can) {
	if (tt[no].S <= can) return tt[no];
	if (l == r) {
		pair<ll,int> ans;
		ans.S = min(tt[no].S,can);
		ans.F=ans.S*(tt[no].F/tt[no].S);
		return ans;
	}
	if (can == 0) return {0LL,0};
	int mid= (l+r)>>1;
	auto L = qry(2*no,l,mid,can);
	can -= L.S;
	auto R = qry(2*no+1,mid+1,r,can);
	R.S += L.S;
	R.F += L.F;
	return R;

}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >>n>>T;
	vi a(n), t(n);
	vector<vi> at(n+1);
	FOR(i,0,n-1){
		cin>>a[i]>>t[i];
		at[a[i]].push_back(i);
	}
		
	int ans = 0;
	NFOR(i,n,1) {
		for (int x : at[i]) upd(1,1,K,t[x]);
		auto x = qry(1,1,K,i);
		if (x.S==i and x.F <= T) ans=max(ans,i);
	}
	memset(tt,0,sizeof tt);
	vector<ii> TT;
	NFOR(i,n,1) {
		for (int x : at[i]) upd(1,1,K,t[x]),TT.emplace_back(t[x],x);
		if (i==ans) {
			cout << ans << "\n" << ans << "\n";
			sort(all(TT));
			FOR(i,0,ans-1) cout << TT[i].S+1 << " ";
			return 0;
		}
	}
	cout << "0\n0\n";

	


	return 0;
}