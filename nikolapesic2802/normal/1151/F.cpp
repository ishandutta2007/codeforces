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
struct matrix{
    int x,y;
    vector<vector<int> > mat;
    matrix(int n,int m)
    {
        x=n,y=m;
        mat.resize(n,vector<int>(m));
    }
    matrix operator*(matrix a)
    {
        assert(y==a.x);
        matrix ret(x,a.y);
        for(int i=0;i<x;i++)
            for(int j=0;j<a.y;j++)
                for(int k=0;k<y;k++)
                    ret.mat[i][j]=add(ret.mat[i][j],mul(mat[i][k],a.mat[k][j]));
        return ret;
    }
};
matrix powmod(matrix x,int k)
{
    assert(x.x==x.y);
    matrix ans(x.x,x.y);
    for(int i=0;i<x.x;i++)
        ans.mat[i][i]=1;
    for(;k;k>>=1,x=x*x)
        if(k&1)
            ans=ans*x;
    return ans;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
    int br=0;
    vector<int> niz(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        if(niz[i]==0)
            br++;
    }
    int start=0;
    for(int i=0;i<br;i++)
        if(niz[i]==0)
            start++;
    matrix tr(1,br+1);
    tr.mat[0][start]++;
    matrix step(br+1,br+1);
    for(int i=0;i<=br;i++)
    {
        step.mat[i][i]+=br*(br-1)/2+(n-br)*(n-br-1)/2;
        int nl=i,nr=br-i,jl=br-i,jd=n-br-jl;
        step.mat[i][i]+=nl*nr+jl*jd;
        if(i)
            step.mat[i][i-1]+=nl*jd;
        if(i<br)
            step.mat[i][i+1]+=jl*nr;
    }
    step=powmod(step,k);
    tr=tr*step;
    int ukupno=0;
    for(int i=0;i<=br;i++)
        ukupno=add(ukupno,tr.mat[0][i]);
    ukupno=powmod(ukupno,mod-2);
    printf("%i\n",mul(tr.mat[0][br],ukupno));
    return 0;
}