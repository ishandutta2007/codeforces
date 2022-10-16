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

const int N=3e5+5;
vector<int> a(N),nxt(N),minn(4*N);
void init(int l=0,int r=N-1,int i=1)
{
    if(l==r)
    {
        minn[i]=a[l];
        return;
    }
    int m=(l+r)>>1;
    init(l,m,2*i);
    init(m+1,r,2*i+1);
    minn[i]=min(minn[2*i],minn[2*i+1]);
}
int get(int qs,int qe,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return INT_MAX;
    if(qs<=l&&qe>=r)
        return minn[i];
    int m=(l+r)>>1;
    return min(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
        a[i+n]=a[i+2*n]=a[i];
    a[3*n]=INT_MAX;
    nxt[3*n]=3*n;
    nxt.resize(3*n+1);
    init();
    for(int i=3*n-1;i>=0;i--)
    {
        int lim=(a[i]-1)/2;
        int l=i,r=3*n;
        while(l<r)
        {
            int m=(l+r+1)>>1;
            if(get(i,m)<=lim)
                r=m-1;
            else
                l=m;
        }
        nxt[i]=min(nxt[i+1],l);
    }
    for(int i=0;i<n;i++)
    {
        if(nxt[i]==3*n)
            printf("-1 ");
        else
            printf("%i ",nxt[i]-i+1);
    }
    return 0;
}