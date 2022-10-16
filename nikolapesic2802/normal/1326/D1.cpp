
// Problem : D2. Prefix-Suffix Palindrome (Hard version)
// Contest : Codeforces Global Round 7
// URL : http://codeforces.com/contest/1326/problem/D2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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

const int mod=1e9+7,puta=26; //998244353
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
const int N=1e6+1;
vector<int> pwrs(1,1);
void test(){
	string s;
		cin >> s;
		int n=s.size();
		int poc=0;
		for(int i=0;i<n/2;i++){
			if(s[i]==s[n-1-i])
				poc++;
			else
				break;
		}
		string po=s.substr(0,poc);
		s=s.substr(poc,n-2*poc);
		n-=2*poc;
		if(n==0){
			for(auto p:po)
				printf("%c",p);
			reverse(all(po));
			for(auto p:po)
				printf("%c",p);
			printf("\n");
			return;
		}
		vector<int> pre(n),suf(n);
		pre[0]=s[0]-'a';
		suf[n-1]=s[n-1]-'a';
		for(int i=1;i<n;i++){
			pre[i]=add(mul(pre[i-1],puta),s[i]-'a');
		}
		for(int i=n-2;i>=0;i--){
			suf[i]=add(mul(suf[i+1],puta),s[i]-'a');
		}
		for(int i=n;;i--){
			int a=0,b=i-1;
			int pr=pre[b];
			if(a)
				pr=sub(pr,mul(pre[a-1],pwrs[b-a+1]));
			int su=suf[a];
			if(b!=n-1)
				su=sub(su,mul(suf[b+1],pwrs[b-a+1]));
			if(pr==su){
				for(auto p:po)
					printf("%c",p);
				for(int i=a;i<=b;i++)
					printf("%c",s[i]);
				reverse(all(po));
				for(auto p:po)
					printf("%c",p);
				printf("\n");
				return;
			}
			a=n-i,b=n-1;
			pr=pre[b];
			if(a)
				pr=sub(pr,mul(pre[a-1],pwrs[b-a+1]));
			su=suf[a];
			if(b!=n-1)
				su=sub(su,mul(suf[b+1],pwrs[b-a+1]));
			if(pr==su){
				for(auto p:po)
					printf("%c",p);
				for(int i=a;i<=b;i++)
					printf("%c",s[i]);
				reverse(all(po));
				for(auto p:po)
					printf("%c",p);
				printf("\n");
				return;
			}
		}
}
int main()
{
	for(int i=1;i<N;i++)
		pwrs.pb(mul(pwrs.back(),puta));
	int t;
	scanf("%i",&t);
	while(t--){
		test();
	}
	return 0;
}