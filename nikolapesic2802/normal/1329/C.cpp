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
#define D(x) cerr << #x << " is " << (x) << "\n";
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

const int N=(1<<22)+5;
int a[N],nivo[N];
int h,g,gg;
set<pair<int,int> > sl;
bool moze(int tr,int nivo){
	int l=2*tr,r=2*tr+1;
	if(a[l]==0&&a[r]==0){
		return nivo!=gg;
	}
	if(a[l]>a[r])
		return moze(l,nivo+1);
	return moze(r,nivo+1);
}
void dodajNove(int tr){
	int l=2*tr,r=2*tr+1;
	if(a[l]==0&&a[r]==0)
		return;
	if(a[l]>a[r]){
		dodajNove(l);
		if(a[r]!=0)
			sl.insert({a[r],r});
	}
	else{
		dodajNove(r);
		if(a[l]!=0)
			sl.insert({a[l],l});
	}
}
void obrisi(int tr){
	int l=2*tr,r=2*tr+1;
	if(a[l]==0&&a[r]==0){
		a[tr]=0;
		return;
	}
	if(a[l]>a[r]){
		a[tr]=a[l];
		obrisi(l);
	}
	else{
		a[tr]=a[r];
		obrisi(r);
	}
}
void test(){
	scanf("%i %i",&h,&g);
	gg=g;
	h=1<<h;
	g=1<<g;
	ll sum=0;
	for(int i=1;i<=2*h;i++)
		a[i]=0;
	for(int i=1;i<h;i++){
		//a[i]=h-i;
		scanf("%i",&a[i]);
		sum+=a[i];
	}
	sl.clear();
	sl.insert({a[1],1});
	vector<int> operations;
	for(int i=0;i<h-g;i++){
		/*printf("%i: ",i);
		cout << sl << endl;
		for(int i=1;i<h;i++){
			printf("%i ",a[i]);
		}
		printf("\n");*/
		auto tr=*sl.begin();
		sl.erase(sl.begin());
		if(moze(tr.s,nivo[tr.s])){
			//printf("Moze!\n",tr.s);
			sum-=tr.f;
			obrisi(tr.s);
			operations.pb(tr.s);
			sl.insert({a[tr.s],tr.s});
		}
		else{
			dodajNove(tr.s);
			i--;
		}
	}
	printf("%lld\n",sum);
	for(auto p:operations)
		printf("%i ",p);
	printf("\n");
}
int main()
{
	nivo[1]=1;
	for(int i=2;i<N;i++)
		nivo[i]=nivo[i/2]+1;
	int t;
	scanf("%i",&t);
	while(t--){
		test();
	}
	return 0;
}