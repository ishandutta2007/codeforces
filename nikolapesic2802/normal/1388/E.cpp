
// Problem : E. Uncle Bogdan and Projections
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : http://codeforces.com/contest/1388/problem/E
// Memory Limit : 512 MB
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

const ld PI=acos(-1),eps=1e-10;
int main()
{
	int n=ri();
	vector<int> l(n),r(n),y(n);
	for(int i=0;i<n;i++)
		rd(l[i],r[i],y[i]);
	auto solve=[&](ld ugao){
		//printf("%Lf!\n",ugao);
		ld mn=LLONG_MAX,mx=LLONG_MIN;
		ld gde;
		if(ugao<=-PI/2){
			ugao=-PI/2-ugao;
			gde=-tan(ugao);
		}
		else{
			ugao=ugao+PI/2;
			gde=tan(ugao);
		}
		for(int i=0;i<n;i++){
			mn=min(mn,l[i]+gde*y[i]);
			mx=max(mx,r[i]+gde*y[i]);
		}
		//printf("%Lf: %Lf\n",ugao,mx-mn);
		return mx-mn;
	};
	ld vece=-PI,manje=0;
	vector<pair<ld,int> > aa;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int dy=abs(y[i]-y[j]);
			if(!dy)
				continue;
			int a=i,b=j;
			if(y[a]<y[b])
				swap(a,b);
			ld ugao=atan2(-dy,r[b]-l[a]);
			ld drugi=atan2(-dy,l[b]-r[a]);
			aa.pb({drugi,1});
			aa.pb({ugao,-1});
		}
	sort(all(aa));
	//cout << aa << endl;
	int tr=0;
	ld sol=LLONG_MAX;
	ld lst=-PI;
	vector<ld> moze;
	for(auto p:aa){
		//cout << lst << p << tr << endl;
		if(tr==0){
			if(lst<=-PI/2+eps&&p.f>=-PI/2-eps)
				moze.pb(-PI/2);
			moze.pb(p.f);
		}
		tr+=p.s;
		if(tr==0){
			moze.pb(p.f);
		}
		lst=p.f;
	}
	if(lst<=-PI/2+eps)
		moze.pb(-PI/2);
	sort(all(moze));
	moze.erase(unique(all(moze)),moze.end());
	int le=0,ri=moze.size()-1;
	while(le<ri){
		int m=(le+ri)>>1;
		ld val1=solve(moze[m]),val2=solve(moze[m+1]);
		if(val1<val2)
			ri=m;
		else
			le=m+1;
	}
	printf("%.10Lf\n",solve(moze[le]));
	return 0;
}