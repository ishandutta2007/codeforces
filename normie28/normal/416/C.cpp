#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
 
const long long INF = 1e18;
const long long MAX = 1e5+10;
 
bool sortDesc(const pair<int,pair<int,int>> &a , const pair<int,pair<int,int>> &b){
	return (a.first > b.first);
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
  
 
int main(){
	fastio;
	int n,k; std::vector< pair<int,pair<int,int>> > v; std::vector<pair<int,int>> r;
    cin>>n;
	FOR(i,0,n) {int c,p; cin>>c>>p; v.push_back({p,{i,c}});}
	
	sort(v.begin(),v.end(),sortDesc);
	cin>>k;
	FOR(i,0,k) {int x ; cin>>x; r.push_back({i,x});}
	sort(r.begin(),r.end(),sortbysec);
	int sum=0,cnt=0; std::vector<pair<int,int>> ans;
	//FOR(i,0,k) cout<<r[i].second<<" "; //cout<<v[i].first<<" "<<v[i].second.second<<endl;
	FOR(i,0,n){
		int u = v[i].second.second; 
		FOR(j,0,k)
		{
			if(r[j].second>=u) 
			{ r[j].second=-1;sum+=v[i].first; cnt++;  ans.push_back({v[i].second.first+1, r[j].first+1});
			/* cout<<v[i].first<<" "<<v[i].second.second<<" ";*/ break;}
		}
	}
	sort(ans.begin(), ans.end());
 
	cout<<cnt<<" "<<sum<<endl;
 
	FOR(i,0,ans.size()) {cout<<ans[i].first<<" "<<ans[i].second<<endl;}
 
}