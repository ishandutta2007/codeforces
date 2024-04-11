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

const int mod=998244353,N=101;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){
    return (ll)a*b%mod;
}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int dp[N][N],ch[N][N];
int nCk(int n,int k){
    if(k>n)
        return 0;
    int ans=1;
    for(int i=0;i<k;i++)
        ans=mul(ans,n-i);
    for(int i=1;i<=k;i++)
        ans=mul(ans,pwrmod(i,mod-2));
    return ans;
}
int get(int d,int num){
    if(num==0)
        return 1;
    int ans=0;
    for(int i=1;i<=num;i++)
        ans=add(ans,mul(nCk(d,i),ch[i][num]));
    return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ch[0][0]=1;
    for(int i=1;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=1;k<=j;k++)
                ch[i][j]=add(ch[i][j],ch[i-1][j-k]);
	int n;
	scanf("%i",&n);
	vector<pair<int,int> > a(n);
	set<int> gr;
	for(int i=0;i<n;i++)
        scanf("%i %i",&a[i].f,&a[i].s),gr.insert(a[i].f),gr.insert(a[i].s+1);
    reverse(all(a));
    vector<int> g;
    for(auto p:gr)
        g.pb(p);
    dp[0][0]=1;
    int m=g.size();
    for(int i=1;i<m;i++){
        int l=g[i-1],r=g[i]-1;
        //printf("%i %i!\n",l,r);
        for(int k=0;k<=n;k++){
            for(int j=k;j<=n;j++){
                dp[i][j]=add(dp[i][j],mul(dp[i-1][k],get(r-l+1,j-k)));
                if(j==n||a[j].f>r||a[j].s<l)
                    break;
            }
        }
    }
    //printf("%i!\n",dp[m-1][n]);
    for(int i=0;i<n;i++){
        dp[m-1][n]=mul(dp[m-1][n],pwrmod(a[i].s-a[i].f+1,mod-2));
        //printf("%i!\n",dp[m-1][n]);
    }
    printf("%i\n",dp[m-1][n]);
    return 0;
}