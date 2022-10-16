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

const int N=1e6+5;
int n,k,l,dp[N],cnt[N];
string s;
void calc(int price){
	dp[n]=cnt[n]=0;
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1]+(s[i]>='a');
        cnt[i]=cnt[i+1];
        if(i+l<=n&&dp[i+l]+price<dp[i])
            dp[i]=dp[i+l]+price,cnt[i]=cnt[i+l]+1;
        if(i+l>n&&price<dp[i])
        	dp[i]=price,cnt[i]=1;
    }
}
int solveOne(){
    int le=0,ri=N;
	while(le<ri){
        int price=(le+ri)>>1;
        calc(price);
        if(cnt[0]>k)
            le=price+1;
        else
            ri=price;
	}
	calc(le);
	return dp[0]-le*k;
}
int solve(){
	int ans=solveOne();
	for(int i=0;i<n;i++)
        if(s[i]>='a')
            s[i]-='a'-'A';
        else
            s[i]-='A'-'a';
    return min(ans,solveOne());
}

void gen(int NMax,int kMax=-1,int lMax=-1){
	n=NMax-rng()%(NMax/10+1);
	if(kMax==-1)
		k=rng()%min(n,NMax+1)+1;
	else
		k=rng()%min(n,kMax+1)+1;
	if(lMax==-1)
		l=rng()%min(n,NMax)+1;
	else
		l=rng()%min(n,lMax)+1;
	int probUp=rng()%100000;
	s="";
	for(int i=0;i<n;i++){
		char c='a'+(rng()%26);
		if(rng()%100000<probUp)
			c+='A'-'a';
		s+=c;
	}
}
void savein(int x){
	string name="";
	name+='0'+(x/10);
	name+='0'+(x%10);
	name+=".in";
	ofstream out;
	out.open(name.c_str());
	out<<n<<" "<<k<<" "<<l<<"\n"<<s<<"\n";
	out.close();
}
void read(int x){
	string name="";
	name+='0'+(x/10);
	name+='0'+(x%10);
	name+=".in";
	ifstream in;
	in.open(name.c_str());
	in>>n>>k>>l>>s;
	in.close();
}
void read(){
	cin>>n>>k>>l>>s;
}
void saveout(int x){
	read(x);
	string name="";
	name+='0'+(x/10);
	name+='0'+(x%10);
	name+=".out";
	ofstream out;
	out.open(name.c_str());
	out<<solve()<<"\n";
	out.close();
}

int main()
{
	read();
	cout<<solve()<<endl;
	return 0;
	vector<pair<array<int,3>,string>> predefined={
		{{9,2,2},"aAaAAAaaA"},
		{{14,2,6},"aBcdEFGHIJklMn"},
		{{15,2,2},"AaAaAAaaAAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"},
		{{9,2,2},"aAaAAAaaA"}
		
	};
	for(int x=17;x<=17;x++){
		gen(2000,20,20);
		savein(x);
		saveout(x);
	}
	return 0;
}