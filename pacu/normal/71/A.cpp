#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	int N,i;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> a;
		if(a.size()<=10) cout << a << endl;
		else cout << a[0] << a.size()-2 << a[a.size()-1] << endl;
	}
}