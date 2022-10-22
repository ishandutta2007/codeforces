#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;
//long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>K;
	while(K--){
		cin>>N;
		L=-100000;
		R=100000;
		int B,U;
		B=-100000;
		U=100000;
		for(int i=0;i<N;i++){
			cin>>W>>H;
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(!a){
				L=max(L,W);
			}
			if(!b){
				U=min(U,H);
			}
			if(!c){
				R=min(R,W);
			}
			if(!d){
				B=max(B,H);
			}
		}
		if(L<=R&&B<=U){
			cout<<"1 "<<L<<" "<<U<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}