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
typedef pair<ll, ii> iii;

ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


int r, c;
ll q, p, cost[255][255], increment[255][255];
char arr[255][255];

int distance_(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

bool valid(int i, int j){
	return (i >=1 && i <= r && j >= 1 && j <= c && arr[i][j] != '*');
}

void process(iii val){
	
	int x = val.ss.ff, y = val.ss.ss;
	ll c = val.ff;
	queue<ii> qq;
	cost[x][y] += c;
	increment[x][y] = c;

	vector<ii> affected;
	affected.pb(ii(x, y));
	
	qq.push(ii(x, y));
	while(!qq.empty()){
		
		int i = qq.front().ff, j = qq.front().ss;
		qq.pop();
		
		if(increment[i][j]/2 == 0)	continue;
		
		if(valid(i-1, j) && increment[i-1][j] == 0){
			increment[i-1][j] = increment[i][j]/2;
			cost[i-1][j] += increment[i-1][j];
			qq.push(ii(i-1, j));
			affected.pb(ii(i-1, j));
		}

		if(valid(i+1, j) && increment[i+1][j] == 0){
			increment[i+1][j] = increment[i][j]/2;
			cost[i+1][j] += increment[i+1][j];
			qq.push(ii(i+1, j));
			affected.pb(ii(i+1, j));
		}

		if(valid(i, j-1) && increment[i][j-1] == 0){
			increment[i][j-1] = increment[i][j]/2;
			cost[i][j-1] += increment[i][j-1];
			qq.push(ii(i, j-1));
			affected.pb(ii(i, j-1));
		}

		if(valid(i, j+1) && increment[i][j+1] == 0){
			increment[i][j+1] = increment[i][j]/2;
			cost[i][j+1] += increment[i][j+1];
			qq.push(ii(i, j+1));
			affected.pb(ii(i, j+1));
		}
	}

	while(!affected.empty()){
		increment[affected.back().ff][affected.back().ss] = 0;
		affected.pop_back();
	}
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>r>>c>>q>>p;
    queue<iii> qq;
    for(int i=1;i<=r;i++){
    	cin>>(arr[i]+1);
    	for(int j=1;j<=c;j++)
    		if(arr[i][j] >= 'A' && arr[i][j] <= 'Z'){
    			qq.push(iii(q*(arr[i][j]-'A'+1), ii(i, j)));
    		}
    }

   	while(!qq.empty()){
   		process(qq.front());
   		qq.pop();
   	}

   	int ans = 0;
   	for(int i=1;i<=r;i++){
   		for(int j=1;j<=c;j++)
   			ans += cost[i][j] > p;
   	}

   	cout<<ans;
    return 0;
}