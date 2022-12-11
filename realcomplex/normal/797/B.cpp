#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int>para,nepara;
	int sk = 0;
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(sk % 2 == 0){
			para.push_back(sk);
		}
		else{
			nepara.push_back(sk);
		}
	}
	int sum = 0;
	//int sum2;
	sort(nepara.begin(),nepara.end());
	reverse(nepara.begin(),nepara.end());
	int Sum = 0;
	for(int i = 0;i<nepara.size();i++){
		Sum += nepara[i];
		nepara[i] = Sum;
	}
	sum = nepara[0];
	for(int i = 2;i<nepara.size();i+=2){
		if(nepara[i] > sum){
			sum = nepara[i];
		}
		else{
			break;
		}
	}
	sort(para.begin(),para.end());
	reverse(para.begin(),para.end());
	for(int i = 0;i<para.size();i++){
		if(sum + para[i] > sum){
			sum += para[i];
		}
	}
	cout << sum;
	return 0;
}