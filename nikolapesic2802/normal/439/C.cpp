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

const int N=1e6+5;
vector<int> par(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){par[find(a)]=find(b);}
int main()
{
    iota(all(par),0);
    int n,k,p;
    scanf("%i %i %i",&n,&k,&p);
    vector<int> a(n);
    vector<int> evens;
    vector<int> odds;
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
        if(a[i]&1)
            odds.pb(i);
        else
            evens.pb(i);
    while((int)odds.size()>k-p){
        if((int)odds.size()==1){
            printf("NO\n");
            return 0;
        }
        int a=odds.back();
        odds.pop_back();
        int b=odds.back();
        odds.pop_back();
        merge(a,b);
        evens.pb(find(a));
    }
    while((int)evens.size()>p){
        if((int)odds.size()>0){
            int a=evens.back();
            evens.pop_back();
            merge(a,odds.back());
            continue;
        }
        if((int)evens.size()==1){
            printf("NO\n");
            return 0;
        }
        int a=evens.back();
        evens.pop_back();
        int b=evens.back();
        merge(a,b);
    }
    if((int)evens.size()!=p||(int)odds.size()!=k-p)
    {
        printf("NO\n");
        return 0;
    }
    map<int,vector<int> > grupe;
    for(int i=0;i<n;i++)
        grupe[find(i)].pb(a[i]);
    printf("YES\n");
    for(auto p:grupe){
        printf("%i ",(int)p.s.size());
        for(auto d:p.s)
            printf("%i ",d);
        printf("\n");
    }
    return 0;
}