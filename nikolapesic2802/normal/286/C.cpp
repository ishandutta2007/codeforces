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
int n;
vector<int> a;
vector<int> sol;
void input()
{
    scanf("%i",&n);
	a.resize(n);
	gp_hash_table<int,int> cnt;
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),cnt[a[i]]++;
    int t;
    scanf("%i",&t);
    while(t--)
    {
        int pos;
        scanf("%i",&pos);
        pos--;
        cnt[a[pos]]-=2;
        a[pos]*=-1;
    }
    for(auto p:cnt)
    {
        if(p.s<0||p.s%2==1)
        {
            printf("NO\n");
            exit(0);
        }
    }
}
vector<pair<int,int> > iza;
void match(int pos)
{
    vector<int> stk;
    if(a[pos]>0)
        a[pos]*=-1;
    stk.pb(-1*a[pos]);
    while(iza.size())
    {
        int tr=iza.back().f;
        int pp=iza.back().s;
        iza.pop_back();
        if(stk.back()==tr)
            stk.pop_back();
        else
            stk.pb(tr),a[pp]*=-1;
        if(stk.size()==0)
            return;
    }
    printf("NO\n");
    exit(0);
}
int main()
{
	input();
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
            match(i);
        else
            iza.pb({a[i],i});
    }
    while(iza.size())
    {
        int pos=iza.back().s;
        iza.pop_back();
        match(pos);
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
        printf("%i ",a[i]);
    return 0;
}