
// Problem : H. Set Merging
// Contest : Codeforces - Codeforces Global Round 9
// URL : http://codeforces.com/contest/1375/problem/H
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
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int B=1<<8,N=1<<12;
int a[N],ind[N],pos[N],tr;
vector<pair<int,int> > solution;
struct block{
	int l,r,koji;
	vector<int> seq;
	int gde[B];
	vector<vector<int> > index;
	vector<vector<int> > construct(vector<int> &s,int le,int ri){
		//cout << s << " " << le << " " << ri << endl;
		int n=s.size();
		vector<vector<int> > sol(n,vector<int>(n));
		if(le==ri){
			sol[0][0]=gde[s[0]-l]+1;
			//printf("%i!\n",gde[s[0]-l]+1);
			return sol;
		}
		int m=(le+ri)>>1;
		vector<int> lft,rght;
		for(auto p:s)
			if(p<=m)
				lft.pb(p);
			else
				rght.pb(p);
		vector<vector<int> > solL=construct(lft,le,m);
		vector<vector<int> > solR=construct(rght,m+1,ri);
		int leL=0,riL=-1,leR=0,riR=-1;
		for(int i=0;i<n;i++){
			int NleL=leL,NriL=riL,NleR=leR,NriR=riR;
			for(int j=i;j<n;j++){
				if(s[j]<=m)
					riL++;
				else
					riR++;
				if(leL>riL){
					sol[i][j]=solR[leR][riR];
					//printf("Isto R %i %i: %i\n",i,j,sol[i][j]);
					continue;
				}
				if(leR>riR){
					sol[i][j]=solL[leL][riL];
					//printf("Isto L %i %i: %i\n",i,j,sol[i][j]);
					continue;
				}
				sol[i][j]=tr++;
				//printf("merge %i %i: %i,  %i + %i\n",i,j,sol[i][j],solL[leL][riL],solR[leR][riR]);
				solution.pb({solL[leL][riL],solR[leR][riR]});
			}
			leL=NleL,riL=NriL,leR=NleR,riR=NriR;
			if(s[i]<=m)
				leL++,riL++;
			else
				leR++,riR++;
		}
		return sol;
	}
	void build(int d){
		koji=d;
		for(int i=0;i<N;i++){
			if(a[i]>=l&&a[i]<=r){
				seq.pb(a[i]);
				ind[i]=d;
				pos[i]=seq.size()-1;
				gde[a[i]-l]=i;
			}
		}
		index=construct(seq,l,r);
	}
}b[N/B];
int gen(int l,int r){
	vector<int> le(N/B,B),ri(N/B,-1);
	for(int i=l;i<=r;i++){
		int d=(a[i]-1)/B;
		le[d]=min(le[d],pos[i]);
		ri[d]=max(ri[d],pos[i]);
	}
	int trInd=-1;
	for(int i=0;i<N/B;i++){
		if(ri[i]==-1)
			continue;
		if(trInd==-1){
			trInd=b[i].index[le[i]][ri[i]];
			continue;
		}
		solution.pb({trInd,b[i].index[le[i]][ri[i]]});
		trInd=tr++;
	}
	return trInd;
}
int main()
{
	int n=ri(),q=ri();
	tr=n+1;
	for(int i=0;i<(n-1)/B+1;i++)
		b[i].l=i*B+1,b[i].r=min((i+1)*B,n);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	for(int i=0;i<(n-1)/B+1;i++)
		b[i].build(i);
	vector<int> inds(q);
	for(int i=0;i<q;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		inds[i]=gen(l-1,r-1);
	}
	printf("%i\n",tr-1);
	for(auto p:solution)
		printf("%i %i\n",p.f,p.s);
	for(int i=0;i<q;i++)
		printf("%i ",inds[i]);
	printf("\n");
	return 0;
}