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
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int n,m;
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
bool inside(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n>> m;
    vector<string> mat(n);
    for(int i=0;i<n;i++)
        cin >> mat[i];
    vector<vector<vector<int> > > dist(3,vector<vector<int> >(n,vector<int>(m,-1)));
    vector<set<pair<int,pair<int,int> > > > q(3);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]=='.'||mat[i][j]=='#')
                continue;
            dist[mat[i][j]-'1'][i][j]=0;
            q[mat[i][j]-'1'].insert({0,{i,j}});
        }
    for(int k=0;k<3;k++)
    {
        while(q[k].size())
        {
            int x=(*q[k].begin()).s.f;
            int y=(*q[k].begin()).s.s;
            int d=(*q[k].begin()).f;
            q[k].erase(q[k].begin());
            if(d>dist[k][x][y])
                continue;
            for(int l=0;l<4;l++)
            {
                int xx=x+dx[l];
                int yy=y+dy[l];
                if(!inside(xx,yy)||mat[xx][yy]=='#')
                    continue;
                int mysol=dist[k][x][y]+1;
                if(mat[x][y]==mat[xx][yy]&&mat[xx][yy]!='.')
                    mysol--;
                if(dist[k][xx][yy]==-1)
                {
                    dist[k][xx][yy]=mysol;
                    q[k].insert({mysol,{xx,yy}});
                    continue;
                }
                if(dist[k][xx][yy]>mysol)
                {
                    dist[k][xx][yy]=mysol;
                    q[k].insert({mysol,{xx,yy}});
                }
            }
        }
    }
    int best=INT_MAX;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(dist[0][i][j]!=-1&&dist[1][i][j]!=-1&&dist[2][i][j]!=-1)
                best=min(best,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2);
    if(best>INT_MAX/5)
        printf("-1\n");
    else
        printf("%i\n",best);
    return 0;
}