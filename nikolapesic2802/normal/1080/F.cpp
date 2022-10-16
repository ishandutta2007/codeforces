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
int N;
vector<set<pair<int,int> > > niz;
struct segTree{
    vector<set<pair<int,int> > > arr;
    void init()
    {
        arr.resize((N)*4);
    }
    void set_all(int i=1,int l=1,int r=N-1)
    {
        //printf("Setujem %i %i %i\n",i,l,r);
        if(l==r)
        {
            arr[i]=niz[l];
            return;
        }
        int m=(l+r)>>1;
        set_all(2*i,l,m);
        set_all(2*i+1,m+1,r);
        vector<pair<int,pair<int,int> > > sve;
        for(auto p:arr[2*i])
        sve.pb({p.first,{p.second,1}});
        for(auto p:arr[2*i+1])
        sve.pb({p.first,{p.second,2}});
        sort(all(sve));
        reverse(all(sve));
        int minn1=INT_MAX,minn2=INT_MAX;
        for(auto p:sve)
        {
            if(p.second.second==1)
            {
                minn1=min(minn1,p.second.first);
                arr[i].insert({p.first,max(minn1,minn2)});
            }
            else
            {
                minn2=min(minn2,p.second.first);
                arr[i].insert({p.first,max(minn1,minn2)});
            }
        }
    }
    bool get(int qs,int qe,int x,int y,int i=1,int l=1,int r=N-1)
    {
        //printf("%i %i %i\n",i,l,r);
        if(qs>r||qe<l)
            return true;
        if(qs<=l&&qe>=r)
        {
            if(arr[i].lower_bound({x,0})==arr[i].end())
                return false;
            pair<int,int> lol=*arr[i].lower_bound({x,0});
            return lol.second<=y;
        }
        int m=(l+r)>>1;
        return get(qs,qe,x,y,2*i,l,m)&&get(qs,qe,x,y,2*i+1,m+1,r);
    }
} ST;
int main()
{
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	niz.resize(n+1);
	N=n+1;
	vector<vector<pair<int,int> > > seg(n+1);
	for(int i=0;i<k;i++)
    {
        int l,r,p;
        scanf("%i %i %i",&l,&r,&p);
        seg[p].pb({l,r});
    }
    for(int i=1;i<=n;i++)
    {
        sort(all(seg[i]));
        reverse(all(seg[i]));
        int minn=INT_MAX;
        for(auto p:seg[i])
        {
            minn=min(minn,p.second);
            niz[i].insert({p.first,minn});
            //printf("%i: %i %i\n",i,p.first,minn);
        }
    }
    ST.init();
    //printf("INIT!\n");
    ST.set_all();
    //printf("SET!\n");
    for(int i=0;i<m;i++)
    {
        int a,b,x,y;
        scanf("%i %i %i %i",&a,&b,&x,&y);
        if(ST.get(a,b,x,y))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        fflush(stdout);
    }
    return 0;
}