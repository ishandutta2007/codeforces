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
	int q;
	scanf("%i",&q);
	while(q--)
    {
        int n,a;
        scanf("%i",&n);
        vector<int> l(n,-1),r(n,-1);
        for(int i=0;i<n;i++)
        {
            scanf("%i",&a);
            a--;
            if(l[a]==-1)
                l[a]=i;
            r[a]=i;
        }
        vector<pair<int,pair<int,int> > > nums;
        for(int i=0;i<n;i++)
            if(l[i]!=-1)
                nums.pb({i,{l[i],r[i]}});
        sort(all(nums));
        int sol=nums.size(),o=n,cnt=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i].s.s<o)
                o=nums[i].s.f,cnt++;
            else
                o=nums[i].s.f,cnt=1;
            sol=min(sol,(int)nums.size()-cnt);
        }
        printf("%i\n",sol);
    }
    return 0;
}