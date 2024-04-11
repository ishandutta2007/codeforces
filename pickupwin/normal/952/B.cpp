#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int a=0;
int nocnt=0;
string input;

string n[8]={
	"normal",
	"cool",
	"not bad",
	"don't touch me!",
	"don't touch me",
	"don't think so",
	"great!",
	"great"
};

string g="grumpy";

int main(){
	
	for(int i=0;i<=9;++i){
		cout << i << endl;
		getline(cin, input);
		if(input=="no"){
			++nocnt;
		}
		else{
			for(int j=1;j<=7;++j){
				if(input==n[j]){
					a=1;break;
				}
			}
			if(a==0){
				a=-1;
			}
			break;
		}
		if(nocnt>3){
			a=1;
			break;
		}
	}
	
	if(a>0) cout << n[0] << endl;
	if(a<0) cout << g << endl;
	assert(a!=0);
	
	return 0;
}