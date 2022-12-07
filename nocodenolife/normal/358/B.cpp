#include <iostream>

using namespace std;

int main()
{
	string message;
	string heart = "<3";

	int n;
	cin>>n;
	if(n> 100006/3)
	{
		cout<<"no"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		string word;
		cin>>word;
		message = message +heart+ word;
	}
	message = message + heart;
	if(message.size()>100000)
	{
		cout<<"no"<<endl;
		return 0;
	}
	string coded;
	cin>>coded;

	int iter =0;
	int cod =0;
	int m_size = message.size();
	int c_size = coded.size();
	while(iter<m_size && cod<c_size)
	{
		if(coded[cod] == message[iter])
		{
			iter++;
		}
		cod++;
	}

	if(iter==m_size)
	{
		cout<<"yes"<<endl;
		return 0;
	}

	cout<<"no"<<endl;
	return 0;
}