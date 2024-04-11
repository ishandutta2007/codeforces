
// Problem : F. Restore the Permutation by Sorted Segments
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/contest/1343/problem/F
// Memory Limit : 0 MB
// Time Limit : 0 ms
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

int n;
deque<int> sol;
int first;
set<int> prvi;
set<set<int> > a;
vector<set<int> > uzeti;
set<int> em;
bool solve(){
	//cout << a << uzeti << first << sol << endl;
	if(a.empty()){
		if(sol.size()!=n-1||first==-1)
			return 0;
		/*for(auto p:uzeti)
			if(p.size())
				return 0;*/
		sol.push_front(first);
		set<int> check;
		for(int i=0;i<prvi.size();i++)
			check.insert(sol[i]);
		if(check!=prvi)
			return 0;
		for(auto p:sol)
			printf("%i ",p);
		printf("\n");
		return 1;
	}
	map<int,int> cnt;
	for(auto p:a)
		for(auto d:p)
			cnt[d]++;
	vector<int> jed;
	for(auto p:cnt)
		if(p.s==1)
			jed.pb(p.f);
	//cout << jed << endl;
	if(jed.empty())
		return 0;
	if(jed.size()==1){
		sol.push_front(jed[0]);
		auto koji=a.begin();
		for(auto it=a.begin();it!=a.end();it++){
			if((*it).count(jed[0])){
				koji=it;
				break;
			}
		}
		uzeti.pb(*koji);
		for(auto &p:uzeti){
			if(p.empty())
				continue;
			if(!p.count(jed[0])){
				return 0;
			}
			p.erase(jed[0]);
		}
		a.erase(koji);
		return solve();
	}
	else{
		if(first!=-1)
			return 0;
		//printf("STIGAO!\n");
		bool moze=1;
		for(auto p:uzeti)
			if(p.size()&&!p.count(jed[0]))
				moze=0;
		if(moze){
			//printf("MOZE!\n");
			deque<int> solback=sol;
			int firstback=first;
			set<int> prviback=prvi;
			set<set<int> > aback=a;
			vector<set<int> > uzetiback=uzeti;
			auto koji=a.begin();
			for(auto it=a.begin();it!=a.end();it++){
				if((*it).count(jed[0])){
					koji=it;
					break;
				}
			}
			auto koji1=a.begin();
			for(auto it=a.begin();it!=a.end();it++){
				if((*it).count(jed[1])){
					koji1=it;
					break;
				}
			}
			if(koji!=koji1){
				//printf("NISU ISTI!\n");
				uzeti.pb(*koji);
				for(auto &p:uzeti){
					if(p.empty())
						continue;
					if(!p.count(jed[0])){
						return 0;
					}
					p.erase(jed[0]);
				}
				a.erase(koji);
				auto tr=*koji1;
				sol.push_front(jed[0]);
				first=jed[1];
				prvi=tr;
				a.erase(koji1);
				tr.erase(jed[1]);
				a.insert(tr);
				if(solve())
					return 1;
			}
			else{
				if(a.size()==1&&(*a.begin()).size()==2){
					first=jed[1];
					prvi=*koji;
					sol.push_front(jed[0]);
					a.clear();
					if(solve())
						return 1;
				}
			}
			sol=solback;
			first=firstback;
			prvi=prviback;
			a=aback;
			uzeti=uzetiback;
		}
		moze=1;
		for(auto p:uzeti)
			if(p.size()&&!p.count(jed[1]))
				moze=0;
		if(moze){
			swap(jed[0],jed[1]);
			auto koji=a.begin();
			for(auto it=a.begin();it!=a.end();it++){
				if((*it).count(jed[0])){
					koji=it;
					break;
				}
			}
			auto koji1=a.begin();
			for(auto it=a.begin();it!=a.end();it++){
				if((*it).count(jed[1])){
					koji1=it;
					break;
				}
			}
			if(koji!=koji1){
				//printf("NISU ISTI!\n");
				uzeti.pb(*koji);
				for(auto &p:uzeti){
					if(p.empty())
						continue;
					if(!p.count(jed[0])){
						return 0;
					}
					p.erase(jed[0]);
				}
				a.erase(koji);
				auto tr=*koji1;
				sol.push_front(jed[0]);
				first=jed[1];
				prvi=tr;
				a.erase(koji1);
				tr.erase(jed[1]);
				a.insert(tr);
				return solve();
			}
			else{
				if(a.size()==1&&(*a.begin()).size()==2){
					first=jed[1];
					prvi=*koji;
					sol.push_front(jed[0]);
					a.clear();
					if(solve())
						return 1;
				}
			}
		}
	}
	return 0;
}
void test(){
	first=-1;
	sol.clear();
	prvi.clear();
	scanf("%i",&n);
	a.clear();
	uzeti.clear();
	for(int i=1;i<n;i++){
		int k,b;
		scanf("%i",&k);
		set<int> tr;
		for(int j=0;j<k;j++)
			scanf("%i",&b),tr.insert(b);
		a.insert(tr);
	}
	assert(solve());
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
		test();
	}
	return 0;
}