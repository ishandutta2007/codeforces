#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define pb emplace_back
#define mp std::make_pair
#define fi first
#define se second
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}
template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}
template<typename T>
T &read(T &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
template<typename T1,typename... T2>
void read(T1 &x, T2& ...y){ read(x); read(y...); }
const int N=1000010;
int vis[N];
void solve(){
	string s,t,a;
	cin >> t >> s;
	int m=t.size();
	for(int i='A';i<='Z';i++)vis[i]=0;
	for(auto c:s)vis[c]++;
	for(int i=m-1;i>=0;i--){
		if(vis[t[i]]){
			--vis[t[i]];
			a.push_back(t[i]);
		}
	}
	reverse(a.begin(),a.end());
	if(a==s)puts("YES");
	else puts("NO");
}
signed main(){
	int T;read(T);
	while(T--)solve();
    #ifdef qawszx
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}