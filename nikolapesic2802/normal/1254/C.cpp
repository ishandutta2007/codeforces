#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

vector<int> tacke;
ll ask(int t,int i,int j,int k)
{
    printf("%i %i %i %i\n",t,tacke[i]+1,tacke[j]+1,tacke[k]+1);
    fflush(stdout);
    ll a;
    scanf("%lld",&a);
    return a;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	tacke.resize(n);
	iota(all(tacke),0);
	int bst=1;
	for(int i=2;i<n;i++)
        if(ask(2,0,bst,i)<0)
            bst=i;
    swap(tacke[1],tacke[bst]);
    vector<pair<ll,int> > gde;
    for(int i=2;i<n;i++)
        gde.pb({ask(1,0,1,i),i});
    sort(all(gde));
    vector<int> l1,l2;
    l1.pb(0);
    l1.pb(1);
    l1.pb(gde[0].s);
    for(int i=1;i<(int)gde.size();i++)
    {
        if(ask(2,l1[l1.size()-2],l1[l1.size()-1],gde[i].s)<0)
            l2.pb(l1.back()),l1.pop_back();
        l1.pb(gde[i].s);
    }
    reverse(all(l2));
    printf("0 ");
    for(auto p:l1)
        printf("%i ",tacke[p]+1);
    for(auto p:l2)
        printf("%i ",tacke[p]+1);
    printf("\n");
    return 0;
}