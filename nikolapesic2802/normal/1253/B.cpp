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
	vector<bool> in((int)1e6+1);
	vector<int> br((int)1e6+1);
	set<int> trDay;
	int cnt=0,last=-1;
	vector<int> sol;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a>0)
        {
            if(in[a])
                return 0*printf("-1\n");
            in[a]=1;
            br[a]++;
            if(br[a]>1)
                return 0*printf("-1\n");
            cnt++;
            trDay.insert(a);
        }
        else
        {
            a*=-1;
            if(!in[a])
                return 0*printf("-1\n");
            in[a]=0;
            cnt--;
        }
        if(cnt==0)
        {
            sol.pb(i-last);
            last=i;
            for(auto p:trDay)
                br[p]=0;
            trDay.clear();
        }
    }
    if(cnt!=0)
        return 0*printf("-1\n");
    printf("%i\n",sol.size());
    for(auto p:sol)
        printf("%i ",p);
    return 0;
}