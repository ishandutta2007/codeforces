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
vector<int> par(N),mx(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
int cnt=0;
void merge(int a,int b){mx[find(b)]=max(mx[find(a)],mx[find(b)]);par[find(a)]=find(b);}
int main()
{
    iota(all(par),0);
    iota(all(mx),0);
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        merge(a,b);
    }
    for(int i=0;i<n;i++)
    {
        int tr=find(i);
        int dokle=mx[tr];
        if(dokle!=i)
        {
            for(int j=i+1;j<dokle;j++){
                if(find(tr)!=find(j))
                    merge(tr,j),cnt++;
            }
            i=dokle-1;
        }
        else
            i=dokle;
    }
    printf("%i\n",cnt);
    return 0;
}