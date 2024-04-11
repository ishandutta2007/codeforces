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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	int n,k,m;
	scanf("%i %i %i",&n,&k,&m);
	vector<int> niz(n);
	for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    sort(all(niz));
    vector<ll> prefix(n);
    prefix[0]=niz[0];
    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+niz[i];
    double maxx=0;
    for(int i=0;i<n;i++)
    {
        if(i>m)
            break;
        ll sum=prefix[n-1];
        if(i!=0)
            sum-=prefix[i-1];
        int add=min((ll)(n-i)*k,(ll)m-i);
        maxx=max(maxx,(double)((double)sum+add)/(n-i));
    }
    printf("%.10f",maxx);
    return 0;
}