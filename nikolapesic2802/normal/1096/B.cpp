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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int mod=998244353;
int main()
{
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	int l=1,r=1;
	int same=0;
	if(s[0]==s[n-1])
        same=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            l++;
        else
            break;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]==s[i+1])
            r++;
        else
            break;
    }
    ll ans=0;
    if(same)
    {
        if(l==n)
        {
            for(int i=1;i<=n;i++)
                ans+=n-i+1;
        }
        else
        {
            ans=(ll)(l+1)*(r+1);
        }
    }
    else
    {
        ans=l+1+r;
    }
    printf("%i\n",ans%mod);
    return 0;
}