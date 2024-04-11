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
		if(i>0&&i<sz(a))
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int N=1e5+1;
const int K=7e3+1;
vector<bitset<K> > bs;
vector<bool> on(K,true);
vector<bitset<K> > mults(K);
int main()
{
    for(int i=2;i<K;i++)
    {
        int t=i*i;
        for(int j=t;j<K;j+=t)
            on[j]=false;
    }
    for(int i=1;i<K;i++){
        for(int j=i;j<K;j+=i)
            if(on[j/i])
                mults[i][j]=1;
    }
	int n,q;
	scanf("%i %i",&n,&q);
	bs.resize(n+1);
	while(q--)
    {
        int t;
        scanf("%i",&t);
        int x,v,z;
        scanf("%i %i",&x,&v);
        if(t==1)
        {
            bs[x].reset();
            for(int i=1;i*i<=v;i++)
            {
                if(v%i==0)
                {
                    bs[x][i]=1;
                    bs[x][v/i]=1;
                }
            }
        }
        if(t==2)
        {
            scanf("%i",&z);
            bs[x]=bs[z]^bs[v];
        }
        if(t==3)
        {
            scanf("%i",&z);
            bs[x]=bs[z]&bs[v];
        }
        if(t==4)
        {
            printf("%i",(bs[x]&mults[v]).count()%2);
        }
    }
    return 0;
}