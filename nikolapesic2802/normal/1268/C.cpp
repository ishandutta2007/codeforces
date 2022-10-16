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

const int N=2e5+5;
vector<int> sum(4*N);
void sett(int pos,int l=0,int r=N-1,int i=1){
    if(l==r){
        sum[i]=1;
        return;
    }
    int m=(l+r)>>1;
    if(pos<=m)
        sett(pos,l,m,2*i);
    else
        sett(pos,m+1,r,2*i+1);
    sum[i]=sum[2*i]+sum[2*i+1];
}
ll get(int qs,int qe,int l=0,int r=N-1,int i=1){
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return r-l+1-sum[i];
    int m=(l+r)>>1;
    return get(qs,qe,l,m,2*i)+get(qs,qe,m+1,r,2*i+1);
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	vector<int> pos(n);
	ordered_set<int> ind;
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),a[i]--,pos[a[i]]=i;
    ll sol=0;
    int last=N-1;
    for(int i=0;i<n;i++){
        ind.insert(pos[i]);
        sett(pos[i]);
        sol+=get(min(last,pos[i]),max(last,pos[i]));
        int novo=*ind.find_by_order(i/2);
        int gde=ind.order_of_key(pos[i]);
        sol+=i-gde;
        if(pos[i]<last)
            sol-=gde;
        else{
            assert(pos[i]>last);
            sol-=i-gde;
        }
        int add=get(min(novo,last),max(novo,last));
        if(novo!=last){
            sol-=(ll)(i/2+1)*add;
            sol+=(ll)(i-i/2)*(add);
        }
        last=novo;
        printf("%lld ",sol);
    }
    return 0;
}