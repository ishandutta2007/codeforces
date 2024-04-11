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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int N=1e5+5;
vector<vector<int> > graf(N);
int visited[N][2];
pair<int,int> parent[N][2];
int visit[N];
bool ima;
void test(int tr)
{
    visit[tr]=1;
    for(auto p:graf[tr])
    {
        if(visit[p]==1)
            ima=true;
        if(visit[p]==0)
            test(p);
    }
    visit[tr]=2;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
    {
        int c;
        scanf("%i",&c);
        for(int j=0;j<c;j++)
        {
            int a;
            scanf("%i",&a);
            graf[i].pb(a-1);
        }
    }
    int s;
    scanf("%i",&s);
    s--;
    queue<pair<int,int> > q;
    q.push({s,0});
    visited[s][0]=1;
    parent[s][0]={-1,-1};
    pair<int,int> sol={-1,-1};
    while(q.size())
    {
        int tr=q.front().f;
        int player=q.front().s;
        if(player==1&&graf[tr].size()==0)
        {
            sol=q.front();
            break;
        }
        q.pop();
        int nxt=(player+1)%2;
        for(auto p:graf[tr])
        {
            if(visited[p][nxt])
                continue;
            visited[p][nxt]=1;
            parent[p][nxt]={tr,player};
            q.push({p,nxt});
        }
    }
    if(sol.f!=-1)
    {
        printf("Win\n");
        vector<int> moves;
        while(parent[sol.f][sol.s].f!=-1)
        {
            moves.pb(sol.f);
            sol=parent[sol.f][sol.s];
        }
        reverse(all(moves));
        printf("%i ",s+1);
        for(auto p:moves)
            printf("%i ",p+1);
    }
    else
    {
        test(s);
        if(ima)
            printf("Draw\n");
        else
            printf("Lose\n");
    }
    return 0;
}