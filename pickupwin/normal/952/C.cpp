#include <iostream>
using namespace std;

int N, Num[111];
bool win=true;

int iabs(int a){
	return (a>0)?a:(-a);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> Num[i];
	}
	for(int i=1;i<N;++i){
		if(iabs(Num[i]-Num[i+1])>=2){
			win=false;
			break;
		}
	}
	
	if(win)cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}