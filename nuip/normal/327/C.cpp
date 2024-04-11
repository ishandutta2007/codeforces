#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<cmath>
#define MAXI (10000000)

using namespace std;

long long pow2s[MAXI+5],repeat,sum,pow2=1;
const long long Q=1000000007;

int main(){

	long long i,j,cnt=0;
	string num;
	
	pow2s[0]=1;
	for(i=1;i<MAXI+5;i++){
		pow2s[i]=pow2s[i-1]*2;
		pow2s[i]%=Q;
	}
	
	cin>>num>>repeat;
	
	cnt=sum=0;
	for(i=num.size()-1;i>=0;i--){
		if(num.at(i)=='0' || num.at(i)=='5'){
			cnt+=pow2s[i];
			cnt%=Q;
		}
	}
	
	//cout<<cnt<<endl;
	
	long long sum100=0,cntt=1;//cnt;
	for(i=0;i<100;i++){
		sum100+=cntt;
		sum100%=Q;
		cntt*=pow2s[num.size()];
		cntt%=Q;
	}
//	cout<<sum100<<endl;
	sum100=(sum100*cnt)%Q;
	//cout<<"sum100:"<<sum100<<endl;
		
	
	for(i=0;i<repeat/(100);i++){
		sum+=sum100;
		sum%=Q;
		sum100*=pow2s[100*num.size()];
		sum100%=Q;
	}
	for(i=0;i<repeat%100;i++){
		sum*=pow2s[num.size()];
		sum%=Q;
		sum+=cnt;
		sum%=Q;
	}
	
//	cout<<(pow2-1)%(pow2s[num.size()]-1)<<endl;
	
	cout<<sum<<endl;

	return 0;
}
/*
	long long temp=repeat*num.size(),tmp;
	for(i=0;i<temp/(MAXI-1);i++){
		pow2*=pow2s[(MAXI-1)];
		pow2%=Q;
	}*/