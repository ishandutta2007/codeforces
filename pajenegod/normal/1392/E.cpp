// NOT MY CODE
// https://codeforces.com/contest/1392/submission/90225397

#include <bits/stdc++.h>
namespace Suhaib_Templates {
    using namespace std;
    #define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false);
    #define Alhamdulillah return 0;
    typedef long long ll;
    typedef long double ld;
    #define debug(n) cerr << "[" << #n << " = " << n << "]" << '\n'
    #define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
    #define F_OR1(e) F_OR(i, 0, e, 1)
    #define F_OR2(i, e) F_OR(i, 0, e, 1)
    #define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
    #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
    #define GET5(a, b, c, d, e, ...) e
    #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
    #define lp(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
    #define each(a,x) for (auto& a: x)
    #define pb push_back
    #define ins insert
    #define sz(v) (int) v.size()
 
    ll FirstTrue (ll l,ll r,function<bool(ll)>f) {
        while(l<r){
        ll mid=l+(r-l)/2;
        f(mid)?r=mid:l=mid+1; } 
        return l;
    }
    ll LastTrue(ll l,ll r,function<bool(ll)>f) {
        while(l<r){
        ll mid=l+(r-l+1)/2;
        f(mid)?l=mid:r=mid-1;} 
        return l;
    }
     
    ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
 
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { lp(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { lp(i,SZ) re(a[i]); }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr(x.first,' ',x.second); 
    }
    template<class T> void prContain(const T& x) {
        each(a,x) pr(a,' '); 
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { cout << '\n'; } 
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...);
    }    
}
using namespace Suhaib_Templates;
 
 
 
void Suhaib_Sawalha (){
 
    int n;
    re(n);
 
    lp(n){
        lp(j,n){
            pr((i&1 ? 0 : 1ll<<(i+j)) , " ");
        }
        ps();
    }
 
    int q;
    re(q);
    while (q--){
        ll s;
        re(s);
        int x = 1 , y = 1;
        ps(x,y);
        lp(i,1,2 * n - 1){
            if ((s & (1ll<<i))){
                if (x&1)
                    ++y;
                else
                    ++x;
            }
            else {
                if(x&1)
                    ++x;
                else 
                    ++y;
            }
            ps(x,y);
        }
    }
 
}
 
int main(){
                                In_The_Name_Of_Allah_The_Merciful   /*      */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
// int _;cin>>_;for(int i=1;i<=_;++i,cout<<'\n')
        // cout<<"Case #"<<i<<":\n", 
        Suhaib_Sawalha();
                                         Alhamdulillah                    /*   */
}