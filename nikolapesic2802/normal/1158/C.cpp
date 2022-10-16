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
vector<int> nxt;
pair<int,int> minn(pair<int,int> a,pair<int,int> b)
{
    if(a.f==b.f)
        if(a.s<b.s)
            return a;
        else
            return b;
    else
        if(a.f>b.f)
            return a;
        else
            return b;
}
struct segTree{
    vector<pair<int,int> > big;
    vector<int> mi;
    void build(int l,int r,int i)
    {
        if(l==r)
        {
            big[i]={nxt[l],l};
            mi[i]=-1;
            if(nxt[l]==-1)
                mi[i]=l;
            return;
        }
        int m=(l+r)>>1;
        build(l,m,2*i);
        build(m+1,r,2*i+1);
        big[i]=minn(big[2*i],big[2*i+1]);
        mi[i]=max(mi[2*i],mi[2*i+1]);
    }
    void init()
    {
        big.resize(4*n);
        mi.resize(4*n);
        build(0,n-1,1);
    }
    pair<int,int> get(int qs,int qe,int l=0,int r=n-1,int i=1)
    {
        if(qs>r||qe<l)
            return {-1,-1};
        if(qs<=l&&qe>=r)
            return big[i];
        int m=(l+r)>>1;
        return minn(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
    }
    int getmi(int qs,int qe,int l=0,int r=n-1,int i=1)
    {
        if(qs>r||qe<l)
            return -1;
        if(qs<=l&&qe>=r)
            return mi[i];
        int m=(l+r)>>1;
        return max(getmi(qs,qe,l,m,2*i),getmi(qs,qe,m+1,r,2*i+1));
    }
}st;
void test()
{
    scanf("%i",&n);
    nxt.clear();
    nxt.resize(n);
    for(int i=0;i<n;i++)
        scanf("%i",&nxt[i]);
    st.init();
    vector<int> sol(n);
    int tren=n;
    bool fail=false;
    function<void(int,int,int)> solve=[&](int l,int r,int look){\
        //printf("%i %i %i\n",l,r,look);
        if(l>r)
            return;
        auto tr=st.get(l,r);
        //cout << tr << endl;
        int pos=tr.s;
        if(tr.f!=look)
        {
            int gde=st.getmi(l,r);
            pos=gde;
            if(gde==-1){
                fail=true;
                return;
            }
        }
        sol[pos]=tren--;
        solve(l,pos-1,pos+1);
        solve(pos+1,r,look);
    };
    solve(0,n-1,n+1);
    if(fail)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<n;i++)
            printf("%i ",sol[i]);
        printf("\n");
    }
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
        test();
    return 0;
}