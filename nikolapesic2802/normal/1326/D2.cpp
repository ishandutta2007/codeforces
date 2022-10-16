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
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
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

struct hasher{
	bool isPrime(int i){
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				return 0;
		return 1;
	}
	vector<int> mod;
	int n,m,a,mxMod=1e9+7;
	vector<vector<int> > pwr;
	vector<vector<int> > h;
	void init(string s,int number_of_mods){
		m=number_of_mods;
		for(;mod.size()<m;mxMod++)
			if(isPrime(mxMod))
				mod.push_back(mxMod);
		n=s.size();
		a=rng()%((int)1e9-250)+256;
		shuffle(all(mod),rng);
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

void test(){
	string s;
	cin >> s;
	int n=s.size();
	int poc=0;
	for(int i=0;i<n/2;i++){
		if(s[i]==s[n-1-i])
			poc++;
		else
			break;
	}
	string po=s.substr(0,poc);
	s=s.substr(poc,n-2*poc);
	n-=2*poc;
	if(n==0){
		for(auto p:po)
			printf("%c",p);
		reverse(all(po));
		for(auto p:po)
			printf("%c",p);
		printf("\n");
		return;
	}
	string rr=s;
	reverse(all(rr));
	s+=rr;
	h.init(s,15);
	for(int i=n;;i--){
		int a=0,b=i-1;
		if(h.same(a,b,n-1-b+n,n-1-a+n)){
			for(auto p:po)
				printf("%c",p);
			for(int i=a;i<=b;i++)
				printf("%c",s[i]);
			reverse(all(po));
			for(auto p:po)
				printf("%c",p);
			printf("\n");
			return;
		}
		a=n-i,b=n-1;
		if(h.same(a,b,n-1-b+n,n-1-a+n)){
			for(auto p:po)
				printf("%c",p);
			for(int i=a;i<=b;i++)
				printf("%c",s[i]);
			reverse(all(po));
			for(auto p:po)
				printf("%c",p);
			printf("\n");
			return;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		test();
	}
	return 0;
}