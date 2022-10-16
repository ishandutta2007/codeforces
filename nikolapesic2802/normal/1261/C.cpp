#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

vector<int> dx={0,0,1,-1,1,1,-1,-1},dy={1,-1,0,0,1,-1,1,-1};
int n,m;
const int N=1e6+1;
vector<string> mat(N),sol;
bool inside(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m&&mat[x][y]=='X';
}
vector<vector<int> > dist(N);
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	string em1(m,'.');
	for(int i=0;i<n;i++)
        cin >> mat[i],dist[i].resize(m),sol.pb(em1);
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!inside(i,j))
                continue;
            bool moze=true;
            for(int k=0;k<8;k++)
                if(!inside(i+dx[k],j+dy[k]))
                    moze=false;
            if(!moze)
                q.push({i,j}),dist[i][j]=1;
        }
    while(q.size())
    {
        int x=q.front().f,y=q.front().s;
        q.pop();
        for(int k=0;k<8;k++)
        {
            int xx=x+dx[k],yy=y+dy[k];
            if(inside(xx,yy)&&dist[xx][yy]==0)
                dist[xx][yy]=dist[x][y]+1,q.push({xx,yy});
        }
    }
    int l=0,r=min(n,m);
    while(l<r)
    {
        int mi=(l+r+1)>>1;
        vector<vector<int> > d(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dist[i][j]>mi)
                    q.push({i,j}),d[i][j]=1;
        while(q.size())
        {
            int x=q.front().f,y=q.front().s;
            q.pop();
            if(d[x][y]>mi)
                continue;
            for(int k=0;k<8;k++)
            {
                int xx=x+dx[k],yy=y+dy[k];
                if(inside(xx,yy)&&d[xx][yy]==0)
                    d[xx][yy]=d[x][y]+1,q.push({xx,yy});
            }
        }
        bool isto=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(inside(i,j)&&!d[i][j])
                    isto=false;
        if(!isto)
            r=mi-1;
        else
            l=mi;
    }
    cout << l << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(dist[i][j]>l)
                cout << "X";
            else
                cout << ".";
        cout << "\n";
    }
    return 0;
}