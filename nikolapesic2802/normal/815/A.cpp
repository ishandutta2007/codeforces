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
int mat[N][N];
int diff[N][N];
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int mnf=INT_MAX;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%i",&mat[i][j]),mnf=min(mnf,mat[i][j]);
    for(int i=0;i<n;i++){
        int mn=INT_MAX;
        for(int j=0;j<m;j++)
            mn=min(mn,mat[i][j]);
        for(int j=0;j<m;j++)
            diff[i][j]=mat[i][j]-mn;
    }
    /*int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,diff[i][0]);
    }
    for(int i=0;i<n;i++){
        int d=mx-diff[i][0];
        for(int j=0;j<m;j++)
            diff[i][j]+=d;
    }*/
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(diff[i][j]!=diff[i-1][j]){
                printf("-1\n");
                return 0;
            }
        }
    }
    vector<int> cols,rows;
    if(n<m){
        for(int i=0;i<n;i++){
            for(int k=0;k<mnf;k++)
                rows.pb(i+1);
        }
    }else{
        for(int i=0;i<m;i++){
            for(int k=0;k<mnf;k++)
                cols.pb(i+1);
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mat[i][j]-=mnf;
    for(int j=0;j<m;j++)
        for(int k=0;k<diff[0][j];k++)
            cols.pb(j+1);
    for(int i=0;i<n;i++){
        int d=mat[i][0]-diff[i][0];
        for(int j=0;j<d;j++)
            rows.pb(i+1);
    }
    printf("%i\n",cols.size()+rows.size());
    for(auto p:cols)
        printf("col %i\n",p);
    for(auto p:rows)
        printf("row %i\n",p);
    return 0;
}