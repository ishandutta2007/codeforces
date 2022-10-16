#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=2001;
vector<int> p(N),c(N);
int find(int tr){return tr==p[tr]?tr:p[tr]=find(p[tr]);}
void merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(c[a]>c[b])
		swap(a,b);
	p[b]=a;
}
int main()
{
	iota(all(p),0);
    int n;
    cin >> n;
    ll sol=0;
    vector<int> x(n),y(n),k(n);
    for(int i=0;i<n;i++)
    	cin >> x[i] >> y[i];
    for(int i=0;i<n;i++)
    	cin >> c[i],sol+=c[i];
    for(int i=0;i<n;i++)
    	cin >> k[i];
    vector<pair<ll,pair<int,int> > > e;
    for(int i=0;i<n;i++)
    	for(int j=i+1;j<n;j++)
    		e.pb({(ll)(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),{i,j}});
    sort(all(e));
    vector<pair<int,int> > cc;
    //cout << sol << endl;
    for(auto p:e)
    	if(find(p.s.f)!=find(p.s.s)&&p.f<max(c[find(p.s.f)],c[find(p.s.s)]))
    		cc.pb(p.s),sol-=max(c[find(p.s.f)],c[find(p.s.s)])-p.f,merge(p.s.f,p.s.s);
    set<int> st;
    for(int i=0;i<n;i++)
    	st.insert(find(i)+1);
    cout << sol << endl;
    cout << st.size() << endl;
    for(auto p:st)
    	cout << p << " ";
   cout << endl << cc.size() << endl;
   for(auto p:cc)
   	cout << p.f+1 << " " << p.s+1 << endl;
}