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
	int n,m;
	scanf("%i %i",&n,&m);
	m--;
	int s;
	ll t;
	scanf("%i %lld",&s,&t);
	s--;
	int tr=s;
	ll step=t;
	ll num=t;
	vector<int> poz;
	vector<int> visited(n);
	int offset=0;
	ll broj=t/n;
	for(int i=0;i<num;i++)
    {
        if(tr<=m)
        {
            tr=(tr+step)%n;
        }
        else
        {
            tr=(tr-step)%n;
            if(tr<0)
                tr+=n;
        }
        step--;
        if(step%n==0)
        {
            if(visited[tr])
            {
                broj-=visited[tr]-1;
                offset=visited[tr]-1;
                break;
            }
            poz.pb(tr);
            visited[tr]=poz.size();

        }
    }
    printf("%i\n",poz[broj%(poz.size()-offset)+offset]+1);
    return 0;
}