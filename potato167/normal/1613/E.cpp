#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=x,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
}



void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int h,w;
	cin>>h>>w;
	vector<vector<char>> p(h+2,vector<char>(w+2,'#'));
	rep(i,h) rep(j,w) cin>>p[i+1][j+1];
	vector<vector<int>> dp(h+2,vector<int>(w+2,-1));
	vector<int> dx={-1,0,0,1},dy={0,1,-1,0};
	queue<pair<int,int>> q;
	rep(i,h) rep(j,w){
		if(p[i+1][j+1]=='#') continue;
		if(p[i+1][j+1]=='L') q.push({i+1,j+1});
		else{
			dp[i+1][j+1]++;
			rep(k,4){
				if(p[i+1+dx[k]][j+1+dy[k]]!='#') dp[i+1][j+1]++;
			}
		}
	}
	/*rep(i,h){
		rep(j,w) cout<<dp[1+i][j+1];
		cout<<"\n";
	}*/
	while(!q.empty()){
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		if(p[x][y]!='L') p[x][y]='+';
		rep(k,4){
			int s=x+dx[k],t=y+dy[k];
			dp[s][t]--;
			if(dp[s][t]==1) q.push({s,t});
			if(dp[s][t]==0) p[s][t]='+';
		}
	}
	rep(i,h){
		rep(j,w){
			cout<<p[i+1][j+1];
		}
		cout<<"\n";
	}
}