#include<bits/stdc++.h>

using namespace std;

int f(int x){
	if(x%10==0){return x/10;}
	else{return x-1;}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<k;i++){n=f(n);}
	cout << n << '\n';
  return 0;
}