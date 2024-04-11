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
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=40001,source=N-2,sink=N-1;
struct edge{
    int nxt,cap,rev,cost,ind;
};
vector<vector<edge> > graf(N);
void addEdge(int a,int b,int cap,int cost,int ind){
    //printf("%i-%i %i %i\n",a,b,cap,cost);
    edge ea={b,cap,graf[b].size(),cost,ind},eb={a,0,graf[a].size(),-cost,-1};
    graf[a].pb(ea);
    graf[b].pb(eb);
}
int flow,cost;
vector<int> dist(N),par(N);
vector<bool> in(N);
bool calcDist(){
    fill(all(dist),INT_MAX);
    fill(all(in),0);
    par[source]=-1;
    dist[source]=0;
    in[source]=1;
    queue<int> q;
    q.push(source);
    while(q.size()){
        auto tr=q.front();
        q.pop();
        in[tr]=0;
        for(auto p:graf[tr])
            if(p.cap&&dist[p.nxt]>dist[tr]+p.cost){
                dist[p.nxt]=dist[tr]+p.cost;
                par[p.nxt]=p.rev;
                if(!in[p.nxt])
                    in[p.nxt]=1,q.push(p.nxt);
            }
    }
    //printf("%i!\n",dist[sink]);
    return dist[sink]!=INT_MAX;
}
void update(){
    int tr=sink,mnFlow=INT_MAX;
    while(par[tr]!=-1)
        mnFlow=min(mnFlow,graf[graf[tr][par[tr]].nxt][graf[tr][par[tr]].rev].cap),tr=graf[tr][par[tr]].nxt;
    tr=sink;
    flow+=mnFlow;
    cost+=mnFlow*dist[sink];
    while(par[tr]!=-1)
        graf[tr][par[tr]].cap+=mnFlow,graf[graf[tr][par[tr]].nxt][graf[tr][par[tr]].rev].cap-=mnFlow,tr=graf[tr][par[tr]].nxt;
}
void mcmf(){
    while(calcDist()&&dist[sink]<=0)
        update();
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n1,n2,m,r,b;
    scanf("%i %i %i %i %i",&n1,&n2,&m,&r,&b);
    vector<int> red(n1+n2),blue(n1+n2),uncolored(n1+n2),degree(n1+n2);
    vector<pair<int,int> > edges;
    string colors,c2;
    cin >> colors >> c2;
    colors+=c2;
    for(int i=0;i<m;i++){
        int p,q;
        scanf("%i %i",&p,&q);
        p--;q--;
        q+=n1;
        addEdge(p,q,1,r,i);
        addEdge(q,p,1,b,i);
    }
    for(int i=0;i<n1+n2;i++){
        if(colors[i]=='U')
            addEdge(source,i,N,0,-1),addEdge(i,sink,N,0,-1);
        if(colors[i]=='R'){
            if(i<n1)
                addEdge(source,i,1,-N,-1),addEdge(source,i,N,0,-1);
            else
                addEdge(i,sink,1,-N,-1),addEdge(i,sink,N,0,-1);
            cost+=N;
        }
        if(colors[i]=='B'){
            if(i<n1)
                addEdge(i,sink,1,-N,-1),addEdge(i,sink,N,0,-1);
            else
                addEdge(source,i,1,-N,-1),addEdge(source,i,N,0,-1);
            cost+=N;
        }
    }
    mcmf();
    if(cost>=N)
        return 0*printf("-1\n");
    else
        printf("%i\n",cost);
    string sol(m,'U');
    for(int i=0;i<n1+n2;i++)
        for(auto p:graf[i])
            if(p.ind!=-1&&p.cap==0)
                sol[p.ind]=i<n1?'R':'B';
    cout << sol << endl;
}