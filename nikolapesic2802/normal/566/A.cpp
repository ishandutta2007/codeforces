
// Problem : A. Matching Names
// Contest : VK Cup 2015 - Finals, online mirror
// URL : https://codeforces.com/contest/566/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

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

const int N=1e5+5;
struct trieNode{
	vector<int> ends,nxt;
}em;
vector<trieNode> tri(1);
string s;
void addNode(int ind,int pos,int tr){
	//printf("%i %i %i\n",ind,pos,tr);
	if(tri[tr].nxt.empty())
		tri[tr].nxt.resize(26,-1);
	if(pos==(int)s.size()){
		tri[tr].ends.pb(ind);
		return;
	}
	int c=s[pos]-'a';
	//printf("%i!\n",c);
	if(tri[tr].nxt[c]==-1){
		tri[tr].nxt[c]=tri.size();
		tri.pb(em);
	}
	addNode(ind,pos+1,tri[tr].nxt[c]);
}
vector<pair<int,int> > pairs;
vector<vector<int> > inds;
vector<int> emp;
int sol=0;
int match(int tr,int dep){
	int my=inds.size();
	inds.pb(emp);
	for(auto p:tri[tr].ends){
		if(inds[my].size()&&(ll)inds[my].back()*p<0){
			int a=inds[my].back();
			inds[my].pop_back();
			pairs.pb({max(a,p),-min(a,p)});
			sol+=dep;
		}
		else
			inds[my].pb(p);
	}
	for(int i=0;i<26;i++){
		if(tri[tr].nxt[i]==-1)
			continue;
		int njegov=match(tri[tr].nxt[i],dep+1);
		if(inds[njegov].empty())
			continue;
		if(inds[my].empty()){
			my=njegov;
			continue;
		}
		if((ll)inds[my].front()*inds[njegov].front()<0){
			while(inds[my].size()&&inds[njegov].size()){
				int a=inds[my].back(),b=inds[njegov].back();
				inds[my].pop_back();
				inds[njegov].pop_back();
				pairs.pb({max(a,b),-min(a,b)});
				sol+=dep;
			}
			if(inds[njegov].size())
				my=njegov;
			continue;
		}
		if(inds[my].size()<inds[njegov].size())
			swap(my,njegov);
		for(auto p:inds[njegov])
			inds[my].pb(p);
	}
	return my;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	vector<string> a(n),b(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<n;i++)
		s=a[i],addNode(i+1,0,0);
	for(int i=0;i<n;i++)
		s=b[i],addNode(-i-1,0,0);
	match(0,0);
	printf("%i\n",sol);
	for(auto p:pairs)
		printf("%i %i\n",p.f,p.s);
	return 0;
}