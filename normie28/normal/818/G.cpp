// Problem : G. Four Melodies
// Contest : Codeforces - Educational Codeforces Round 24
// URL : https://codeforces.com/contest/818/problem/G
// Memory Limit : 1024 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
        Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
struct Edge
{
    short from, to, capacity, cost;
    Edge(short _from, short _to, short _cap, short _cost)
    {
    	from=_from;
    	to=_to;
    	capacity=_cap;
    	cost=_cost;
    }
};

vector<vector<short>> adj, cost, capacity;

const short INF = 16000;

void shortest_paths(short n, short v0, vector<short>& d, vector<short>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<short> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        short u = q.front();
        q.pop();
        inq[u] = false;
        for (short v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

short min_cost_flow(short N, vector<Edge> edges, short K, short s, short t) {
    adj.assign(N, vector<short>());
    cost.assign(N, vector<short>(N, 0));
    capacity.assign(N, vector<short>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    short flow = 0;
    short cost = 0;
    vector<short> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        short f = K - flow;
        short cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}
vector<Edge> gr;
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
int arr[3001];
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> bmod[7];
vector<int> bval[100011];
int main()
{
        fio;
        cin>>n;
        for (i=1;i<=n;i++) cin>>arr[i];
        gr.emplace_back(0,1,4,0);
        for (i=1;i<=n;i++) gr.emplace_back(1,2*i,1,0);
        for (i=1;i<=n;i++) gr.emplace_back(2*i+1,2*n+2,1,0);
        gr.emplace_back(2*n+2,2*n+3,4,0);
        for (i=1;i<=n;i++) gr.emplace_back(2*i,2*i+1,1,-1);
        for (i=1;i<=n;i++)
        {
        	bval[arr[i]].push_back(i);
        	bmod[arr[i]%7].push_back(i);
        }
        for (i=0;i<7;i++) for (j=1;j<bmod[i].size();j++)
        gr.emplace_back(2*n+3+bmod[i][j-1],2*n+3+bmod[i][j],4,0);
        for (i=1;i<=100000;i++) for (j=1;j<bval[i].size();j++)
        gr.emplace_back(3*n+3+bval[i][j-1],3*n+3+bval[i][j],4,0);
        
        
        for (i=0;i<7;i++) for (j=0;j<bmod[i].size();j++)
        gr.emplace_back(2*n+3+bmod[i][j],2*bmod[i][j],1,0);
        for (i=1;i<=100000;i++) for (j=0;j<bval[i].size();j++)
        gr.emplace_back(3*n+3+bval[i][j],2*bval[i][j],1,0);
        for (i=1;i<=n;i++)
        {
        	auto it1=upper_bound(bmod[arr[i]%7].begin(),bmod[arr[i]%7].end(),i);
        	if (it1!=bmod[arr[i]%7].end()) 
        	gr.emplace_back(2*i+1,2*n+3+(*it1),1,0);
        	
        	
        	auto it2=upper_bound(bval[arr[i]-1].begin(),bval[arr[i]-1].end(),i);
        	if (it2!=bval[arr[i]-1].end()) 
        	gr.emplace_back(2*i+1,3*n+3+(*it2),1,0);
        	
        	
        	auto it3=upper_bound(bval[arr[i]+1].begin(),bval[arr[i]+1].end(),i);
        	if (it3!=bval[arr[i]+1].end()) 
        	gr.emplace_back(2*i+1,3*n+3+(*it3),1,0);
        }
        cout<<-min_cost_flow(4*n+4,gr,4,0,2*n+3);
        //cout<<endl<<gr.size();
}