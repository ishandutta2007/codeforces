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
	vector<int> pos(n);
	vector<pair<int,int> > swaps;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        arr[i]=a-1;
        pos[a-1]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(pos[i]==i)
            continue;
        if(abs(pos[i]-i)*2>=n){
            swaps.pb({pos[i],i});
            swap(arr[i],arr[pos[i]]);
            swap(pos[i],pos[arr[pos[i]]]);
            continue;
        }
        if(abs(pos[i]-0)*2>=n&&abs(i-0)*2>=n)
        {
            swaps.pb({pos[i],0});
            swaps.pb({i,0});
            swaps.pb({pos[i],0});
            swap(arr[i],arr[pos[i]]);
            swap(pos[i],pos[arr[pos[i]]]);
            continue;
        }
        if(abs(pos[i]-n+1)*2>=n&&abs(i-n+1)*2>=n)
        {
            swaps.pb({pos[i],n-1});
            swaps.pb({i,n-1});
            swaps.pb({pos[i],n-1});
            swap(arr[i],arr[pos[i]]);
            swap(pos[i],pos[arr[pos[i]]]);
            continue;
        }
        if(abs(pos[i]-0)*2>=n)
        {
            swaps.pb({pos[i],0});
            swaps.pb({i,n-1});
            swaps.pb({0,n-1});
            swaps.pb({pos[i],0});
            swaps.pb({i,n-1});
            swap(arr[i],arr[pos[i]]);
            swap(pos[i],pos[arr[pos[i]]]);
            continue;
        }
        swaps.pb({pos[i],n-1});
        swaps.pb({i,0});
        swaps.pb({0,n-1});
        swaps.pb({pos[i],n-1});
        swaps.pb({i,0});
        swap(arr[i],arr[pos[i]]);
            swap(pos[i],pos[arr[pos[i]]]);
            continue;
    }
    printf("%i\n",swaps.size());
    for(auto p:swaps)
        printf("%i %i\n",p.f+1,p.s+1);
    return 0;
}