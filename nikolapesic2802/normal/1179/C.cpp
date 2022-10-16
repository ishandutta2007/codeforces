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

const int N=1e6+1;
vector<int> maxx(4*N),lazy(4*N);
void prop(int i)
{
    maxx[2*i]+=lazy[i];
    maxx[2*i+1]+=lazy[i];
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    lazy[i]=0;
}
int findFirst(int l=0,int r=N-1,int i=1)
{
    if(maxx[i]<1)
        return -1;
    if(l==r)
        return l;
    prop(i);
    int m=(l+r)>>1;
    if(maxx[2*i+1]>=1)
        return findFirst(m+1,r,2*i+1);
    return findFirst(l,m,2*i);
}
void add(int qs,int qe,int val,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        maxx[i]+=val;
        lazy[i]+=val;
        return;
    }
    int m=(l+r)>>1;
    prop(i);
    add(qs,qe,val,l,m,2*i);
    add(qs,qe,val,m+1,r,2*i+1);
    maxx[i]=max(maxx[2*i],maxx[2*i+1]);
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),add(0,a[i],1);
    for(int i=0;i<m;i++)
        scanf("%i",&b[i]),add(0,b[i],-1);
    int q;
    scanf("%i",&q);
    while(q--)
    {
        int t,i,x;
        scanf("%i %i %i",&t,&i,&x);
        i--;
        if(t==1)
            add(0,a[i],-1),add(0,x,1),a[i]=x;
        if(t==2)
            add(0,b[i],1),add(0,x,-1),b[i]=x;
        printf("%i\n",findFirst());
    }
    return 0;
}