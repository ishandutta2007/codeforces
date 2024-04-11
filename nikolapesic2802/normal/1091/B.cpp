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
	vector<pair<int,int> > cords;
	for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        cords.pb({a,b});
    }
    vector<pair<int,int> > ords;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        ords.pb({a,b});
    }
    map<pair<int,int>,int> mapa;
    for(int i=1;i<n;i++)
    {
        mapa[{ords[i].first,ords[i].second}]++;
    }
    for(int i=0;i<n;i++)
    {
        bool test=true;
        map<pair<int,int>,int> m=mapa;
        int x=cords[i].first+ords[0].first;
        int y=cords[i].second+ords[0].second;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            int xx=x-cords[j].first;
            int yy=y-cords[j].second;
            m[{xx,yy}]--;
            if(m[{xx,yy}]<0)
                {
                    test=false;
                    break;
                }
        }
        if(test)
        {
            printf("%i %i\n",x,y);
            return 0;
        }
    }
    return 0;
}