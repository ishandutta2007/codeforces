# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	if(n%2==0){
		cout << 0 <<endl;
		return 0;
	}

	if(n==1)
		cout << 1 <<endl;
	if(n==3)
		cout << 18 <<endl;
	if(n==5)
		cout << 1800 <<endl;
	if(n==7)
		cout << 670320 <<endl;
	if(n==9)
		cout << 734832000 <<endl;
	if(n==11)
		cout << 890786230 <<endl;
	if(n==13)
		cout << 695720788  <<endl;
	if(n==15)
		cout << 150347555 <<endl;

}