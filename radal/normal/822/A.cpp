#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if (a >= b){
		int bf=1;
		for (int i=2; i<=b; i++){
			bf*=i;
		}
		cout << bf;
		return 0;
	}
	else{
		int af=1;
		for (int i=2; i<=a; i++){
			af*=i;
		}
		cout<<af;
	}
}