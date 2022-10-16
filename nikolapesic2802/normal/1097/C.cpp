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

int main()
{
	int n;
	scanf("%i",&n);
	vector<string> s(n);
	for(int i=0;i<n;i++)
        cin >> s[i];
    vector<int> c,o,ne;
    for(int i=0;i<n;i++)
    {
        int tr=0,minn=0,maxx=0;
        for(auto p:s[i])
        {
            if(p=='(')
            {
                tr++;
            }
            else
                tr--;
            maxx=max(maxx,tr);
            minn=min(minn,tr);
        }
        if(tr==0)
        {
            if(minn==0)
            {
                ne.pb(0);
            }
        }
        if(tr>0)
        {
            if(minn==0)
                o.pb(tr);
        }
        if(tr<0)
        {
            if(minn==tr)
                c.pb(-1*tr);
        }
    }
    sort(all(o));
    sort(all(c));
    int cnt=ne.size()/2;
    int i=0,j=0;
    while(i<o.size()&&j<c.size())
    {
        if(o[i]==c[j])
        {
            cnt++;
            i++;
            j++;
            continue;
        }
        if(o[i]<c[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("%i\n",cnt);
    return 0;
}