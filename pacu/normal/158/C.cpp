#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> S;

int main()
{
	int N;
	string a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a;
		if(a == "pwd")
		{
			cout << "/";
			for(int i=0;i<S.size();i++)
				cout << S[i] << "/";
			cout << endl;
		}
		else
		{
			cin >> b;
			if(b[0] == '/')
				S.clear();
			else if(b[0] != '.')
				S.push_back("");
			for(int j=0;j<b.size();j++)
			{
				if(b[j]=='.')
				{
					if((j>0) && (b[j-1]=='.'))
						S.pop_back();
				}
				else if(b[j] != '/')
				{
					if((j>0)&&(b[j-1]=='/'))
						S.push_back("");
					S[S.size()-1] += b[j];
				}
			}
		}
	}
}