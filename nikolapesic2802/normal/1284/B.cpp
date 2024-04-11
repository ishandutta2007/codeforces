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

int main()
{
	int n,N=1e6+5;
	scanf("%i",&n);
	vector<int> seq;
	vector<int> cnt(N);
	ll ans=0;
	int cntIma=0;
	for(int i=0;i<n;i++){
        int k;
        scanf("%i",&k);
        vector<int> a(k);
        int mx=0,mn=INT_MAX;
        for(int i=0;i<k;i++)
            scanf("%i",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
        bool ima=false;
        for(int j=1;j<k;j++)
            if(a[j]>a[j-1])
                ima=true;
        if(ima){
            cntIma++;
        }else{
            seq.pb(a.back());
            cnt[mx]++;
        }
	}
	ans+=(ll)cntIma*(n-cntIma)*2+(ll)cntIma*(cntIma);
	for(int i=N-1;i>=0;i--)
        cnt[i]+=cnt[i+1];
	for(auto p:seq){
        ans+=cnt[p+1];
	}
    printf("%lld\n",ans);
    return 0;
}