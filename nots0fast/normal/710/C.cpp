#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j]=-1;
		}
	}
	int evens = 2;
	int rownum=1;
	int columnnum=1;
	bool John = true;
	int middle = n/2;
	int number;
	int odds = 1;
	while(John)
	{
		if(rownum>=middle)
		{
			John=false;
		}
		else
		{
			int prev = columnnum;
			number=n-1-columnnum;
			for(columnnum; columnnum<=number; columnnum++)
			{
				arr[rownum][columnnum]=odds;
				odds+=2;
			}
			--columnnum;
			++rownum;
			for(rownum; rownum<=number; rownum++)
			{
				arr[rownum][columnnum]=odds;
				odds+=2;
			}
			--rownum;
			--columnnum;
			for(columnnum; columnnum>=prev; columnnum--)
			{
				arr[rownum][columnnum]=odds;
				odds+=2;
			}
			++columnnum;
			--rownum;
			for(rownum; rownum>=prev+1; rownum--)
			{
				arr[rownum][columnnum]=odds;
				odds+=2;
			}
			columnnum+=2;
			rownum+=2;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(arr[i][middle]==-1)
		{
			arr[i][middle]=odds;
			odds+=2;
		}
		if(arr[middle][i]==-1)
		{
			arr[middle][i]=odds;
			odds+=2;
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j]==-1)
			{
				cout<<evens<<" ";
				evens+=2;
			}
			else
			{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}