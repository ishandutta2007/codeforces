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
	string s;
	cin >> s;
	int n=s.size();
	bool test=true;
	for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
            test=false;
    }
    if(n%2==1)
    {
        bool t2=true;
        string s2=s.substr(0,n/2)+s.substr(n/2+1,n/2);
        for(int i=0;i<n-2;i++)
        {
            if(s2[i]!=s2[i+1])
                t2=false;
        }
        if(t2)
        {
            printf("Impossible\n");
            return 0;
        }
    }
    if(test)
    {
        printf("Impossible\n");
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        string ne=s.substr(i+1,n-i-1)+s.substr(0,i+1);
        string ee=ne;
        reverse(all(ee));
        if(ee==ne&&ne!=s)
        {
            printf("1\n");
            return 0;
        }
    }
    printf("2\n");
    return 0;
}