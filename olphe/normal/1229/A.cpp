#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	vector<long long int>v(N);
	vector<long long int>w(N);
	for(auto &i:v)cin>>i;
	for(auto &i:w)cin>>i;
	map<long long int ,pair<long long int,int>>mp;
	for(int i=0;i<N;i++){
		mp[-v[i]].first+=w[i];
		mp[-v[i]].second++;
	}
	vector<long long int>used;
	long long int ans=0;
	for(auto i:mp){
		long long int num=-i.first;
		if(i.second.second>1){
			ans+=i.second.first;
			used.push_back(num);
		}
		else {
			bool flag=false;
			for(auto j:used){
				if((j&num)==num){
					flag=true;
					break;
				}
			}
			if(flag){
				used.push_back(num);
				ans+=i.second.first;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}