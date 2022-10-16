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
	int n;
	scanf("%i",&n);
	vector<int> niz(n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    vector<int> niz2(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz2[i]);
    }
    if(niz[0]!=niz2[0]||niz[n-1]!=niz2[n-1])
    {
        printf("No\n");
        return 0;
    }
    multiset<int> delta;
    for(int i=1;i<n;i++)
    {
        delta.insert(abs(niz[i]-niz[i-1]));
    }
    for(int i=1;i<n;i++)
    {
        int d=abs(niz2[i]-niz2[i-1]);
        if(!delta.count(d))
        {
            printf("No\n");
            return 0;
        }
        delta.erase(delta.find(d));
    }
    printf("Yes\n");
    return 0;
}