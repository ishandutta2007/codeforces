#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int x, y;
	cin >> x>> y;
	if(x == 1 && y == 1)
	{	cout<<"=";
		return 0;}
	else if(x == 1){
		cout<<"<";
		return 0;
	}
	else if(y == 1) {
		cout<<">";
		return 0;
	}
	if(x == 2){
		x = 4;
	}
	if(y == 2){
		y = 4;
	}
	if(y > x)
		cout<<">";
	else if(x > y)
		cout<<"<";
	else
		cout<<"=";
}