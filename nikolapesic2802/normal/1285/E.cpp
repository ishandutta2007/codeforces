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
vector<vector<pair<int,int> > > dodaj(4*N);
set<pair<int,int> > starts;
vector<vector<pair<int,pair<int,int> > > > obrisani;
vector<pair<int,pair<int,int> > > em;
void merge(int l,int r){
    obrisani.pb(em);
    auto it=starts.lower_bound({l,l});
    int rght=r;
    while((*it).f<=r)
        rght=max(rght,(*it).s),obrisani.back().pb({1,*it}),starts.erase(it),it=starts.lower_bound({l,l});
    int lft=l;
    if(it!=starts.begin()){
        it--;
        if((*it).s>=l){
            obrisani.back().pb({1,*it});
            lft=(*it).f;
            rght=max(rght,(*it).s);
            starts.erase(it);
        }
    }
    obrisani.back().pb({0,{lft,rght}});
    starts.insert({lft,rght});
}
void undo(){
    while(obrisani.back().size()){
        if(obrisani.back().back().f==0)
            starts.erase(obrisani.back().back().s);
        else
            starts.insert(obrisani.back().back().s);
        obrisani.back().pop_back();
    }
    obrisani.pop_back();
}
void add(int qs,int qe,pair<int,int> x,int l,int r,int i){
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r){
        dodaj[i].pb(x);
        return;
    }
    int m=(l+r)>>1;
    add(qs,qe,x,l,m,2*i);
    add(qs,qe,x,m+1,r,2*i+1);
}
int ans=0;
void solve(int l,int r,int i){
    //printf("%i-%i %i\n",l,r,i);
    //cout << dodaj[i] << endl;
    for(auto p:dodaj[i])
        merge(p.f,p.s);
    if(l==r){
        ans=max(ans,(int)starts.size());
        for(auto p:dodaj[i])
            undo();
        return;
    }
    int m=(l+r)>>1;
    solve(l,m,2*i);
    solve(m+1,r,2*i+1);
    for(auto p:dodaj[i])
        undo();
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%i",&t);
	while(t--){
        int n;
        scanf("%i",&n);
        starts.clear();
        starts.insert({INT_MAX,INT_MAX});
        for(int i=1;i<4*n;i++)
            dodaj[i].clear();
        ans=0;
        for(int i=0;i<n;i++){
            pair<int,int> x;
            scanf("%i %i",&x.f,&x.s);
            if(i)
                add(0,i-1,x,0,n-1,1);
            if(i!=n-1)
                add(i+1,n-1,x,0,n-1,1);
        }
        solve(0,n-1,1);
        printf("%i\n",ans-1);
	}
    return 0;
}