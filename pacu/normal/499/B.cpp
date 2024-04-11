#include <iostream>
#include <string>
using namespace std;

string a[3000];
string b[3000];
int N,M;

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;i++)
		cin >> a[i] >> b[i];
	string c;
	for(int i=0;i<N;i++)
	{
		cin >> c;
		int j;
		for(j=0;j<M;j++)
			if((c==a[j])||(c==b[j]))
				break;
		if(a[j].size()<=b[j].size()) cout << a[j] << " ";
		else cout << b[j] << " ";
	}
	cout << endl;
	return 0;
}