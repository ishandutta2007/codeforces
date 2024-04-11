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
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
int n,m,p;
bool inside(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
int main()
{

	scanf("%i %i %i",&n,&m,&p);
	vector<int> speed(p);
	for(int i=0;i<p;i++)
        scanf("%i",&speed[i]);
    vector<vector<int> > visited(n,vector<int>(m));
    vector<queue<pair<pair<int,int>,int> > > q(p);
    vector<queue<pair<pair<int,int>,int> > > new_q(p);
    vector<int> sol(p);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        char s[m];
        scanf("%s",s);
        for(int j=0;j<m;j++)
        {
            if(s[j]>='1'&&s[j]<='9')
            {
                int tr=s[j]-'1';
                q[tr].push({{i,j},0});
                visited[i][j]=1;
                sol[tr]++;
                cnt++;
            }
            if(s[j]=='#')
                visited[i][j]=1,cnt++;
        }
    }
    //printf("%i\n",cnt);
    bool dodao=true;
    while(dodao)
    {
        dodao=false;
        //printf("%i\n",cnt);
        for(int i=0;i<p;i++)
        {
            while(q[i].size())
            {
                int x=q[i].front().f.f;
                int y=q[i].front().f.s;
                int tr=q[i].front().s;
                //printf("%i %i %i %i %i\n",x,y,tr,i,speed[i]);
                q[i].pop();
                if(tr==speed[i])
                {
                    new_q[i].push({{x,y},0});
                    continue;
                }
                //printf("WUT!\n");
                for(int k=0;k<4;k++)
                {
                    int xx=x+dx[k];
                    int yy=y+dy[k];
                    if(!inside(xx,yy)||visited[xx][yy]==1)
                        continue;
                    sol[i]++;
                    cnt++;
                    visited[xx][yy]=1;
                    q[i].push({{xx,yy},tr+1});
                }
            }
            while(new_q[i].size())
            {
                dodao=true;
                q[i].push(new_q[i].front());
                new_q[i].pop();
            }
        }
    }
    for(int i=0;i<p;i++)
        printf("%i ",sol[i]);
    return 0;
}