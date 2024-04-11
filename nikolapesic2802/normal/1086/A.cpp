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
const int N=1e3+5;
int visited[N][N];
int main()
{
	vector<pair<int,int> > niz;
	for(int i=0;i<3;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        niz.pb({a,b});
    }
    vector<pair<int,int> > points;
    sort(all(niz));
    int x=niz[0].first;
    int y=niz[0].second;
    visited[x][y]=1;
    while(x!=niz[1].first)
    {
        x++;
        visited[x][y]=1;
    }
    while(y!=niz[1].second)
    {
        if(niz[1].second>y)
            y++;
        else
            y--;
        visited[x][y]=1;
    }
    x=niz[2].first;
    y=niz[2].second;
    visited[x][y]=1;
    while(x!=niz[1].first)
    {
        x--;
        visited[x][y]=1;
    }
    while(y!=niz[1].second)
    {
        if(niz[1].second>y)
            y++;
        else
            y--;
        visited[x][y]=1;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            if(visited[i][j])
            points.pb({i,j});
    }
    printf("%i\n",points.size());
    for(auto p:points)
    {
        printf("%i %i\n",p.first,p.second);
    }
    return 0;
}