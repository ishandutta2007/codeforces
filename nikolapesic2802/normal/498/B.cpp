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
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	int n,T;
	scanf("%i %i",&n,&T);
	vector<ld> dp(T+1),sl(T+1);
	dp[0]=1;
	ld sol=0;
	for(int i=1;i<=n;i++)
    {
        int p,t;
        scanf("%i %i",&p,&t);
        ld yes=(ld)p/100,no=1-yes;
        ld nono=pow(no,t-1);
        ld trsol=0;
        int l=0,r=-1;
        sl[0]=0;
        for(int j=1;j<=T;j++)
        {
            r++;
            trsol*=no;
            trsol+=dp[j-1]*yes;
            if(r-l+1==t)
                trsol-=nono*yes*dp[l],l++;
            sl[j]=trsol;
            if(j-t>=0)
                sl[j]+=nono*dp[j-t];
            sol+=sl[j];
        }
        for(int j=0;j<=T;j++)
            dp[j]=sl[j];
    }
    printf("%.10Lf\n",sol);
    return 0;
}