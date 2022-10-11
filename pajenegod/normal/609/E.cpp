// testing Adshin21 code
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200500;

#define f first
#define s second

#define w f.f
#define id f.s
#define x s.f
#define y s.s

#define input(x,y,w,id) make_pair(make_pair(w,id),make_pair(x,y));

int arr[N]; //set
int sze[N]; //sze of particular set
int cost[N]; //the weight of that index

pair< pair<int,int > , pair<int,int> > graph[N];

bool visited[N];
int n,m,a,b,c;

int ans[N];

vector<int> pathu;
vector<int> pathv;

int Representative(int u)
{
    while( u != arr[u] )   u = arr[u];

    return u;
}

bool fnd(int u,int v)
{
    return Representative(u) == Representative(v);
}

void unin(int u,int v,int Z)
{
    u = Representative(u);
    v = Representative(v);

    if(sze[u]<sze[v]) swap(u,v);

    sze[u] += sze[v];
    arr[v] = u;
    cost[v] = Z;
}

int mst(){

	for(int i=1;i<=n;i++){
	    arr[i] = i;
	    sze[i] = 1;
	}
	sort(graph,graph+m);

	int mscost = 0;
	int edge = 0;
	for(int i = 0 ; i < m ; ++i){
		if(!fnd(graph[i].x , graph[i].y)){
			unin(graph[i].x , graph[i].y , graph[i].w);
			mscost += graph[i].w;
			visited[graph[i].id] = true;
			if(++edge==n-1)
				break;
		}
	}

	return mscost;
}

int32_t main(){
	cin >> n >> m;

	for(int i = 0 ; i < m ; ++i){
		cin >> a >> b >> c;
		graph[i] = input(a,b,c,i);
	}

	int total = mst();

	for(int i = 0 ; i < m ; ++i){

		int u = graph[i].x;
		int v = graph[i].y;
		int we = graph[i].w;
		int index = graph[i].id;

		if( visited[index] ){
			ans[index] = total;
		}
		else{

			pathu.clear();
			pathv.clear();

			pathu.push_back(u);
			pathv.push_back(v);

			while( u != arr[u]){
				u = arr[u];
				pathu.push_back(u);
			}

			while( v != arr[v]){
				v = arr[v];
				pathv.push_back(v);
			}

            assert(pathu.back()==pathv.back());
			int lca = u;

			while( !pathu.empty() && !pathv.empty() && pathu.back() == pathv.back() ){
				lca = pathu.back();
				pathu.pop_back();
				pathv.pop_back();
			}

			int maxedge = 0;

			u = graph[i].x;
			v = graph[i].y;

			while( u != lca ){
				maxedge = max( maxedge , cost[u]);
				u = arr[u];
			} 

			while( v != lca ){
				maxedge = max( maxedge , cost[v]);
				v = arr[v];
			}
            assert(maxedge>0);
			ans[index] = total + graph[i].w - maxedge;
		}
	}

	for(int i = 0 ; i < m ; ++i){
		cout << ans[i] << '\n';
	}

	return 0;
}