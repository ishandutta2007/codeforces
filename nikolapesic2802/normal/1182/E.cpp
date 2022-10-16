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

int mod=1e9+7;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
struct mat{
    int n,m;
    vector<vector<int> > mat;
};
mat operator*(mat a,mat b)
{
    mat sol;
    sol.mat.resize(a.n,vector<int>(b.m));
    sol.n=a.n;
    sol.m=b.m;
    assert(a.m==b.n);
    for(int i=0;i<a.n;i++)
        for(int j=0;j<b.m;j++){
            int pw=0;
            for(int k=0;k<a.m;k++)
                pw=add(pw,mul(a.mat[i][k],b.mat[k][j]));
            sol.mat[i][j]=pw;
        }
    return sol;
}
mat powr(mat x,ll k)
{
    mat ans=x;
    for(;k;k>>=1,x=x*x)
        if(k&1)
            ans=ans*x;
    return ans;
}
int main()
{
    mat f;
    f.mat.resize(3,vector<int>(3));
    f.n=f.m=3;
    f.mat[0][0]=f.mat[0][1]=f.mat[1][0]=f.mat[2][0]=f.mat[1][2]=1;
    mat f1,f2,f3;
    f1.mat.resize(1,vector<int>(3));
    f1.n=1;
    f1.m=3;
    f2=f3=f1;
    f1.mat[0][2]=1;
    f2.mat[0][1]=1;
    f3.mat[0][0]=1;
    mat C;
    C.mat.resize(5,vector<int>(5));
    C.mat[0][0]=C.mat[0][1]=C.mat[1][0]=C.mat[2][0]=C.mat[3][0]=C.mat[1][2]=C.mat[3][3]=C.mat[4][4]=C.mat[4][3]=1;
    C.n=C.m=5;
    mat c;
    c.n=1;
    c.m=5;
    c.mat.resize(1,vector<int>(5));
    c.mat[0][3]=2;
    c.mat[0][4]=2;
    ll n;
    int ff1,ff2,ff3,cc;
    scanf("%lld %i %i %i %i",&n,&ff1,&ff2,&ff3,&cc);
    mod--;
    f=powr(f,n-4);
    C=powr(C,n-4);
    f1=f1*f;
    f2=f2*f;
    f3=f3*f;
    c=c*C;
    mod++;
    printf("%i\n",mul(mul(powmod(ff1,f1.mat[0][0]),powmod(ff2,f2.mat[0][0])),mul(powmod(ff3,f3.mat[0][0]),powmod(cc,c.mat[0][0]))));
    return 0;
}