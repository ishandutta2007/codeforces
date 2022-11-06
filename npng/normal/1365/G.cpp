#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int Maxn=1000;
const int Q=13;
typedef long long ll;
int n;
ll ans[Maxn+5];
int mask[Maxn+5];
vector<int> ask[70];
ll val[70];
ll query(vector<int> v){
	cout<<"? "<<v.size();
	for(int i=0;i<(int)v.size();i++){
		cout<<' '<<(v[i]+1);
	}
	cout<<endl;
	ll ans;
	cin>>ans;
	return ans;
}
int main(){
	fflush(stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<(1<<Q);i++){
		if(__builtin_popcount(i)!=Q/2){
			continue;
		}
		mask[cnt]=i;
		for(int j=0;j<Q;j++){
			if(((i>>j)&1)==0){
				ask[j].push_back(cnt);
			}
		}
		cnt++;
		if(cnt==n){
			break;
		}
	}
	for(int i=0;i<Q;i++){
		if(!ask[i].empty()){
			val[i]=query(ask[i]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<Q;j++){
			if((mask[i]>>j)&1){
				ans[i]|=val[j];
			}
		}
	}
	cout<<'!';
	for(int i=0;i<n;i++){
		cout<<' '<<ans[i];
	}
	cout<<endl;
	return 0;
}