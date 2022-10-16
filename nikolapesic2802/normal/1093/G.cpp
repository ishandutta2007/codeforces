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
int K=(1<<5)+1;
vector<vector<int> > num(K);
struct segTree{
    vector<int> minn,maxx;
    int sz;
    void init(int n,int d)
    {
        sz=n;
        maxx.resize(2*n);
        minn.resize(2*n);
        for(int i=sz+1;i<2*sz;i++)
        {
            maxx[i]=minn[i]=num[d][i-sz-1];
        }
        for(int i=sz-1;i;i--)
        {
            maxx[i]=max(maxx[2*i],maxx[2*i+1]);
            minn[i]=min(minn[2*i],minn[2*i+1]);
        }
    }
    void set(int i,int a)
    {
        i+=sz;
        maxx[i]=a;
        minn[i]=a;
        for(i>>=1;i;i>>=1)
        {
            maxx[i]=max(maxx[2*i],maxx[2*i+1]);
            minn[i]=min(minn[2*i],minn[2*i+1]);
        }
    }
    int get(int l,int r)
    {
        int mi=INT_MAX,ma=INT_MIN;
        for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1)
        {
            if(l%2==1)
            {
                mi=min(mi,minn[l]);
                ma=max(ma,maxx[l]);
                l++;
            }
            if(r%2==0)
            {
                mi=min(mi,minn[r]);
                ma=max(ma,maxx[r]);
                r--;
            }
        }
        return ma-mi;
    }
};
int k;
vector<segTree> trees(K);
void add(vector<int> dim,int pos)
{
    for(int i=0;i<(1<<k);i++)
    {
        int sum=0;
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
                sum-=dim[j];
            else
                sum+=dim[j];
        }
        trees[i].set(pos,sum);
    }
}
int get(int l,int r)
{
    int best=0;
    for(int i=0;i<(1<<k);i++)
        best=max(best,trees[i].get(l,r));
    return best;
}
int main()
{
	int n;
	scanf("%i %i",&n,&k);
    for(int i=0;i<n;i++)
    {
        vector<int> d(k);
        for(int j=0;j<k;j++)
            scanf("%i",&d[j]);
        for(int mask=0; mask<(1<<k); mask++)
        {
            int sum=0;
            for(int j1=0; j1<k; j1++)
            {
                if(mask&(1<<j1))
                    sum-=d[j1];
                else
                    sum+=d[j1];
            }
            num[mask].pb(sum);
        }
    }
    for(int i=0;i<(1<<k);i++)
    {
        trees[i].init(n+1,i);
    }
    int q;
    scanf("%i",&q);
    for(int i=0;i<q;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==1)
        {
            int p;
            scanf("%i",&p);
            vector<int> d(k);
            for(int j=0;j<k;j++)
                scanf("%i",&d[j]);
            add(d,p);
        }
        else
        {
            int l,r;
            scanf("%i %i",&l,&r);
            printf("%i\n",get(l,r));
        }
    }
    return 0;
}