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
	vector<int> cnt((int)3e5);
	int maxx=0;
	int koji=0;
	vector<int> a(n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
        cnt[a[i]]++;
        if(cnt[a[i]]>maxx)
        {
            maxx=cnt[a[i]];
            koji=a[i];
        }
    }
    vector<int> pos;
    for(int i=0;i<n;i++)
        if(a[i]==koji)
            pos.pb(i);
    int gde=pos[0];
    vector<pair<int,pair<int,int> > > op;
    for(int i=gde-1;i>=0;i--)
    {
        if(a[i]>koji)
        {
            op.pb({2,{i,i+1}});
        }
        else
        {
            op.pb({1,{i,i+1}});
        }
    }
    for(int i=gde+1;i<n;i++)
        if(a[i]!=koji)
        {
            if(a[i]>koji)
            {
                op.pb({2,{i,i-1}});
            }
            else
            {
                op.pb({1,{i,i-1}});
            }
        }
    printf("%i\n",op.size());
    for(auto p:op)
        printf("%i %i %i\n",p.f,p.s.f+1,p.s.s+1);
    return 0;
}