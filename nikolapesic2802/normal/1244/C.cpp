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

const int N=101;
vector<int> par(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){par[find(a)]=find(b);}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    ll n,p,d,w;
    cin >> n >> p >> w >> d;
    for(int x=0;x<(int)1e5+5;x++){
        ll sum=x*w;
        ll ostatak=p-sum;
        if(ostatak<0)
            break;
        if(ostatak%d==0)
        {
            ll y=ostatak/d;
            if(x+y<=n){
                printf("%i %lld %lld\n",x,y,n-x-y);
                return 0;
            }
        }
    }
    for(int y=0;y<(int)1e5+5;y++){
        ll sum=y*d;
        ll ostatak=p-sum;
        if(ostatak<0)
            break;
        if(ostatak%w==0)
        {
            ll x=ostatak/w;
            if(x+y<=n){
                printf("%lld %i %lld\n",x,y,n-x-y);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}