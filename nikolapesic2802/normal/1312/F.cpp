//Grundy numbers :o, I don't think I'm gonna get this one :(. Maybe?


// Problem : F. Attack on Red Kingdom
// Contest : Educational Codeforces Round 83 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1312/problem/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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

vector<vector<int> > c(ll v){
	vector<vector<int> > sol(6,vector<int>(3));
	for(int j=0;j<3;j++)
		sol[5][j]=v%5,v/=5;
	for(int i=4;i>=0;i--)
		for(int j=0;j<3;j++)
			sol[i][j]=v%4,v/=4;
	return sol;
}
ll c(vector<vector<int> > sol){
	ll v=0;
	for(int i=0;i<=4;i++)
		for(int j=2;j>=0;j--)
			v=v*4+sol[i][j];
	for(int j=2;j>=0;j--)
		v=v*5+sol[5][j];
	return v;
}
map<ll,int> done;
bool imam[4];
vector<vector<int> > nxt(vector<vector<int> > sol){
	int x=sol[5][0]+1,y=sol[5][1]+1,z=sol[5][2]+1;
	vector<vector<int> > novi(6,vector<int>(3));
	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			novi[i][j]=sol[i+1][j];
	for(int j=0;j<3;j++)
		novi[5][j]=sol[5][j];
	memset(imam,0,sizeof imam);
	imam[sol[5-x][0]]=1;
	imam[sol[5-y][1]]=1;
	imam[sol[5-z][2]]=1;
	int mx;
	for(mx=0;;mx++)
		if(!imam[mx])
			break;
	novi[4][0]=mx;
	
	memset(imam,0,sizeof imam);
	imam[sol[5-x][0]]=1;
	imam[sol[5-z][2]]=1;
	for(mx=0;;mx++)
		if(!imam[mx])
			break;
	novi[4][1]=mx;
	
	memset(imam,0,sizeof imam);
	imam[sol[5-x][0]]=1;
	imam[sol[5-y][1]]=1;
	for(mx=0;;mx++)
		if(!imam[mx])
			break;
	novi[4][2]=mx;
	return novi;
}
/*vector<vector<int> > nap(vector<vector<int> > sol,ll koliko){
	if(koliko==0)
		return sol;
	return nap(nxt(sol),koliko-1);
}
*/
vector<vector<vector<int> > > redom[5][5][5];
pair<int,int> yes[5][5][5];
vector<vector<int> > napred(ll koliko,int x,int y,int z){
	if(koliko<=yes[x][y][z].f)
		return redom[x][y][z][koliko];
	koliko-=yes[x][y][z].f;
	return redom[x][y][z][yes[x][y][z].f+koliko%yes[x][y][z].s];
}
void cikSize(vector<vector<int> > sol,int x,int y,int z){
	ll tr=c(sol);
	redom[x][y][z].pb(sol);
	auto nx=nxt(sol);
	ll sl=c(nx);
	if(done.find(sl)==done.end()){
		done[sl]=done[tr]+1;
		cikSize(nx,x,y,z);
		return;
	}
	yes[x][y][z]={done[sl],done[tr]-done[sl]+1};
}

int main()
{
	for(int x=0;x<5;x++)
		for(int y=0;y<5;y++)
			for(int z=0;z<5;z++){
				vector<vector<int> > pocetni(6,vector<int>(3,0));
				pocetni[5][0]=x,pocetni[5][1]=y,pocetni[5][2]=z;
				done[c(pocetni)]=0;
				cikSize(pocetni,x,y,z);
			}
	int t;
	scanf("%i",&t);
	while(t--){
		int n,x,y,z;
		scanf("%i %i %i %i",&n,&x,&y,&z);
		vector<ll> a(n);
		vector<int> sufXor(n+1),ob(n);
		for(int i=0;i<n;i++){
			scanf("%lld\n",&a[i]);
			auto tr=napred(a[i],x-1,y-1,z-1);
			sufXor[i]=tr[4][0];
			ob[i]=tr[4][0];
		}
		int preXor=0;
		for(int i=n-2;i>=0;i--)
			sufXor[i]^=sufXor[i+1];
		int cnt=0;
		for(int i=0;i<n;i++){
			auto tr=napred(a[i]-1,x-1,y-1,z-1);
			if(tr[5-x][0]==(sufXor[i+1]^preXor))
				cnt++;
			if(tr[5-y][1]==(sufXor[i+1]^preXor))
				cnt++;
			if(tr[5-z][2]==(sufXor[i+1]^preXor))
				cnt++;
			preXor^=ob[i];
		}
		printf("%i\n",cnt);
	}
	return 0;
}