
// Problem : F. Nastya and CBS
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : https://codeforces.com/contest/1340/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int br=1;
int a,m,mxMod=1e9+7;
vector<int> mod;
struct hasher{
	bool isPrime(int i){
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				return 0;
		return 1;
	}
	
	int n;
	vector<vector<int> > pwr;
	vector<vector<int> > h;
	void init(vector<int> &s,int mx,int number_of_mods=br){
		if(mod.empty()){
			m=number_of_mods;
			for(;mod.size()<m;mxMod++)
				if(isPrime(mxMod))
					mod.push_back(mxMod);
			a=rng()%((int)1e9-mx)+mx;
		}
		n=s.size();
		if(s.empty())
			return;
		h.resize(m);
		pwr.resize(m);
		for(int i=0;i<m;i++)
			h[i].resize(n),pwr[i].resize(n+1);
		for(int j=0;j<m;j++){
			h[j][0]=s[0]%mod[j];
			pwr[j][0]=1;
			for(int i=1;i<n;i++){
				h[j][i]=((ll)h[j][i-1]*a+s[i])%mod[j],pwr[j][i]=(ll)pwr[j][i-1]*a%mod[j];
			}
			pwr[j][n]=(ll)pwr[j][n-1]*a%mod[j];
		}
	}
	int getHash(int l,int r,int i){
		int hh=h[i][r];
		if(l){
			hh=hh-((ll)pwr[i][r-l+1]*h[i][l-1]%mod[i]);
			if(hh<0)
				hh+=mod[i];
		}
		return hh;
	}
	bool same(int l1,int r1,int l2,int r2){
		if(r1-l1!=r2-l2||l1>r1)
			return 0;
		for(int i=0;i<m;i++)
			if(getHash(l1,r1,i)!=getHash(l2,r2,i))
				return 0;
		return 1;
	}
}h;

const int N=1e5+5,S=310;
vector<int> brackets(N);
pair<vector<int>,vector<int> > no={{INT_MAX},{INT_MAX}};
int n,k;
pair<vector<int>,vector<int> > getStk(int l,int r){
	r=min(r,n-1);
	vector<int> stk;
	for(int i=l;i<=r;i++){
		auto p=brackets[i];
		if(p<0){
			if(stk.empty()||stk.back()<0)
				stk.pb(p);
			else{
				if(stk.back()==-p){
					stk.pop_back();
				}
				else
					return no;
			}
		}
		else{
			stk.pb(p);
		}
	}
	vector<int> o,c;
	for(auto p:stk)
		if(p<0)
			c.pb(-p);
		else
			o.pb(p);
	reverse(all(o));
	return {o,c};
}

struct blok{
	int i;
	bool correct;
	hasher open,close;
	void init(int ii){
		i=ii;
		build();
	}
	void build(){
		auto tr=getStk(i*S,(i+1)*S-1);
		//cout << tr << endl;
		if(tr==no)
			correct=0;
		else{
			correct=1,open.init(tr.f,k),close.init(tr.s,k);
		}
	}
}blocks[N/S+1];
bool ok(int l,int r){
	int lb=l/S,rb=r/S;
	if(lb==rb){
		auto tr=getStk(l,r);
		return tr.f.empty()&&tr.s.empty();
	}
	auto tr=getStk(l,(lb+1)*S-1);
	if(tr==no||tr.s.size())
		return 0;
	auto trend=getStk(rb*S,r);
	if(trend==no||trend.f.size())
		return 0;
	//cout << l << " " << r << tr << trend << endl;
	hasher my,kraj;
	my.init(tr.f,k);
	kraj.init(trend.s,k);
	vector<pair<int,pair<int,int> > > stk;
	if(tr.f.size())
		stk.pb({-1,{0,tr.f.size()-1}});
	for(int i=lb+1;i<rb;i++){
		if(!blocks[i].correct)
			return 0;
		//cout << i << stk << endl;
		int l=0,r=blocks[i].close.n-1;
		while(l<=r){
			if(stk.empty())
				return 0;
			int l1=stk.back().s.f,r1=stk.back().s.s;
			int d=min(r1-l1+1,r-l+1);
			int gde=stk.back().f;
			//printf("%i  %i %i   %i %i\n",gde,l1,r1,l,r);
			stk.pop_back();
			if(gde==-1){
				for(int j=0;j<br;j++){
					int a=my.getHash(l1,l1+d-1,j),b=blocks[i].close.getHash(l,l+d-1,j);
					//printf("%i %i\n",a,b);
					if(a!=b)
						return 0;
				}
			}
			else{
				for(int j=0;j<br;j++){
					int a=blocks[gde].open.getHash(l1,l1+d-1,j),b=blocks[i].close.getHash(l,l+d-1,j);
					//printf("%i %i\n",a,b);
					if(a!=b)
						return 0;
				}
			}
			l1+=d;
			l+=d;
			if(l1<=r1)
				stk.pb({gde,{l1,r1}});
		}
		if(blocks[i].open.n)
			stk.pb({i,{0,blocks[i].open.n-1}});
	}
	l=0,r=kraj.n-1;
	while(l<=r){
		if(stk.empty())
			return 0;
		int l1=stk.back().s.f,r1=stk.back().s.s;
		int d=min(r1-l1+1,r-l+1);
		int gde=stk.back().f;
		stk.pop_back();
		if(gde==-1){
			for(int j=0;j<br;j++){
				int a=my.getHash(l1,l1+d-1,j),b=kraj.getHash(l,l+d-1,j);
				if(a!=b)
					return 0;
			}
		}
		else{
			for(int j=0;j<br;j++){
				int a=blocks[gde].open.getHash(l1,l1+d-1,j),b=kraj.getHash(l,l+d-1,j);
				if(a!=b)
					return 0;
			}
		}
		l1+=d;
		l+=d;
		if(l1<=r1)
			stk.pb({gde,{l1,r1}});
	}
	return stk.empty();
}
int main()
{
	scanf("%i %i",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%i",&brackets[i]);
	for(int i=0;i<=(n-1)/S;i++)
		blocks[i].init(i);
	int q;
	scanf("%i",&q);
	for(int i=0;i<q;i++){
		int t;
		scanf("%i",&t);
		if(t==1){
			int i,t;
			scanf("%i %i",&i,&t);
			i--;
			brackets[i]=t;
			blocks[i/S].build();
		}
		else{
			int l,r;
			scanf("%i %i",&l,&r);
			l--;r--;
			printf(ok(l,r)?"Yes\n":"No\n");
		}
	}
	return 0;
}