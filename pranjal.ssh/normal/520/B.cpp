#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define X first
#define Y second
#define FOR(i,a,b) for(int i=a;i<=b;++i)

int a[10051];
queue<ii> q;
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    q.push(mp(n,1)); 
    int  N,cost;
    while(!q.empty())
    {
        N=q.front().X;
        cost=q.front().Y;
    //  cout<<N<<" "<<cost<<"\n";
        
       
        q.pop();
        if(a[N]!=0)
        continue;
        a[N]=cost;
        if(N==m)
        break;
        if(2*N<=10020)
        {
            q.push(mp(2*N,cost+1));
        }
        if(N>1)
        {
            q.push(mp(N-1,cost+1));
        }
    }
    cout<<a[m]-1;
    return 0;
}