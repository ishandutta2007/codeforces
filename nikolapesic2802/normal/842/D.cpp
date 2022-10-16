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

const int N=(1<<20)+1;
vector<int> ima(N);
bool pun(int l,int r)
{
    int a=ima[r];
    if(l)
        a-=ima[l-1];
    return a==r-l+1;
}
int nadji(int x,int bit)
{
    if(bit<0)
        return x;
    int l=x,r=x;
    for(int j=bit-1;j>=0;j--)
        if(x&(1<<j))
            l-=1<<j;
        else
            r+=1<<j;
    if(pun(l,r))
        return nadji(x^(1<<bit),bit-1);
    return nadji(x,bit-1);
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int a;
	for(int i=0;i<n;i++)
        scanf("%i",&a),ima[a]=1;
    for(int i=1;i<N;i++)
        ima[i]+=ima[i-1];
    int xx=0;
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%i",&x);
        xx^=x;
        printf("%i\n",nadji(xx,20)^xx);
    }
    return 0;
}