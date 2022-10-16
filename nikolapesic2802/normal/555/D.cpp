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
set<int> desno;
set<int,greater<int> > levo;
vector<int> arr(N);
map<int,int> ind;
int calc(int tr,int l,int d,int cnt)
{
    if(d==0)
    {
        auto it=desno.upper_bound(tr+l);
        it--;
        auto trr=(*it);
        int dd=trr-tr;
        if(cnt>1&&dd==0)
            return tr;
        if(cnt>1&&dd<l/2)
            return calc(tr,l%(dd*2),d,cnt);
        return calc(trr,l-dd,d^1,cnt+1);
    }
    auto it=levo.upper_bound(tr-l);
    it--;
    auto trr=(*it);
    int dd=tr-trr;
    if(cnt>1&&dd==0)
        return tr;
    if(cnt>1&&dd<l/2)
        return calc(tr,l%(dd*2),d,cnt);
    return calc(trr,l-dd,d^1,cnt+1);
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	desno.insert(INT_MAX);
	levo.insert(INT_MIN);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&arr[i]);
        ind[arr[i]]=i;
        desno.insert(arr[i]);
        levo.insert(arr[i]);
    }
    for(int i=0;i<m;i++)
    {
        int a,l;
        scanf("%i %i",&a,&l);
        printf("%i\n",ind[calc(arr[a-1],l,0,0)]+1);
    }
    return 0;
}