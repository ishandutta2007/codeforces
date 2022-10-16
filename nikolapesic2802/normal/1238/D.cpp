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

bool palindrome(string s)
{
    if(s.size()==2)
        return s[0]==s[1];
    return s[0]==s[2];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	int a=n,b=n;
	vector<int> aa(n+1),bb(n+1);
	aa[n]=bb[n]=n;
    ll sol=0;
    for(int i=n-1;i>=0;i--)
    {
        aa[i]=a;
        bb[i]=b;
        if(s[i]=='A')
            a=i;
        else
            b=i;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]=='A')
        {
            if(s[i+1]=='A')
            {
                sol+=n-i-1;
                if(bb[i]!=n)
                    sol--;
            }
            else
                sol+=n-aa[i];
        }
        else
        {
            if(s[i+1]=='B')
            {
                sol+=n-i-1;
                if(aa[i]!=n)
                    sol--;
            }
            else
                sol+=n-bb[i];
        }
    }
    printf("%lld\n",sol);
    return 0;
}