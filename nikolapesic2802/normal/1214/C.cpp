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

bool correct(deque<char> s)
{
    int tr=0;
    for(auto p:s){
        if(p=='(')
           tr++;
        else
            tr--;
        if(tr<0)
            return 0;
    }
    if(tr!=0)
        return 0;
    return 1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	deque<char> s1,s2;
	int first=INT_MAX,last=0,tr=0;
	for(int i=0;i<n;i++)
        if(s[i]=='(')
            last=i,tr++;
        else
            first=min(first,i),tr--;
    if(tr!=0)
    {
        printf("No\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=first)
            s1.pb(s[i]);
        if(i!=last)
            s2.pb(s[i]);
    }
    s2.push_front(s[last]);
    s1.push_back(s[first]);
    if(correct(s1)||correct(s2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}