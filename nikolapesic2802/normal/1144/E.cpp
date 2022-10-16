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
    int k;
    scanf("%i",&k);
    string a,b;
    cin >> a >> b;
    vector<int> ukupno(k+1);
    for(int i=1;i<=k;i++)
        ukupno[i]=a[i-1]+b[i-1]-2*'a';
    int carry=0;
    for(int i=k;i>=0;i--)
    {
        int a=ukupno[i]+carry;
        carry=0;
        while(a>=26)
        {
            a-=26;
            carry++;
        }
        ukupno[i]=a;
    }
    assert(ukupno[k]%2==0);
    for(int i=0;i<=k;i++)
    {
        if(ukupno[i]%2==1)
            ukupno[i+1]+=26;
        ukupno[i]/=2;
    }
    string sol;
    for(int i=1;i<=k;i++)
        sol+=('a'+ukupno[i]);
    cout << sol;
    return 0;
}