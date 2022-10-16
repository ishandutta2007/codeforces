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
vector<vector<int> > graf(10);
vector<int> visited(10);
bool dfs(int tr,int goal)
{
    if(tr==goal)
        return true;
    visited[tr]=1;
    for(auto p:graf[tr])
    {
        if(!visited[p])
        {
            if(dfs(p,goal))
                return true;
        }
    }
    return false;
}
int N=10;
vector<vector<int> > first(N);
vector<int> dodat(N);
vector<int> in(N);
vector<int> order;
void bfs(int tr)
{
    if(in[tr]==0){
        order.pb(tr);
        in[tr]--;
    }
    else
        in[tr]--;
    for(auto p:first[tr])
    {
        bfs(p);
    }
}
int main()
{
	vector<pair<int,int> > lift={mp(1,1),mp(1,2),mp(2,2),mp(2,1)};
	vector<pair<int,int> > wall_me={mp(0,0),mp(1,0),mp(2,0),mp(3,0),mp(3,1),mp(3,2),mp(3,3),mp(2,3),mp(1,3),mp(0,3),mp(0,2),mp(0,1)};
	vector<pair<pair<int,int>,int> > sta;
	int n;
	scanf("%i",&n);
	/*for(int i=0;i<3;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        sta.pb({a,b});
    }*/
    int matrica[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%i",&matrica[i][j]);
            if(matrica[i][j]==1)
            {
                graf[i].pb(j);
            }
        }
    }
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a=matrica[i][j];
            if(a==1){
                fill(visited.begin(),visited.end(),0);
                if(!dfs(j,i))
                {
                    //printf("%i %i\n",i,j);
                    first[i].pb(j);
                    in[j]++;
                    sta.pb({{i,j},2});
                }
                else
                    sta.pb({{i,j},1});
            }
        }
    }
    deque<int> nula;
    for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                nula.pb(i);
            }
        }
    while(nula.size())
    {
        int tr=nula.front();
        nula.pop_front();
        order.pb(tr);
        for(auto p:first[tr])
        {
            in[p]--;
            if(in[p]==0)
                nula.pb(p);
        }
    }
    printf("%i %i %i\n",5,sta.size()*4+1,2*n);
    char mat[sta.size()*4+1][5],mat2[sta.size()*4+1][5];
    memset(mat,'.',sizeof(mat));
    memset(mat2,'#',sizeof(mat2));
    for(int i=0;i<sta.size();i++)
    {
        int tr=i*4;
        for(auto p:wall_me)
        {
            mat[tr+p.first][p.second]='#';
        }
        for(auto p:lift)
        {
            mat2[tr+p.first][p.second]='.';
        }
    }
    vector<int> status(sta.size());
    int c=1;
    for(auto p:order)
    {
        char m[sta.size()*4+1][5];
        for(int x=0; x<sta.size()*4+1; x++)
        {
            for(int y=0; y<5; y++)
            {
                m[x][y]=mat[x][y];
            }
        }
        m[sta.size()*4][0]='1'+p;
        for(int i=0;i<sta.size();i++)
        {
            int tr=i*4;
            int x=sta[i].first.first;
            int y=sta[i].first.second;
            int k=sta[i].second;
            //printf("Usao za %i %i %i %i\n",x,y,k,p);
            if(status[i]>0)
            {
                //printf("Stavljam lift!\n");
                int delta=c-status[i];
                delta%=lift.size();
                m[tr+lift[delta].first][lift[delta].second]='#';
            }
            if(p==x)
            {
                //printf("Otvaram!\n");
                if(k==2)
                    status[i]=-1;
                else
                    status[i]=c;
                for(auto p:wall_me)
                {
                    m[tr+p.first][p.second]='.';
                }
            }
            if(p==y&&status[i]!=0)
            {
                //printf("Zatvaram!\n");
                status[i]=0;
                for(auto p:wall_me)
                {
                    m[tr+p.first][p.second]='.';
                }
            }
        }
        for(int x=0; x<sta.size()*4+1; x++)
        {
            for(int y=0; y<5; y++)
            {
                printf("%c",m[x][y]);
            }
            printf("\n");
        }
        printf("\n");
        c++;
        for(int x=0; x<sta.size()*4+1; x++)
        {
            for(int y=0; y<5; y++)
            {
                m[x][y]=mat2[x][y];
            }
        }
        for(int i=0;i<sta.size();i++)
        {
            int tr=i*4;
            int x=sta[i].first.first;
            int y=sta[i].first.second;
            int k=sta[i].second;
            if(status[i]>0)
            {
                int delta=c-status[i];
                assert(delta>=0);
                delta%=lift.size();
                m[tr+lift[delta].first][lift[delta].second]='#';
            }
            if(status[i]==0)
            {
                for(auto p:lift)
                {
                    m[tr+p.first][p.second]='#';
                }
            }
        }
        for(int x=0; x<sta.size()*4+1; x++)
        {
            for(int y=0; y<5; y++)
            {
                printf("%c",m[x][y]);
            }
            printf("\n");
        }
        printf("\n");
        c++;
    }
    return 0;
}