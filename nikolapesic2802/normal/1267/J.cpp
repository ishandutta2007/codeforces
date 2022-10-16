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
    int t;
    cin >> t;
    while(t--){
        int n,a;
        scanf("%i",&n);
        vector<int> cnt(n+1);
        ll oo=LLONG_MAX/n;
        vector<ll> sol(n+2);
        for(int i=0;i<n;i++)
            cin >> a,cnt[a]++;
        ll mn=oo;
        for(auto p:cnt){
            if(p==0)
                continue;
            mn=min(mn,(ll)p);
            for(int j=1;j<=p+1;j++){
                int puta=p/j,ostane=p%j;
                if(ostane==0){
                    sol[j]+=puta;
                    continue;
                }
                ostane=j-1-ostane;
                if(ostane>puta)
                    sol[j]+=oo;
                else
                    sol[j]+=puta+1;
            }
        }
        ll so=oo;
        for(int i=1;i<=mn+1;i++)
            so=min(so,sol[i]);
        printf("%lld\n",so);
    }
    return 0;
}