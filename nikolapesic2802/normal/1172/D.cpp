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

const int N=1e3+5;
vector<int> a(N),b(N),Pa(N),Pb(N);
void swapujA(int i,int j)
{
    int aa=a[i],bb=a[j];
    swap(Pa[aa],Pa[bb]);
    swap(a[i],a[j]);
}
void swapujB(int i,int j)
{
    int aa=b[i],bb=b[j];
    swap(Pb[aa],Pb[bb]);
    swap(b[i],b[j]);
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
        a[i]--;
        Pa[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&b[i]);
        b[i]--;
        Pb[b[i]]=i;
    }
    vector<pair<pair<int,int>,pair<int,int> > > sol;
    for(int i=0;i<n;i++)
    {
        if(Pa[i]==i&&Pb[i]==i)
                continue;
        int aa=Pa[i],bb=Pb[i];
        swapujA(i,aa);
        swapujB(i,bb);
        sol.pb({{aa,i},{i,bb}});
    }
    printf("%i\n",sol.size());
    for(auto p:sol)
        printf("%i %i %i %i\n",p.f.f+1,p.f.s+1,p.s.f+1,p.s.s+1);

    return 0;
}