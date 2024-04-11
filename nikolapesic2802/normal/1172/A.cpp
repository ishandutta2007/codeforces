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
	vector<int> hand(n),deck(n);
	for(int i=0;i<n;i++)
        scanf("%i",&hand[i]);
    for(int j=0;j<n;j++)
        scanf("%i",&deck[j]);
    vector<int> activated(n+1);
    for(int i=0;i<n;i++)
        activated[hand[i]]=-hand[i];
    for(int i=0;i<n;i++)
        activated[deck[i]]=i+2-deck[i];
    bool slozeno=true;
    int dokle=deck[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(deck[i+1]==1)
            break;
        if(deck[i]!=deck[i+1]-1)
            slozeno=false;
    }
    if(slozeno)
    {
        for(int i=dokle+1;i<=n;i++)
            if(activated[i]>-dokle)
                slozeno=false;

        if(slozeno)
        {
            printf("%i\n",n-dokle);
            return 0;
        }
    }
    int sol=0;
    for(int i=1;i<=n;i++)
        sol=max(sol,activated[i]);
    printf("%i\n",n+sol);
    return 0;
}