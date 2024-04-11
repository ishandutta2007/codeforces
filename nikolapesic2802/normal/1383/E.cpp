
// Problem : E. Strange Operation
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : http://codeforces.com/contest/1383/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
template<typename C,typename...T>void rd(C a,T...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int mod=1e9+7; //998244353
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
string s;
set<string> moze;
void rec(string s){
	if(moze.count(s))
		return;
	moze.insert(s);
	if(s.size()==1)
		return;
	for(int i=0;i<s.size()-1;i++){
		string nxt=s;
		nxt[i]=max(s[i],s[i+1]);
		nxt.erase(i+1,1);
		rec(nxt);
	}
}
int brute(){
	moze.clear();
	rec(s);
	return moze.size();
}


int moj(){
	int n=s.size();
	vector<int> dp(n);
	set<pair<int,int> > siz;
	int last=-1;
	vector<int> cnt(n);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(i&&s[i-1]=='0')
				cnt[i]=cnt[i-1]+1;
			else
				cnt[i]=1;
		}
	}
	int end=n-1,cc=0;
	while(s[end]=='0')
		end--,cc++;
	int start=0;
	while(s[start]=='0')
		start++;
	if(start==n)
		return n;
	for(int i=end;i>=start;i--){
		if(s[i]=='1'||last==-1)
			dp[i]=1;
		if(last!=-1)
			dp[i]=add(dp[i],dp[last]);
		if(s[i]=='1'){
			if(last!=i+1&&last!=-1){
				int sz=last-i-1;
				while(siz.size()&&(*siz.begin()).f<=sz)
					siz.erase(siz.begin());
				siz.insert({sz,i+1});
			}
			last=i;
			auto it=siz.lower_bound({1,0});
			if(it!=siz.end())
				dp[i]=add(dp[i],dp[(*it).s]);
		}
		else{
			if(i!=n-1&&s[i+1]=='0'){
				dp[i]=add(dp[i],dp[i+1]);
			}
			else{
				auto it=siz.lower_bound({cnt[i]+1,0});
				if(it!=siz.end()){
					dp[i]=add(dp[i],dp[(*it).s+cnt[i]]);
				}
			}
		}
	}
	return mul(mul(start+1,cc+1),dp[start]);
}


void stress(){
	while(1){
		int n=rng()%(1<<5)+1;
		s.clear();
		while(n){
			s+='0'+(n&1);
			n/=2;
		}
		int k=rng()%3;
		for(int i=0;i<k;i++)
			s+='0';
		if(moj()!=brute()){
			cout << s << endl;
			printf("%i %i\n",moj(),brute());
			cout << moze << endl;
			exit(0);
		}
	}
}
int main()
{
	//stress();
	cin >> s;
	printf("%i\n",moj());
	//printf("%i\n",brute());cout<<moze<<endl;
	return 0;
}