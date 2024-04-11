#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;
	map<string,string> M;	//new,old
	cin >> N;
	for(int i=0;i<N;i++)
	{
		string a,b;
		cin >> a >> b;
		M[b] = a;
		if(M.find(a) != M.end())
		{
			M[b] = M[a];
			M.erase(a);
		}
	}
	cout << M.size() << endl;
	for(map<string,string>::iterator it = M.begin();it != M.end();it++)
		cout << it->second << " " << it->first << endl;
	return 0;
}