#include <iostream>
#include <string>

using namespace std;

int unCode(char c){
	return c-'a';
}

char enCode(int a){
	return (char)(a+'a');
}

string input;
int T;
int N, K;
int Cnt[26];

int main(){
	
	cin >> T;
	
	while(T--){
		for(int i=0;i<26;++i)	Cnt[i]=0;
		cin >> input;
		N=input.length();
		for(int i=1;i<=N;++i)	++Cnt[unCode(input[i-1])];
		K=0;
		for(int i=0;i<26;++i)	K+=(Cnt[i]>0);
		if(K==1)	cout << "-1" << endl;
		else{
			for(int i=0;i<26;++i){
				for(int k=0;k<Cnt[i];++k)	cout << enCode(i);
			}
			cout << endl;
		}
	}
	
	return 0;
}