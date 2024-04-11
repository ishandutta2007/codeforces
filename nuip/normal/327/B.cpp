#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

int main(){
	long long N,i;
	cin>>N;
	
	for(i=N+1;i<=2*N;i++){
		cout<<i<<((i==2*N)?"\n":" ");
	}

	return 0;
}