#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int N;
	vector<int> A;
	int i,j;
	int count=0;
	int tot =0;
	cin >> N;
	for(i=0;i<N;i++) A.push_back(0);
	for(i=0;i<N;i++) cin >> A[i];
	sort(A.begin(),A.end(),cmp);
	i=0;
	while(A[i]==4)
	{
		count++;
		i++;
	}
	j=N-1;
	while((A[i]==3)&&(A[j]==1))
	{
		count++;
		i++;
		j--;
	}
	while(A[i]==3)
	{
		count++;
		i++;
	}
	while((A[i]==2)&&(A[i+1]==2))
	{
		count++;
		i+=2;
	}
	for(;i<=j;i++)
		tot+=A[i];
	if(tot%4) count++;
	count += tot/4;
	cout << count << endl;
}