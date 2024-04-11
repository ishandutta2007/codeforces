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
vector<vector<int> > graf;
int n;
bool test(int k)
{
    for(int i=0;i<n;i++)
    {
        if(i+k>=n)
            return true;
        int tr=i+k;
        if(graf[tr].size()!=graf[i].size())
            return false;
        vector<int> jedan=graf[i];
        vector<int> dva=graf[tr];
        for(auto &p:dva)
            p-=k;
        for(auto &p:dva)
            if(p<0)
                p+=n;
        sort(all(jedan));
        sort(all(dva));
        if(jedan!=dva)
            return false;
    }
    return true;
}
int main()
{
	int m;
	scanf("%i %i",&n,&m);
	graf.resize(n);
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    if(test(1))
    {
        printf("Yes\n");
        return 0;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(test(i)||test(n/i))
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}