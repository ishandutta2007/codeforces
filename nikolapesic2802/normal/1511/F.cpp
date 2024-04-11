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

const int mod=998244353;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){
    return (long long)a*b%mod;
}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}

const int N=41,L=26;
vector<int> nxt[N][L];
bool kr[N];
bool pref(string a,string b){
	if(a.size()<b.size())
		return pref(b,a);
	return a.substr(a.size()-b.size(),b.size())==b;
}
vector<vector<int>> mul(vector<vector<int>> &a,vector<vector<int>> &b){
	int n=a.size(),m=b[0].size(),l=a[0].size();
	assert(a[0].size()==b.size());
	vector<vector<int>> sol(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<l;k++)
				sol[i][j]=add(sol[i][j],mul(a[i][k],b[k][j]));
	return sol;
}
int main()
{
	int n=ri(),m=ri();
	vector<string> s(n);
	rd(s);
	map<string,int> done;
	int ind=0;
	vector<string> pre;
	
	//done[""]=ind++;pre.pb("");
	
	for(int i=0;i<n;i++){
		string tr;
		for(int j=0;j<s[i].size();j++){
			tr+=s[i][j];
			if(done.find(tr)==done.end()){
				done[tr]=ind++;
				pre.pb(tr);
			}
			if(j==s[i].size()-1){
				kr[done[tr]]=1;
			}
		}
	}
	for(auto p:done){
		string tr=p.f;
		int i=p.s;
		for(int j=0;j<26;j++){
			char c='a'+j;
			string novi=tr+c,o;
			o+=c;
			if(done.find(novi)!=done.end())
				nxt[i][j].pb(done[novi]);
			if(kr[i]&&done.find(o)!=done.end())
				nxt[i][j].pb(done[o]);
		}
	}
	vector<pair<int,int>> pr;
	map<pair<int,int>,int> koji;
	for(int i=0;i<ind;i++)
		for(int j=i;j<ind;j++)
			if(pref(pre[i],pre[j])){
				pr.pb({i,j});
				koji[{i,j}]=pr.size()-1;
			}
	int L=pr.size();
	vector<vector<int>> mulMat(L,vector<int>(L,0));
	for(int k=0;k<L;k++){
		int i=pr[k].f,j=pr[k].s;
		for(int l=0;l<26;l++){
			for(auto pp:nxt[i][l])
				for(auto dd:nxt[j][l]){
					int p=pp,d=dd;
					if(p>d)
						swap(p,d);
					if(koji.find({p,d})!=koji.end()){
						int sl=koji[{p,d}];
						mulMat[k][sl]=add(mulMat[k][sl],1);
					}
				}
		}
	}
	vector<vector<int>> begMat(1,vector<int>(L,0));
	m--;
	for(int k=0;k<L;k++){
		int i=pr[k].f,j=pr[k].s;
		if(i!=j)
			continue;
		if(pre[i].size()==1)
			begMat[0][k]++;
	}
	for(;m;m>>=1,mulMat=mul(mulMat,mulMat))
		if(m&1)
			begMat=mul(begMat,mulMat);
	int sol=0;
	for(int k=0;k<L;k++){
		int i=pr[k].f,j=pr[k].s;
		if(kr[i]&&kr[j])
			sol=add(sol,begMat[0][k]);
	}
	printf("%i\n",sol);
	return 0;
}