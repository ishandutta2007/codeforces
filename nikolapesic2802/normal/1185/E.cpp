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

void test()
{
    int n,m;
    cin >> n >> m;
    vector<string> board(n);
    for(int i=0;i<n;i++)
        cin >> board[i];
    vector<pair<pair<int,int>,pair<int,int> > > ans;
    vector<vector<pair<int,int> > > pozicije;
    for(int k=0;k<26;k++)
    {
        vector<pair<int,int> > pos;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='a'+k)
                    pos.pb({i,j});
            }
        }
        pozicije.pb(pos);
        if(pos.size()==0){
            ans.pb({{-1,-1},{-1,-1}});
            continue;
        }
        bool istiX=true,istiY=true;
        for(int i=1;i<(int)pos.size();i++){
            if(pos[i].f!=pos[0].f)
                istiX=false;
            if(pos[i].s!=pos[0].s)
                istiY=false;
        }
        if(!istiX&&!istiY)
        {
            printf("NO\n");
            return;
        }
        if(istiX)
        {
            int maxY=0,minY=INT_MAX;
            for(auto p:pos)
                maxY=max(maxY,p.s),minY=min(minY,p.s);
            ans.pb({{pos[0].f,minY},{pos[0].f,maxY}});
            continue;
        }
        if(istiY)
        {
            int maxY=0,minY=INT_MAX;
            for(auto p:pos)
                maxY=max(maxY,p.f),minY=min(minY,p.f);
            ans.pb({{minY,pos[0].s},{maxY,pos[0].s}});
        }
    }
    int maxx=-1;
    for(int k=0;k<26;k++)
        if(ans[k].f.f!=-1)
            maxx=k;
    vector<vector<bool> > visited(n,vector<bool>(m));
    int x,y;
    for(int k=maxx;k>=0;k--)
    {
        for(auto p:pozicije[k])
            visited[p.f][p.s]=1,x=p.f,y=p.s;
        if(ans[k].f.f==-1)
        {
            ans[k]={{x,y},{x,y}};
            continue;
        }
        if(ans[k].f.f==ans[k].s.f)
        {
            for(int j=ans[k].f.s;j<ans[k].s.s;j++)
            {
                if(!visited[ans[k].f.f][j])
                {
                    printf("NO\n");
                    return;
                }
            }
        }
        else
        {
            for(int j=ans[k].f.f;j<ans[k].s.f;j++)
            {
                if(!visited[j][ans[k].f.s])
                {
                    printf("NO\n");
                    return;
                }
            }
        }
    }
    printf("YES\n");
    printf("%i\n",maxx+1);
    for(int i=0;i<=maxx;i++)
    {
        printf("%i %i %i %i\n",ans[i].f.f+1,ans[i].f.s+1,ans[i].s.f+1,ans[i].s.s+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
        test();
    return 0;
}