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
	ll sum=0;
	vector<int> niz(n);
	for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    sort(all(niz));
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(niz[i]==niz[i-1])
        {
            cnt++;
            if(niz[i]==0)
            {
                printf("cslnb\n");
                return 0;
            }
            if(i>1&&niz[i-2]==niz[i-1]-1)
            {
                printf("cslnb\n");
                return 0;
            }
            niz[i-1]--;
            sum++;
        }
    }
    if(cnt>1)
    {
        printf("cslnb\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        sum+=niz[i]-i;
    }
    if(sum%2==0)
        printf("cslnb\n");
    else
        printf("sjfnb\n");
    return 0;
}