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
pair<ll,ll> dp[N][4][4];
pair<ll,ll> damage[N][4][4];
vector<pair<int,int> > niz;
int k;
pair<ll,ll> calc(int i,int tr,int tr2)
{
    if(i==k){
        if(tr==0&&tr2==0)
            return {0,-1};
        else
            return {LLONG_MIN/N,-1};
    }
    if(dp[i][tr][tr2]!=make_pair((ll)-1,(ll)-1))
        return dp[i][tr][tr2];
    dp[i][tr][tr2]=calc(i+1,tr,tr2);
    if(tr&&tr2>=niz[i].f)
        dp[i][tr][tr2]=max(dp[i][tr][tr2],{calc(i+1,tr-1,tr2-niz[i].f).f+niz[i].s,max(calc(i+1,tr-1,tr2-niz[i].f).s,(ll)niz[i].s)});
    return dp[i][tr][tr2];
}
ll sol[N][10];
int n;
ll ccalc(int i,int c)
{
    if(i==n)
        return 0;
    if(sol[i][c]!=-1)
        return sol[i][c];
    sol[i][c]=ccalc(i+1,c);
    for(int j=1;j<=3;j++)
    {
        for(int k=1;k<=3;k++)
        {
            pair<ll,ll> d=damage[i][k][j];
            if(c+k>9)
            {
                d.f+=d.s;
            }
            sol[i][c]=max(sol[i][c],ccalc(i+1,(c+k)%10)+d.f);
        }
    }
    return sol[i][c];
}
int main()
{
    memset(sol,-1,sizeof(sol));
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&k);
        niz.clear();
        niz.resize(k);
        for(int i=0;i<k;i++)
            scanf("%i %i",&niz[i].f,&niz[i].s);
        for(int i=0;i<k;i++)
            for(int j=0;j<=3;j++)
                for(int l=0;l<=3;l++)
                    dp[i][j][l]={-1,-1};
        for(int j=0;j<=3;j++)
            for(int l=0;l<=3;l++)
                damage[i][j][l]=calc(0,j,l);
    }
    printf("%lld\n",ccalc(0,0));
    return 0;
}