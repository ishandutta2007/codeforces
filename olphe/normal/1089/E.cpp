#include "bits/stdc++.h"

using namespace std;

int N;

int main(){
	cin>>N;
	vector<int>box({1,2,3,4,5,6,8,7});
	vector<int>bag({7,8,6,5,4,3,2,1});
	int h=1;
	char c='a';
	if(N==9){
		cout<<"a1 a2 a3 a4 a5 a6 a7 a8 b8 h8"<<endl;
		return 0; 
	}
	if(N<=8)cout<<"a1 ";
	while(N>9){
		if(h==1)N++;
		N-=8;
		if(h&1){
			for(auto i:box)cout<<c<<i<<" ";
		}
		else{
			for(auto i:bag)cout<<c<<i<<" ";		
		}
		h++;
		c++;
	}
	if(N==8){
		c='h';
		if(h&1){
			swap(box[6],box[7]);
			for(auto i:box)cout<<c<<i<<" ";
		}
		else{
			swap(bag[1],bag[7]);
			for(auto i:bag)cout<<c<<i<<" ";
		}
		cout<<endl;
		return 0;
	}
	else if(N==9){
		if(h&1){
			swap(box[6],box[7]);
			for(auto i:box)cout<<c<<i<<" ";
		}
		else{
			swap(bag[1],bag[7]);
			for(auto i:bag)cout<<c<<i<<" ";
		}
		cout<<"h8";
		cout<<endl;
		return 0;
	}
	if(h&1){
		c='h';
		for(int i=1;i<N;i++){
			cout<<c<<i<<" ";
		}
		cout<<"h8"<<endl;
	}
	else{
		c='h';
		cout<<c<<7<<" ";
		for(int i=1;i<N-1;i++){
			cout<<c<<i<<" ";
		}
		cout<<"h8"<<endl;
	}
	return 0;
}