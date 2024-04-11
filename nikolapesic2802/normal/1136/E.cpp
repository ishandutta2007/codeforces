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

const int N=1e5+5;
vector<ll> sums(N),sumsum(N);
ll get_sum(int l,int r)
{
    if(l>r)
        return 0;
    return sums[r]-(l?sums[l-1]:0);
}
ll get2(int l,int r)
{
	if(l>r)
		return 0;
	return sumsum[r]-(l?sumsum[l-1]:0);
}
struct segTree{
    vector<ll> lazy,sum,position,sub;
    void init()
    {
        lazy.resize(4*N);
        sum.resize(4*N);
        position.resize(4*N,-1);
        sub.resize(4*N);
    }
    void prop(int i,int l,int r)
    {
        int m=(l+r)>>1;
        if(position[i]!=-1)
        {
            position[2*i]=position[i];
            position[2*i+1]=position[i]+m-l+1;
            position[i]=-1;
            lazy[2*i]=0;
            lazy[2*i+1]=0;
            sub[2*i]=sub[i];
            sub[2*i+1]=sub[i];
            sum[2*i]=get2(position[2*i],position[2*i]+m-l)-sums[sub[i]]*(m-l+1);
            sum[2*i+1]=get2(position[2*i+1],position[2*i+1]+r-m-1)-sums[sub[i]]*(r-m);
            sub[i]=0;
        }
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        sum[2*i]+=(ll)(m-l+1)*lazy[i];
        sum[2*i+1]+=(ll)(r-m)*lazy[i];
        lazy[i]=0;
    }
    void update(int i)
    {
        sum[i]=sum[2*i]+sum[2*i+1];
    }
    void add(int qs,int qe,ll x,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]+=x;
            sum[i]+=(ll)(r-l+1)*x;
            return;
        }
        int m=(l+r)>>1;
        prop(i,l,r);
        add(qs,qe,x,l,m,2*i);
        add(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    void set(int qs,int qe,int pos,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]=0;
            position[i]=l-qs+pos;
            sub[i]=pos;
            sum[i]=get2(position[i],position[i]+r-l)-sums[sub[i]]*(r-l+1);
            return;
        }
        int m=(l+r)>>1;
        prop(i,l,r);
        set(qs,qe,pos,l,m,2*i);
        set(qs,qe,pos,m+1,r,2*i+1);
        update(i);
    }
    ll get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return 0;
        if(qs<=l&&qe>=r)
            return sum[i];
        int m=(l+r)>>1;
        prop(i,l,r);
        return get(qs,qe,l,m,2*i)+get(qs,qe,m+1,r,2*i+1);
    }
}st;
int main()
{
    st.init();
	int n;
	scanf("%i",&n);
	set<int> unchanged;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        unchanged.insert(i);
        st.add(i,i,a);
    }
    unchanged.insert(n);
    for(int i=1;i<n;i++)
        scanf("%lld",&sums[i]);
    for(int i=2;i<n;i++)
        sums[i]+=sums[i-1];
    sumsum[1]=sums[1];
    for(int i=2;i<n;i++)
    	sumsum[i]+=sumsum[i-1]+sums[i];
    int q;
    scanf("%i",&q);
    while(q--)
    {
        string c;
        cin >> c;
        ll l,r;
        scanf("%lld %lld",&l,&r);
        //printf("%lld %lld\n",l,r);
        l--;
        if(c[0]=='s')
        {
            r--;
            printf("%lld\n",st.get(l,r));
        }
        else
        {
        	if(r==0&&!((int)unchanged.count(l+1)))
        		continue;
            r+=st.get(l,l);
            int start=l;
            int tr=start+1;
            while(tr<n)
            {
                int p=*unchanged.lower_bound(tr);
                if(p==n)
                {
                    tr=n-1;
                    break;
                }
                ll val=st.get(p,p);
                if((ll)r+get_sum(start+1,p)>val)
                {
                	unchanged.erase(p);
                    tr=p+1;
                }
                else
                {
                    tr=p-1;
                    break;
                }
            }
            if(tr==n)
                tr--;
            unchanged.insert(start);
            st.set(start,tr,start);
            st.add(start,tr,r);
        }
    }
    return 0;
}