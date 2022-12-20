#include <iostream>
using namespace std;

int A[100000];
int sm[100001];

int binSearch(int low,int high,int label)
{
	int mid = (low+high)/2;
	if(label < sm[mid])
		return binSearch(low,mid-1,label);
	else if(label >= sm[mid+1])
		return binSearch(mid+1,high,label);
	else
		return mid;
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sm[0] = 0;
	for(int i=0;i<N;i++)
		sm[i+1] = sm[i] + A[i];
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		int k;
		cin >> k;
		k--;
		cout << 1+binSearch(0,N,k) << endl;
	}
}