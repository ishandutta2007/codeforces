// Problem : F. RC Kaboom Show
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/F
// Memory Limit : 256 MB
// Time Limit : 6000 ms
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

struct pt{
	ll x,y;
	pt operator+(pt t){return {x+t.x,y+t.y};}
  pt operator-(pt t){return {x-t.x,y-t.y};}
  pt operator*(ll d){return {x*d,y*d};}
};
ll cross(pt v,pt w){return v.x*w.y-v.y*w.x;}
struct line{
    pt v;
    ll c;
    line(){}
    line(pt a,pt vv){v=vv;c=cross(v,a);}
};
struct car{
	int x,y,dx,dy,s;
};
vector<line> lines;
ld sol=(ld)LLONG_MAX*10;
bool dobro(int x,int dx,ld a){
	if(dx<0)
		return a<=x;
	return a>=x;
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<car> c(n);
	for(int i=0;i<n;i++)
		scanf("%i %i %i %i %i",&c[i].x,&c[i].y,&c[i].dx,&c[i].dy,&c[i].s);
	//printf("ok!\n");
	lines.resize(n);
	shuffle(all(c),rng);
	for(int i=0;i<n;i++){
		if(c[i].dx>0){
			line a({c[i].x,c[i].y},{c[i].dx,c[i].dy});
			lines[i]=a;
		}
		else{
			line a({c[i].x,c[i].y},{-c[i].dx,-c[i].dy});
			lines[i]=a;
		}
	}
	//printf("done!\n");
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int s=c[i].s+c[j].s;
			if(abs(c[i].x-c[j].x)+abs(c[i].y-c[j].y)>sol*s*s)
				continue;
			ll d=cross(lines[j].v,lines[i].v);
			if(d==0){
				if(lines[i].c==lines[j].c){
					ld x=(ld)(c[i].x+c[j].x)/2,y=(ld)(c[i].y+c[j].y)/2;
					if(dobro(c[i].x,c[i].dx,x)&&dobro(c[j].x,c[j].dx,x)){
						sol=min(sol,(ld)(abs(c[j].x-c[i].x)*abs(c[j].x-c[i].x)+abs(c[j].y-c[i].y)*abs(c[j].y-c[i].y))/(c[i].s+c[j].s)/(c[i].s+c[j].s));
						continue;
					}
					if(dobro(c[i].x,c[i].dx,x)){
						sol=min(sol,(ld)(abs(c[j].x-c[i].x)*abs(c[j].x-c[i].x)+abs(c[j].y-c[i].y)*abs(c[j].y-c[i].y))/(c[i].s)/(c[i].s));
					}
					if(dobro(c[j].x,c[j].dx,x)){
						sol=min(sol,(ld)(abs(c[j].x-c[i].x)*abs(c[j].x-c[i].x)+abs(c[j].y-c[i].y)*abs(c[j].y-c[i].y))/(c[j].s)/(c[j].s));
					}
				}
				continue;
			}
			pt p=(lines[i].v*lines[j].c-lines[j].v*lines[i].c);
			ld x=(ld)p.x/d,y=(ld)p.y/d;
			if(dobro(c[i].x,c[i].dx,x)&&dobro(c[j].x,c[j].dx,x)){
				ld d1=fabs(x-c[i].x)*fabs(x-c[i].x)+fabs(y-c[i].y)*fabs(y-c[i].y),d2=fabs(x-c[j].x)*fabs(x-c[j].x)+fabs(y-c[j].y)*fabs(y-c[j].y);
				sol=min(sol,max(d1/c[i].s/c[i].s,d2/c[j].s/c[j].s));
			}
		}
	}
	if(sol==(ld)LLONG_MAX*10)
		printf("No show :(\n");
	else
		printf("%.20Lf\n",sqrtl(sol));
	return 0;
}