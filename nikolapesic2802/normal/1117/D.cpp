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

const int mod=1e9+7;
struct Matrix{
    int n,m;
    vector<vector<int> > polja;
    Matrix(int x,int y)
    {
        n=x;
        m=y;
        polja.resize(n,vector<int>(m));
    }
    void jedinicna()
    {
        for(int i=0;i<min(n,m);i++)
            polja[i][i]=1;
    }
    void init()
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                polja[i][j]=0;
        polja[0][0]=1;
        polja[n-1][0]=1;
        int x=0,y=1;
        while(y<m)
        {
            polja[x][y]=1;
            x++;
            y++;
        }
    }
    Matrix operator*(Matrix a)
    {
        Matrix c(n,a.m);
        assert(m==a.n);
        for(int i=0;i<n;i++)
            for(int j=0;j<a.m;j++)
            {
                int sum=0;
                for(int k=0;k<m;k++)
                {
                    sum+=(ll)polja[i][k]*a.polja[k][j]%mod;
                    sum%=mod;
                }
                c.polja[i][j]=sum;
            }
        return c;
    }
};
Matrix powmod(Matrix x,ll k)
{
    Matrix ans(x.n,x.m);
    ans.jedinicna();
    for(;k;k>>=1,x=x*x)
        if(k&1)
            ans=ans*x;
    return ans;
}
int main()
{
    ll n;
    int m;
    scanf("%lld %i",&n,&m);
    if(n<m)
    {
        printf("1\n");
        return 0;
    }
    Matrix p(m,m);
    p.init();
    p=powmod(p,n-m+1);
    Matrix sol(1,m);
    for(int i=0;i<m;i++)
        sol.polja[0][i]=1;
    sol=sol*p;
    printf("%i\n",sol.polja[0][0]);
    return 0;
}