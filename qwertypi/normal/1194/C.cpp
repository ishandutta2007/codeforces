#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string> 
#include <set>
using namespace std;

string _minus(string A, string B){
	int pos_A = 0;
	int pos_B = 0;
	string res;
	int B_sz = B.size();
	int A_sz = A.size();
	while(pos_B < B_sz && pos_A < A_sz){
		if(A[pos_A] == B[pos_B]){
			pos_A++;
			pos_B++;
		}else{
			res.push_back(A[pos_A]);
			pos_A++;
		}
	}
	for(int i=pos_A;i<A_sz;i++){
		res.push_back(A[i]);
	}
	return res;
}

bool isSub(string A, string B){
	int pos_A = 0;
	int pos_B = 0;
	int B_sz = B.size();
	int A_sz = A.size();
	while(pos_B < B_sz && pos_A < A_sz){
		if(A[pos_A] == B[pos_B]){
			pos_A++;
			pos_B++;
		}else{
			pos_A++;
		}
	}
	return pos_B == B_sz;
}

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		string s, t, p;
		cin >> s >> t >> p;
		if(!isSub(t, s)){
			cout << "NO" << endl;
			continue;
		}
		string a = _minus(t, s);
		int cnt[2][26];
		for(int i=0;i<2;i++){
			fill(cnt[i], cnt[i]+26, 0);
		}
		for(auto i:a){
			cnt[0][i - 'a']++;
		}
		for(auto i:p){
			cnt[1][i - 'a']++;
		}
		bool End = false;
		for(int i=0;i<26;i++){
			if(cnt[0][i] > cnt[1][i]){
				cout << "NO" << endl;
				End = true;
				break;
			}
		}
		if(!End){
			cout << "YES" << endl; 
		}
	}
	return 0;
}