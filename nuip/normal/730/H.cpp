#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int main(){
	int N, M, a[105];
	string name[105];
	cin >> N >> M;
	rep(i,N) cin >> name[i];
	rep(i,M){
		cin >> a[i];
		a[i]--;
	}
	
	bool ans = true;
	string reg = name[ a[0] ];
	rep(i,M)if( reg.size() != name[a[i]].size() ) ans = false;
	if(ans) rep(k,reg.size()){
		int cnt[127]={}, sum=0;
		rep(i,M) cnt[ name[ a[i] ][k] ]++;
		rep(i,127) if(cnt[i]) sum++;
		if( sum > 1 ) reg[k] = '?';
	}
	//cout << reg << endl;
	rep(i,M) name[ a[i] ] += "#";
	if(ans) rep(i,N){
		if( reg.size() != name[i].size() ) continue;
		bool b = true;
		rep(k,reg.size()){
			if( reg[k] != name[i][k] && reg[k] != '?' ){
				b = false;
				break;
			}
		}
		if( b ) ans = false;
	}

	if( ans ){
		cout << "Yes" << endl;
		cout << reg << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}