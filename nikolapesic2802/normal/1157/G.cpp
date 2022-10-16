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

const int N=201;
int mat[N][N];
int n,m;
void check(string r)
{
    string sol(n,'0');
    int cnt=0,gde=0;
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            if(mat[i][j]!=mat[i][j-1])
                cnt++,gde=i;
    if(cnt>1)
        return;
    for(int i=0;i<n;i++)
    {
        if(i==gde)
        {
            if(mat[i][0]==1)
                for(int j=0;j<m;j++)
                    mat[i][j]^=1,sol[i]='1';
            for(int j=1;j<m;j++)
                if(mat[i][j]<mat[i][j-1])
                    return;
        }
        if(i<gde)
            if(mat[i][0]==1)
                sol[i]='1';
        if(i>gde)
            if(mat[i][0]==0)
                sol[i]='1';
    }
    printf("YES\n");
    cout << sol << endl << r << endl;
    exit(0);
}
int main()
{
	scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%i",&mat[i][j]);
    for(int i=0;i<n;i++)
    {
        string s;
        for(int j=0;j<m;j++)
            if(mat[i][j])
                s+='1';
            else
                s+='0';
        for(int j=0;j<m;j++)
            if(s[j]=='1')
                for(int i=0;i<n;i++)
                    mat[i][j]^=1;
        check(s);
        for(int j=0;j<m;j++)
            if(s[j]=='1')
                for(int i=0;i<n;i++)
                    mat[i][j]^=1;
    }
    printf("NO\n");
    return 0;
}