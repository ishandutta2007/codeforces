
// Problem: E. Baby Ehab's Hyper Apartment
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

int q1(int a,int b){
	printf("1 %i %i\n",a,b);
	fflush(stdout);
	int x=ri();
	return x;
}
int q2(int x,vector<int> k){
	if(k.empty())
		return 0;
	printf("2 %i %i ",x,k.size());
	for(auto p:k)
		printf("%i ",p);
	printf("\n");
	fflush(stdout);
	int X=ri();
	return X;
}
void test(){
	int n=ri();
	vector<int> sp={0};
	for(int i=1;i<n;i++){
		if(q1(i,sp[0])){
			sp.insert(sp.begin(),i);
		}
		else{
			int l=0,r=sp.size()-1;
			while(l<r){
				int m=(l+r+1)>>1;
				if(q1(sp[m],i))
					l=m;
				else
					r=m-1;
			}
			sp.insert(sp.begin()+1+l,i);
		}
	}
	vector<bool> done(n);
	vector<vector<int>> comp;
	vector<int> trComp;
	while(sp.size()||trComp.size()){
		if(trComp.empty()){
			trComp.pb(sp.back());
			sp.pop_back();
			continue;
		}
		int nasao=-1;
		for(auto p:trComp){
			if(done[p])
				continue;
			if(q2(p,sp)){
				nasao=p;
				break;
			}
			else
				done[p]=1;
		}
		if(nasao==-1){
			comp.pb(trComp);
			trComp.clear();
		}
		else{
			int tr=sp.back();
			sp.pop_back();
			while(1){
				trComp.pb(tr);
				if(q1(nasao,tr)){
					break;
				}
				tr=sp.back();
				sp.pop_back();
			}
		}
	}
	vector<string> mat(n,string(n,'0'));
	for(int i=0;i<comp.size();i++)
		for(int j=i;j<comp.size();j++)
			for(auto p:comp[i])
				for(auto q:comp[j])
					mat[q][p]='1';
	printf("3\n");
	for(auto p:mat)
		cout << p << "\n";
	fflush(stdout);
	int x=ri();
}
int main()
{
	for(int t=ri();t--;){
		test();
	}
	return 0;
}