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
ll get(int l,int r)
{
    int n=(r-l);
    ll sum=(ll)(2*l-1)*(r-l+1)+(ll)n*(n+1);
    return sum;
}
int start=2;
int lim=2e5+5;
pair<int,int> find(int num)
{
    //printf("Trazim %i!\n",num);
    while(true)
    {
        if(start>lim)
        {
            printf("No\n");
            exit(0);
        }
        int l=0,r=lim-start+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(get(start,start+mid)<num)
                l=mid+1;
            else
                r=mid;
        }
        if(get(start,start+l)==num){
            //printf("Vracam %i %i\n",start,start+l);
            pair<int,int> res=make_pair(start,start+l);
            start+=l+1;
            return res;
        }
        start++;
    }
}
int main()
{
    //printf("%lld %lld\n",get(4,4),get(1,1));
	int n;
	scanf("%i",&n);
	vector<int> brojevi;
	vector<pair<int,int> > skokovi;
	for(int i=0;i<n/2;i++)
    {
        int a;
        scanf("%i",&a);
        skokovi.pb(find(a));
    }
    printf("Yes\n");
    int last=1;
    for(auto p:skokovi)
    {
        printf("%lld %lld ",get(last,p.first-1),get(p.first,p.second));
        last=p.second+1;
    }
    return 0;
}