#include<bits/stdc++.h> 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pii;
 
#define ff first
#define ss second
#define vi vector<int>
#define fo(n) for(int i = 0;i < int(n);i++)
#define foo(a,b) for(int i = int(a);i <= int(b);i++)
#define mk make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define fastio ios_base:: sync_with_stdio(false)
 
 
const int MAXN = 1e6;
const int mod = 1e9 + 7;
const int inf = 1e9;
 
 
int main(){
	
	fastio;
	int n,m;
	cin >> n >> m;
 
	vi time(n);
	fo(n) cin >> time[i];
 
	vi T(101,0);
	int rem = m;
 
	fo(n){
		int reqd = time[i]-rem;
		int cnt = 0;
		int saved = 0;
 
		for(int k = 100;k > 0 && saved < reqd;k--){
			int reqd_num = ceil((double) (reqd-saved)/k);
 
			cnt += min(reqd_num, T[k]);
			saved += min(reqd_num,T[k])*k;
		}
 
		cout << cnt << " ";
		T[time[i]]++;
		rem -= time[i];
	}
 }