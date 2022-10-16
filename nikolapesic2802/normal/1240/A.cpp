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
        int n;
        scanf("%i",&n);
        vector<int> aa(n);
        for(int i=0;i<n;i++)
            scanf("%i",&aa[i]);
        sort(all(aa));
        reverse(all(aa));
        int x,a,y,b;
        scanf("%i %i %i %i",&x,&a,&y,&b);
        ll k;
        scanf("%lld",&k);
        int l=0,r=n;
        while(l<r)
        {
            int m=(l+r)>>1;
            vector<int> cuts;
            for(int i=0;i<m;i++)
            {
                int tr=i+1;
                if(tr%a==0&&tr%b==0)
                    cuts.pb(x+y);
                else
                    if(tr%a==0)
                        cuts.pb(x);
                    else
                        if(tr%b==0)
                            cuts.pb(y);
            }
            sort(all(cuts));
            reverse(all(cuts));
            ll price=0;
            for(int i=0;i<cuts.size();i++)
                price+=aa[i]/100*cuts[i];
            if(price<k)
                l=m+1;
            else
                r=m;
        }
        vector<int> cuts;
        for(int i=0;i<l;i++)
        {
            int tr=i+1;
            if(tr%a==0&&tr%b==0)
                cuts.pb(x+y);
            else
                if(tr%a==0)
                    cuts.pb(x);
                else
                    if(tr%b==0)
                        cuts.pb(y);
        }
        sort(all(cuts));
        reverse(all(cuts));
        ll price=0;
        for(int i=0;i<cuts.size();i++)
            price+=aa[i]/100*cuts[i];
        if(price<k)
            printf("-1\n");
        else
            printf("%i\n",l);
    }
    return 0;
}