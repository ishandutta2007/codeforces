#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
	return (a%2)<(b%2);
}

int main()
{
	int N,k,p,nEven,nOdd;
	int i,iEl;
	int count = 0;
	vector<int> A;
	cin >> N >> k >> p;
	nEven = p;
	nOdd = k-p;
	for(i=0;i<N;i++){cin>>iEl;A.push_back(iEl);}
	sort(A.begin(),A.end(),cmp);
	i = 0;
	while((A[i]%2)==0)
	{
		if(nEven>0)
			nEven--;
		i++;
		if(i==N) break;
	}
	if((N-i)<(2*nEven+nOdd))
	{
		cout << "NO" << endl;
		return 0;
	}
	if(((N-i)%2) != (nOdd%2))
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if((p==1)&&(nOdd==0))
	{
		cout << N;
		for(iEl=0;iEl<N;iEl++)
			cout << " " << A[iEl];
		cout << endl;
		return 0;
	}
	if(nEven>0)	//too few even elements
	{
		for(iEl=0;iEl<i;iEl++)
			cout << 1 << " " << A[iEl] << endl;
		if(nOdd>0)
		{
			for(iEl=i;iEl<(i+2*nEven);iEl+=2)
				cout << 2 << " " << A[iEl] << " " << A[iEl+1] << endl;
		}
		else
		{
			for(iEl=i;iEl<(i+2*(nEven-1));iEl+=2)
				cout << 2 << " " << A[iEl] << " " << A[iEl+1] << endl;
			cout << N-iEl;
			for(;iEl<N;iEl++)
				cout << " " << A[iEl];
		}
		for(;iEl<(i+2*nEven+nOdd-1);iEl++)
			cout << 1 << " " << A[iEl] << endl;
		if(iEl<N)
		{
			cout << N - iEl;
			for(;iEl<N;iEl++)
				cout << " " << A[iEl];
			cout << endl;
		}
	}
	else
	{
		if(p==0)
		{
			cout << i+1;
			for(iEl=0;iEl<=i;iEl++)
				cout << " " << A[iEl];
			cout << endl;
			count++;
			for(iEl=i+1;iEl<(i+nOdd-1);iEl++)
			{
				cout << 1 << " " << A[iEl] << endl;
				count++;
			}
		}
		else
		{
			for(iEl=i;iEl<(i+nOdd-1);iEl++)
			{
				cout << 1 << " " << A[iEl] << endl;
				count++;
			}
		}
		if(iEl<N)
		{
			cout << N-iEl;
			for(;iEl<N;iEl++)
				cout << " " << A[iEl];
			cout << endl;
			count++;
		}
		if(p>0)
		{
			iEl = 0;
			if((k-count)>1)
				for(iEl=0;iEl<(p-1);iEl++)
					cout << 1 << " " << A[iEl] << endl;
			if(iEl<i)
			{
				cout << i-iEl;
				for(;iEl<i;iEl++)
					cout << " " << A[iEl];
				cout << endl;
			}
		}
	}
}