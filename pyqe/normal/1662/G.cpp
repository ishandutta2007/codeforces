// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> al[1000005];
int ss[1000005];
int d[1000005];

void dfs_ss(int i,int p){
	ss[i]=1;
	for (auto it:al[i]){
		if (it==p) continue;
		d[it]=d[i]+1;
		dfs_ss(it,i);
		ss[i]+=ss[it];
	}
}

priority_queue<int,vector<int>,greater<int> > pq;
bitset<1000005> bs;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a;
	rep(x,2,n+1){
		cin>>a;
		
		al[x].pub(a);
		al[a].pub(x);
	}
	
	dfs_ss(1,-1);
	int curr=1,currp=-1;
	
	while (true){
		bool done=true;
		for (auto it:al[curr]){
			if (it==currp) continue;
			
			if (ss[it]>=(n+1)/2){
				currp=curr;
				curr=it;
				done=false;
				break;
			}
		}
		
		if (done) break;
	}
	
	d[curr]=1;
	dfs_ss(curr,-1);
	
	int ans=0;
	
	bs[0]=1;
	for (auto it:al[curr]) pq.push(ss[it]);
	
	while (!pq.empty()){
		int temp=pq.top();
		
		int num=0;
		while (!pq.empty() && pq.top()==temp){
			num++;
			pq.pop();
		}
		
		while (num>=3){
			pq.push(2*temp);
			num-=2;
		}
		
		while (num){
			bs=bs|(bs<<temp);
			num--;
		}
	}
	
	rep(x,0,1000005) if (bs[x]) ans=max(ans,x*(n-1-x));
	
	rep(x,1,n+1) ans+=d[x];
	
	cout<<ans<<endl;
}