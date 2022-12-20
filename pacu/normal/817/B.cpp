#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	if(A[2] > A[1])
	{
		int num = 1;
		while(2+num<N && A[2+num] == A[2])
			num++;
		cout << num << '\n';
		return 0;
	}
	if(A[1] > A[0])
	{
		int num = 1;
		while(1+num<N && A[1+num]==A[1])
			num++;
		cout << ((num*((long long)(num-1)))/2) << '\n';
		return 0;
	}
	int num = 1;
	while(num<N && A[num]==A[0])
		num++;
	cout << ((num*((long long)(num-1))*((long long)(num-2)))/6) << '\n';
	return 0;
}