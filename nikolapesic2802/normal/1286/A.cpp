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
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=101;
int dp[N][N][N][3];
vector<int> a(N);
int n;
#define dp dp[tr][p][d][last]
int calc(int tr,int p,int d,int last){
    if(dp!=-1)
        return dp;
    if(tr==n){
        assert(p==0&&d==0);
        return 0;
    }
    if(a[tr]!=0){
        if(a[tr]&1){
            if(!d)
                return INT_MAX/N;
            dp=calc(tr+1,p,d-1,1)+(last==0);
            return dp;
        }else{
            if(!p)
                return INT_MAX/N;
            dp=calc(tr+1,p-1,d,0)+(last==1);
            return dp;
        }
    }
    dp=INT_MAX/N;
    if(p){
        dp=calc(tr+1,p-1,d,0)+(last==1);
    }
    if(d)
        dp=min(dp,calc(tr+1,p,d-1,1)+(last==0));
    return dp;
}
#undef dp
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
    scanf("%i",&n);
    int p=0,d=0;
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)
        if(i&1)
            d++;
    else
        p++;
    /*for(int i=0;i<n;i++)
        if(a[i]&1)
            d++;
    else
        p++;*/
    printf("%i\n",calc(0,p,d,2));
    return 0;
}