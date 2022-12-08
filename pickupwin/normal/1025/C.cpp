#include <iostream>
#include <string>

using namespace std;

const int MAXN=100111;

string input;
int N;
int Num[MAXN<<1];

int unCode(int c){
	if(c=='b')	return 1;
	else	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	N=input.length();
	for(int i=1;i<=N;++i)	Num[i]=unCode(input[i-1]);
	for(int i=1;i<=N;++i)	Num[i+N]=Num[i];
	N<<=1;
	
	int Ans=0;
	
	for(int i=1, l=1;i<=N;++i){
		if(i!=1 && Num[i]==Num[i-1])	l=i;
		Ans=max(Ans, (i-l+1));
	}
	
	cout << min(Ans, N>>1) << endl;
	
	return 0;
}