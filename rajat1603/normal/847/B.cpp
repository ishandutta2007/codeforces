//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


const int N = 200002;
int n, arr[N], tree[4*N];

void build(int node, int s, int e){
	if(s > e)	return;
	if(s == e){
		tree[node] = arr[s];	return;
	}
	int mid = (s+e)/2;
	build(LEFT(node), s, mid);
	build(RIGHT(node), mid+1, e);
	tree[node] = max(tree[LEFT(node)], tree[RIGHT(node)]);
}


void update(int node, int s, int e, int pos, int val){
	if(s > e || pos < s || pos > e)	return;
	if(s == e){
		tree[node] = val;
		return;
	}
	int mid = (s + e)/2;
	update(LEFT(node), s, mid, pos, val);
	update(RIGHT(node), mid+1, e, pos, val);
	tree[node] = max(tree[LEFT(node)], tree[RIGHT(node)]);
}

int query(int node, int s, int e, int lo, int hi){
	if(s > e || lo > e || s > hi)	return 0;
	if(s >= lo && e <= hi)	return tree[node];
	int mid = (s + e)/2;
	int a = query(LEFT(node), s, mid, lo, hi);
	int b = query(RIGHT(node), mid+1, e, lo, hi);
	return max(a, b);
}


int get_first(){
	int lo = 1, hi = n, ans = n+1;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(query(1, 1, n, 1, mid) > 0){
			ans = min(ans, mid);
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return ans;
}

int get_next(int pos){
	int lo = pos+1, hi = n, ans = n+1;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(query(1, 1, n, pos+1, mid) > arr[pos]){
			ans = min(ans, mid);
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
// cout<<"get_next "<<pos<<" returns "<<ans<<endl;
	return ans;
}


int main(){

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    scanf("%d", &n);
    for(int i=1;i<=n;i++)	scanf("%d", &arr[i]);
    build(1, 1, n);

	int rem = n;
	while(rem > 0){

		int curr = get_first();
		while(curr <= n){
			rem--;
			printf("%d ", arr[curr]);
			update(1, 1, n, curr, 0);
			curr = get_next(curr);
		}

		printf("\n");
	}

    return 0;
}