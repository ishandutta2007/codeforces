#include <bits/stdc++.h>

using namespace std;

bool ask(int k){
	cout << k << endl;
	fflush(stdout);
	string a;
	cin >> a;
	return (a=="yes");
}

bool is(int k){
	for(int j = 2;j<=sqrt(k);j++){
		if(k%j==0)return false;
	}
	return true;
}

void corner(){
	if(ask(4)||ask(9)||ask(25)||ask(49)){
		cout << "composite" << endl;
		fflush(stdout);
		exit(0);
	}
}

int main(){
	corner();
	int cnt = 0;
	for(int i = 2;i<=100;i++){
		if(is(i)){
			if(ask(i)==true){
				cnt++;
			}
		}
		if(i*2>100)break;
		if(cnt==2){
			cout << "composite" << endl;
			fflush(stdout);
			exit(0);
		}
	}
	cout << "prime" << endl;
	fflush(stdout);
	return 0;
}