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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}



string str;
int sz, trie[5000002][5], endshere[5000002];


void insert(){
	int n = (int)str.length(), curr = 0;
	for(int i=0;i<n;i++){
		int dir = str[i] - 'a';
		if(trie[curr][dir] == -1)	trie[curr][dir] = ++sz;
		curr = trie[curr][dir];
	}
	endshere[curr]++;;
// cout<<"incremented at "<<curr<<endl;
}

set<int> yolo;

void calc(const string& str, int i, int node){
	if(node == -1)	return;
// cout<<"now at "<<str<<" "<<i<<" "<<node<<endl;
	if(i == (int)str.length()){
// cout<<i<<" "<<node<<" returns "<<endshere[node]<<endl;
		yolo.insert(node);
		return;
	}
	if(str[i] == '?'){
		calc(str, i+1, node);
		for(int j=0;j<5;j++){
			calc(str, i+1, trie[node][j]);
	 	}
	 	return;
	}
	calc(str, i+1, trie[node][str[i]-'a']);
}


int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(trie, -1, sizeof(trie));
    sz = 0;

    int n, m;
    cin>>n>>m;
    while(n--){
    	cin>>str;
    	insert();
    }

    while(m--){
    	cin>>str;
    	yolo.clear();
    	calc(str, 0, 0);
    	int ans = 0;
    	for(auto it : yolo)
    		ans += endshere[it];
    	cout<<ans<<endl;
    	// cout<<calc(str, 1, 1)<<endl;
    }

    return 0;
}