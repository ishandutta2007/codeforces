#include <iostream>
#include <string>

using namespace std;

const int MAXL=100111;

int L;
string input;
int Num[MAXL];
int Cnt[27], CCnt;

int unCode(char c){
	return c-'a'+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> L;
	cin >> input;
	for(int i=1;i<=L;++i)
		Num[i]=unCode(input[i-1]);
	
	for(int i=1;i<=L;++i)	++Cnt[Num[i]];
	for(int i=1;i<=26;++i)	if(Cnt[i]>0)	++CCnt;
	
	if(CCnt<=1)	cout << "Yes" << endl;
	else{
		bool Win=false;
		for(int i=1;i<=26;++i)	if(Cnt[i]>1)	Win=true;
		if(Win)	cout << "Yes" << endl;
		else	cout << "No" << endl;
	}
	
	return 0;
}