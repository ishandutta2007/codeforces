#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>K;
	while(K--){
		int b,w;
		cin>>b>>w;
		swap(b,w);
		if(b>=w){
			if(w*3+1<b){
				cout<<"NO\n";
				continue;
			}
			cout<<"YES"<<endl;
			if(w*3+1==b){
				for(int i=0;i<w;i++){
					cout<<100+i*2-1<<" "<<5<<endl;
					cout<<100+i*2<<" "<<4<<endl;
					cout<<100+i*2<<" "<<6<<endl;
					cout<<100+i*2<<" "<<5<<endl;
				}
				cout<<100+w*2-1<<" "<<5<<endl;
				continue;
			}
			for(int i=0;i<w;i++){
				cout<<100+i*2<<" "<<5<<endl;
			}
			for(int i=0;i<min(w,b);i++){
				cout<<100+i*2-1<<" "<<5<<endl;
			}
			b-=w;
			for(int i=0;i<min(w,b);i++){
				cout<<100+i*2<<" "<<4<<endl;
			}
			b-=w;
			for(int i=0;i<min(w,b);i++){
				cout<<100+i*2<<" "<<6<<endl;
			}
			b-=w;
		}
		else{
			swap(b,w);
			if(w*3+1<b){
				cout<<"NO\n";
				continue;
			}
			cout<<"YES"<<endl;
			if(w*3+1==b){
				for(int i=0;i<w;i++){
					cout<<99+i*2-1<<" "<<5<<endl;
					cout<<99+i*2<<" "<<4<<endl;
					cout<<99+i*2<<" "<<6<<endl;
					cout<<99+i*2<<" "<<5<<endl;
				}
				cout<<99+w*2-1<<" "<<5<<endl;
				continue;
			}
			for(int i=0;i<w;i++){
				cout<<99+i*2<<" "<<5<<endl;
			}
			for(int i=0;i<min(w,b);i++){
				cout<<99+i*2-1<<" "<<5<<endl;
			}
			b-=w;
			for(int i=0;i<min(w,b);i++){
				cout<<99+i*2<<" "<<4<<endl;
			}
			b-=w;
			for(int i=0;i<min(w,b);i++){
				cout<<99+i*2<<" "<<6<<endl;
			}
			b-=w;
		}
	}
	return 0;
}