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
	vector<pair<int,int> > niz(n);
	for(int i=0;i<n;i++)
        scanf("%i",&niz[i].first),niz[i].second=i,niz[i].first=n-niz[i].first;
    sort(all(niz));
    vector<int> sol(n);
    int cnt=1;
    for(int i=0;i<niz.size();)
    {
        int br=niz[i].first;
        for(int j=i;j<i+br;j++)
        {
            if(niz[j].first!=niz[i].first)
            {
                printf("Impossible\n");
                return 0;
            }
            sol[niz[j].second]=cnt;
        }
        i+=br;
        cnt++;
    }
    printf("Possible\n");
    for(auto p:sol)
        printf("%i ",p);
    return 0;
}