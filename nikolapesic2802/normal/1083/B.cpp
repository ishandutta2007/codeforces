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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
int n;
struct segTree{
    vector<ll> lazy;
    void init()
    {
        lazy.resize(4*n);
    }
    void prop(int i)
    {
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
    }
    void add(int qs,int qe,int x,int l=0,int r=n,int i=1)
    {
        //printf("dodajem %i %i %i\n",qs,qe,x);
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]+=(ll)x;
            return;
        }
        prop(i);
        int m=(l+r)>>1;
        add(qs,qe,x,l,m,2*i);
        add(qs,qe,x,m+1,r,2*i+1);
    }
    ll get(int p,int l=0,int r=n,int i=1)
    {
        if(l>p||r<p)
            return 0;
        if(l==r&&l==p)
            return lazy[i];
        prop(i);
        int m=(l+r)>>1;
        return get(p,l,m,2*i)+get(p,m+1,r,2*i+1);
    }
} ST;
int main()
{
	int k;
	scanf("%i %i",&n,&k);
	if(k==1)
    {
        printf("%i\n",n);
        return 0;
    }
    ST.init();
	char s[n+1],t[n+1];
	scanf("%s",s);
	scanf("%s",t);
	bool nasao=false;
	int ss=n;
	for(int i=0;i<n;i++)
    {
        if(nasao)
        {
            if(s[i]=='a')
            {
                ST.add(i,i,1);
            }
            if(t[i]=='b')
            {
                ST.add(i,i,1);
            }
            continue;
        }
        if(s[i]!=t[i])
        {
            ss=i;
            nasao=true;
            assert(s[i]=='a'&&t[i]=='b');
        }
    }
    ll res=ss+2*(n-ss);
    k-=2;
    for(int i=0;i<n;i++)
    {
        ll tr=ST.get(i);
        int br=min((ll)k,tr);
        if(br)
        {
            res+=(ll)(n-i)*br;
            k-=br;
            if(i<n-1)
                ST.add(i+1,n-1,br);
        }
    }
    printf("%lld\n",res);
    return 0;
}