#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;
 
int n;

int cn[26]; 

int main(){
	cin>>n;
	vector<long long int> v;
	for(int i=0;i<n;i++){
		long long int a;
		scanf("%lld",&a);
		v.push_back(a);
		for(int j=0;j<20;j++){
			if((a>>j)&1){
				cn[j]++;
			}
		}
	}
	long long int ans=0;
	while(true){
		//cerr<<"OK"<<endl;
		long long int ret=0;
		for(int i=0;i<20;i++){
			if(cn[i]){
				ret+=(1<<i);
				cn[i]--;
			}
		}
		ret*=ret;
		ans+=ret;
		if(ret==0)break;
		//cerr<<ret<<endl;
	}
	printf("%lld\n",ans);
	return 0;
	return 0;
}