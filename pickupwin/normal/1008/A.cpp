#include <iostream>
#include <string>

using namespace std;

const int MAXN=111;

string input;
int N;
char Num[MAXN];
bool Win=true;

bool isv(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	N=input.length();
	for(int i=1;i<=N;++i){
		Num[i]=input[i-1];
	}
	
	for(int i=1;i<=N;++i){
		if(!isv(Num[i])){
			if(Num[i]!='n' && (i==N || (!isv(Num[i+1]))))	
				Win=false;
		}
	}
	
	if(Win)	cout << "YES" << endl;
	else	cout << "NO" << endl;
	
	return 0;
}