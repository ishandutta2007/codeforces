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
    int n,k;
    scanf("%i %i",&n,&k);
    vector<pair<int,int> > cmon;
    vector<int> niz(n),c(n);
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]),cmon.pb({niz[i],i});
    map<int,int> boja;
    for(int i=0;i<n;i++)
    {
        boja[niz[i]]++;
        if(boja[niz[i]]>k)
        {
            printf("NO\n");
            return 0;
        }
    }
    sort(all(cmon));
    int tr=0;
    for(auto p:cmon)
    {
        c[p.s]=tr+1;
        tr=(tr+1)%k;
    }
    printf("YES\n");
    for(auto p:c)
        printf("%i ",p);
    printf("\n");
    return 0;
}