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


const int N=2e5+5;
vector<ll> mn(4*N),lazy(4*N);
void prop(int i){
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    mn[2*i]+=lazy[i];
    mn[2*i+1]+=lazy[i];
    lazy[i]=0;
}
void add(int qs,int qe,ll a,int l=0,int r=N-1,int i=1){
    /*if(i==1)
        printf("%i-%i %lld\n",qs,qe,a);*/
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r){
        lazy[i]+=a;
        mn[i]+=a;
        return;
    }
    int m=(l+r)>>1;
    prop(i);
    add(qs,qe,a,l,m,2*i);
    add(qs,qe,a,m+1,r,2*i+1);
    mn[i]=min(mn[2*i],mn[2*i+1]);
}
ll get(int qs,int qe,int l=0,int r=N-1,int i=1){
    if(qs>r||qe<l)
        return LLONG_MAX;
    if(qs<=l&&qe>=r)
        return mn[i];
    int m=(l+r)>>1;
    prop(i);
    return min(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	vector<int> p(n),a(n),pos(n);
	for(int i=0;i<n;i++)
        scanf("%i",&p[i]),pos[p[i]-1]=i;
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        add(i,i,sum);
    }
    ll sol=get(0,n-2);
    for(int i=0;i<n;i++){
        int po=pos[i];
        add(po,n-1,-a[po]);
        add(0,po-1,a[po]);
        sol=min(sol,get(0,n-2));
    }
    printf("%lld\n",sol);
    return 0;
}