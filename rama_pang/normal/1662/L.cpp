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

struct node{
	int s,e,m;
	int val=-1e9;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int k){
		val=max(val,k);
		
		if (s==e) return;
		if (i<=m) l->update(i,k);
		else r->update(i,k);
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root;

int n,k;
ii arr[200005];
vector<int> idx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	n++;
	rep(x,1,n) cin>>arr[x].se;
	rep(x,1,n) cin>>arr[x].fi;
	rep(x,0,n) arr[x].se*=k;
	
	rep(x,0,n) arr[x]={-arr[x].fi+arr[x].se,arr[x].fi+arr[x].se};
	
	vector<ll> uni;
	rep(x,0,n) uni.pub(arr[x].se);
	sort(all(uni));
	map<ll,int> m;
	rep(x,0,n) m[uni[x]]=x;
	rep(x,0,n) arr[x].se=m[arr[x].se];
	
	//rep(x,0,n) cout<<arr[x].fi<<" "<<arr[x].se<<endl;
	
	vector<int> idx;
	rep(x,0,n) idx.pub(x);
	sort(all(idx),[](int i,int j){
		if (arr[i].fi!=arr[j].fi) return arr[i].fi<arr[j].fi;
		else return arr[i].se<arr[j].se;
	});
	
	root=new node(0,n);
	
	int ans=0;
	for (auto &it:idx){
		//cout<<it<<" "<<arr[it].fi<<" "<<arr[it].se<<endl;
		
		int temp=root->query(0,arr[it].se);
		if (it==0) temp=max(temp,0);
		
		if (it) temp++;
		ans=max(ans,temp);
		root->update(arr[it].se,temp);
	}
	
	cout<<ans<<endl;
}