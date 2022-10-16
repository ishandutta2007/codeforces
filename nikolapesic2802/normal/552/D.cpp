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


int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
map<pair<int,pair<int,int> >,int> cnt;
map<int,int> aaa;
ll formula(int n){
    n=aaa[n];
    if(n<3)
        return 0;
    return (ll)n*(ll)(n-1)*(ll)(n-2)/6;
}
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<=n;i++){
        aaa[i*(i-1)/2]=i;
    }
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++)
        scanf("%i %i",&x[i],&y[i]);
    ll ans=(ll)n*(ll)(n-1)*(ll)(n-2)/6;
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        int xx=x[i]-x[j],yy=y[i]-y[j];
        int g=gcd(abs(xx),abs(yy));
        xx/=g;
        yy/=g;
        if(xx<0){
            xx*=-1;
            yy*=-1;
        }
        if(xx==0)
            yy=abs(yy);
        int coef=xx*y[i]-yy*x[i];
        cnt[{coef,{xx,yy}}]++;
    }
    for(auto p:cnt)
        ans-=formula(p.s);
    printf("%lld\n",ans);
    return 0;
}