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
    int n,x,y;
    scanf("%i %i %i",&n,&x,&y);
    if(x>y)
    {
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%i",&a);
        }
        printf("%i\n",n);
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a<=x)
            cnt++;
    }
    printf("%i\n",(cnt+1)/2);
    return 0;
}