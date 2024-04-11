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

set<pair<int,int> > s;
void insert(int a)
{
    auto it=s.lower_bound({a,0});
    if(it==s.end()||(*it).f!=a)
    {
        s.insert({a,1});
        return;
    }
    auto tr=(*it);
    s.erase(it);
    tr.s++;
    s.insert(tr);
}
void erase(int a)
{
    auto it=s.lower_bound({a,0});
    auto tr=(*it);
    s.erase(it);
    tr.s--;
    if(tr.s)
        s.insert(tr);
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<pair<int,int> > a(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i].f),a[i].s=i;
    sort(all(a));
    for(int i=0;i<n-1;i++)
        insert(a[i+1].f-a[i].f);
    for(int i=0;i<n;i++)
    {
        if(i)
            erase(a[i].f-a[i-1].f);
        if(i!=n-1)
            erase(a[i+1].f-a[i].f);
        if(i&&i!=n-1)
            insert(a[i+1].f-a[i-1].f);
        if(s.size()==1||s.size()==0)
        {
            printf("%i\n",a[i].s+1);
            return 0;
        }
        if(i)
            insert(a[i].f-a[i-1].f);
        if(i!=n-1)
            insert(a[i+1].f-a[i].f);
        if(i&&i!=n-1)
            erase(a[i+1].f-a[i-1].f);
    }
    printf("-1\n");
    return 0;
}