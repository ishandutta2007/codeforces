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

const int N=5e5+5;
vector<int> primes;
vector<int> visited(N);
int main()
{
	for(int i=2;i<N;i++)
    {
        if(visited[i])
            continue;
        primes.pb(i);
        for(int j=i;j<N;j+=i)
            visited[j]=1;
    }
    int n;
    scanf("%i",&n);
    vector<int> cnt(3);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        cnt[a]++;
    }
    int tr=0;
    for(auto p:primes)
    {
        while(p-tr>=2&&cnt[2])
        {
            printf("2 ");
            cnt[2]--;
            tr+=2;
        }
        while(p-tr>=1&&cnt[1])
        {
            printf("1 ");
            cnt[1]--;
            tr++;
        }
    }
    return 0;
}