#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

long long int kk;
vector<int> tmp;
bool ok(long long int z){
	long long int k=z/10;
	if(k==0LL)return false;
	long long int g=z%10;
	vector<int> cn;
	for(int i=0;i<g;i++)cn.push_back(k+1);
	for(int i=g;i<10;i++)cn.push_back(k);
	long long int pr=1;
	tmp=cn;
	for(int i=0;i<cn.size();i++){
		pr*=cn[i];
		if(pr>=kk)return true;
	}
	if(pr>=kk)return true;
	return false;
}
int main(){
	
	scanf("%lld",&kk);
	long long int mint=10;
	long long int maxt=10000000LL;
	while(mint+1LL<maxt){
		long long int mid=(mint+maxt)/2LL;
		if(ok(mid)){
			maxt=mid;
		}
		else{
			mint=mid;
		}
	}
	if(ok(mint)){
		maxt=mint;
	}
	else{
		mint=maxt;
	}
	ok(mint);
	string z="codeforces";
	string ans;
	for(int i=0;i<tmp.size();i++){
		while(tmp[i]--){
			ans.push_back(z[i]);
		}
	}
	printf("%s\n",ans.c_str());
	
	return 0;
}