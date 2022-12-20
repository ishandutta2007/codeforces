#include <iostream>
#include <algorithm>
using namespace std;

struct order
{
	int hair,disp,loc,original;
};

order A[100000];

bool cmp1(order x,order y)
{
	if(x.disp == y.disp)
		return x.hair < y.hair;
	return x.disp > y.disp;
}

bool cmp2(order x,order y)
{
	if(x.hair == y.hair)
		return x.loc < y.loc;
	return x.hair > y.hair;
}

bool cmp3(order x,order y)
{
	return x.disp > y.disp;
}

int main()
{
	int N,P,K;
	cin >> N >> P >> K;
	for(int i=0;i<N;i++)
		cin >> A[i].hair >> A[i].disp;
	for(int i=0;i<N;i++)
		A[i].original = i+1;
	sort(A,A+N,cmp1);
	for(int i=0;i<N;i++)
		A[i].loc = i;
	sort(A,A+N-(P-K),cmp2);
	int l = 0;
	for(int i=0;i<K;i++)
	{
		cout << A[i].original << " ";
		l = max(l,A[i].loc);
	}
	sort(A,A+N,cmp1);
	sort(A+l+1,A+N,cmp3);
	for(int i=l+1;i<(l+1+P-K);i++)
		cout << A[i].original << " ";
	cout << endl;
}