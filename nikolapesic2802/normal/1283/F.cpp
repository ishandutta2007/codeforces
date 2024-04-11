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

int main()
{
	int n;
	scanf("%i",&n);
	int nxtVal=n;
	vector<vector<int> > graf(n+1);
	vector<int> taken(n+1);
	int last;
	scanf("%i",&last);
	int start=last;
	if(last==nxtVal)
        nxtVal--;
    taken[last]=1;
    for(int i=2;i<n;i++){
        int tr;
        scanf("%i",&tr);
        if(taken[tr]){
            graf[last].pb(nxtVal);
            graf[nxtVal].pb(last);
            taken[nxtVal]=1;
            while(taken[nxtVal])
                nxtVal--;
            last=tr;
        }else{
            graf[last].pb(tr);
            graf[tr].pb(last);
            taken[tr]=1;
            while(taken[nxtVal])
                nxtVal--;
            last=tr;
        }
    }
    graf[last].pb(nxtVal);
    graf[nxtVal].pb(last);
    printf("%i\n",start);
    for(int i=1;i<=n;i++)
        for(auto p:graf[i])
            if(i<p)
                printf("%i %i\n",i,p);
    return 0;
}