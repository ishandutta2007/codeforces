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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

inline int read()
{
	char ch=getchar();
	int s=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s*=10;
		s+=ch-48;
		ch=getchar();
	}
	return s;
}
int main()
{
	int n=read(),d;
    vector<int> a(n+1),unused,used(n+1);
	for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i])
            used[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
        if(!used[i])
            unused.pb(i);
	for(int i=1;i<=n;i++)
        if(a[i]==0&&!used[i])
            if(unused.back()==i)
                d=unused.back(),unused.pop_back(),a[i]=unused.back(),used[unused.back()]=1,unused.pop_back(),unused.pb(d);
            else
                a[i]=unused.back(),used[unused.back()]=1,unused.pop_back();
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            a[i]=unused.back(),unused.pop_back();
    for(int i=1;i<=n;i++)
        printf("%i ",a[i]);
}