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
const int N=2e5+5;
vector<int> cnt(N);
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        cnt[a]++;
    }
    int l=0,r=0;
    int most=0,tr=0;
    int bl=-1,br=-1;
    for(int i=1;i<N;i++)
    {
        if(cnt[l]==0||cnt[i]==0)
        {
            l=r=i;
            tr=cnt[i];
            if(tr>most)
            {
                most=tr;
                bl=l;
                br=r;
            }
            continue;
        }
        if(l==r||cnt[r]>1)
        {
            r++;
            tr+=cnt[i];
            if(tr>most)
            {
                most=tr;
                bl=l;
                br=r;
            }
            continue;
        }
        assert(cnt[r]==1);
        l=i-1;
        r=i;
        tr=cnt[i]+cnt[i-1];
        if(tr>most)
        {
            most=tr;
            bl=l;
            br=r;
        }
    }
    printf("%i\n",most);
    for(int i=bl+1;i<br;i++)
        assert(cnt[i]>1);
    while(cnt[bl]--)
        printf("%i ",bl);
    for(int i=bl+1;i<=br;i++)
        while(cnt[i]>1)
            printf("%i ",i),cnt[i]--;
    for(int i=br;i>bl;i--)
        printf("%i ",i);
    printf("\n");
    return 0;
}