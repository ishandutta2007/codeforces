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

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> faktori;
    int tr=n;
    for(int i=2;i*i<=n;i++)
    {
        if(tr%i==0)
        {
            faktori.pb(i);
        }
        while(tr%i==0)
        {
            tr/=i;
        }
    }
    if(tr!=1)
        faktori.pb(tr);
    sort(all(faktori));
    if(faktori.size()==1)
    {
        printf("NO\n");
        return 0;
    }
    int prvi=faktori[0];
    int poslednji=faktori.back();
    int c1=0,c2=0;
    int diff=n-1;
    while(diff%prvi!=0)
    {
        diff-=poslednji;
        c1++;
    }
    c2=diff/prvi;
    printf("YES\n2\n%i %i\n%i %i\n",c1,n/poslednji,c2,n/prvi);
    return 0;
}