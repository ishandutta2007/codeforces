
// Problem : H1. Breadboard Capacity (easy version)
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/H1
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

int n,m,q;
string gore,dole,levo,desno,s="BR";
int ind=0;
struct segTree{
    int n;
    vector<int> cnt,sw;
    void update(int i){
        cnt[i]=cnt[2*i]+cnt[2*i+1];
    }
    void init(int l,int r,int i,vector<int> &vals){
        if(l==r){
            cnt[i]=vals[l];
            return;
        }
        int m=(l+r)/2;
        init(l,m,2*i,vals);
        init(m+1,r,2*i+1,vals);
        update(i);
    }
    void prop(int i,int l,int m,int r){
        if(sw[i]){
        	sw[i]=0;
        	sw[2*i]^=1;
        	sw[2*i+1]^=1;
        	cnt[2*i]=(m-l+1)-cnt[2*i];
        	cnt[2*i+1]=(r-m)-cnt[2*i+1];
        }
    }
    void flipRange(int qs,int qe,int l,int r,int i){
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r){
            sw[i]^=1;
            cnt[i]=(r-l+1)-cnt[i];
            return;
        }
        int m=(l+r)/2;
        prop(i,l,m,r);
        flipRange(qs,qe,l,m,2*i);
        flipRange(qs,qe,m+1,r,2*i+1);
        update(i);
    }

    public:
    void init(int N){ //Make a tree of size N and set it to zeros
        n=N;
        int pwr=1;
        while(pwr<2*n)
            pwr*=2;
        cnt.resize(pwr);
        sw.resize(pwr);
        for(int i=0;i<pwr;i++)
            cnt[i]=sw[i]=0;
    }
    void init(vector<int> &vals){ //Make a tree with the given vals
        init(vals.size());
        init(0,n-1,1,vals);
    }
    void rangeFlip(int qs,int qe){flipRange(qs,qe,0,n-1,1);}
}l,r,u,d;
void sw(){
	swap(l,u);
	swap(r,d);
	swap(levo,gore);
	swap(desno,dole);
	swap(n,m);
	ind^=1;
}
struct node{
	int l,r;
	vec<4,int> dp;
	int swapL,swapR;
	void swL(){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					swap(dp[0][i][j][k],dp[1][i][j][k]);
		swapL^=1;
	}
	void swR(){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					swap(dp[i][0][j][k],dp[i][0][j][k]);
		swapR^=1;
	}
	node(){
		vec<4,int> no(2,2,2,2,INT_MAX);
		dp=no;
		l=r=-1;
		swapL=swapR=0;
	}
	int get(){
		int sol=INT_MAX;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				sol=min(sol,dp[0][0][i][j]);
		return sol;
	}
}e;
vector<node> drvo;
void prop(int i){
	if(drvo[i].l==-1)
		return;
	if(drvo[i].swapL){
		drvo[i].swapL=0;
		drvo[drvo[i].l].swL();
		drvo[drvo[i].r].swL();
	}
	if(drvo[i].swapR){
		drvo[i].swapR=0;
		drvo[drvo[i].l].swR();
		drvo[drvo[i].r].swR();
	}
}
vec<4,int> merge(vec<4,int> a,vec<4,int> b){
	vec<4,int> dp(2,2,2,2,INT_MAX);
	for(int o=0;o<2;o++)
		for(int d=0;d<2;d++)
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++)
						dp[o][d][i][j]=min(dp[o][d][i][j],a[o][d][i][k]+b[o][d][k][j]);
	return dp;
}
void calcVal(int tr,int pos){
	if(pos==0){
		int cntB=l.cnt[1],cntR=n-l.cnt[1];
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				drvo[tr].dp[i][j][0][0]=cntR,drvo[tr].dp[i][j][1][0]=n+cntR,drvo[tr].dp[i][j][1][1]=cntB,drvo[tr].dp[i][j][0][1]=n+cntB;
		return;
	}
	if(pos==m+1){
		int cntB=r.cnt[1],cntR=n-r.cnt[1];
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				drvo[tr].dp[i][j][0][0]=cntR,drvo[tr].dp[i][j][1][0]=n+cntR,drvo[tr].dp[i][j][1][1]=cntB,drvo[tr].dp[i][j][0][1]=n+cntB;
		return;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				for(int d=0;d<2;d++)
					drvo[tr].dp[i][j][k][d]=(k!=d?n:0)+((s[d]!=gore[pos-1]?1:0)^i)+((s[d]!=dole[pos-1]?1:0)^j);
}
void build(int tr=ind,int l=0,int r=m+1){
	if(l==r){
		calcVal(tr,l);
		/*printf("%i-%i:\n",l,r);
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				printf("dp[%i][%i]: %i\n",i,j,drvo[tr].dp[0][0][i][j]);*/
		return;
	}
	int m=(l+r)>>1;
	drvo[tr].l=drvo.size();
	drvo[tr].r=drvo.size()+1;
	drvo.pb(e);
	drvo.pb(e);
	build(drvo[tr].l,l,m);
	build(drvo[tr].r,m+1,r);
	drvo[tr].dp=merge(drvo[drvo[tr].l].dp,drvo[drvo[tr].r].dp);
}
int main()
{
	scanf("%i %i %i",&n,&m,&q);
	cin >> levo >> desno >> gore >> dole;
	vector<int> a;
	a.clear();
	for(auto p:levo)
		a.pb(p=='B'?1:0);
	l.init(a);
	a.clear();
	for(auto p:desno)
		a.pb(p=='B'?1:0);
	r.init(a);
	a.clear();
	for(auto p:gore)
		a.pb(p=='B'?1:0);
	u.init(a);
	a.clear();
	for(auto p:dole)
		a.pb(p=='B'?1:0);
	d.init(a);
	drvo.pb(e);
	drvo.pb(e);
	build();
	sw();
	build();
	sw();
	printf("%i\n",min(drvo[0].get(),drvo[1].get()));
	for(int i=0;i<q;i++){
		string s;
		int a,b;
		cin>>s>>a>>b;
		
	}
	return 0;
}