#include <iostream>
#include <algorithm>
using namespace std;

struct exam
{
	long long grade;
	long long cess;
};

bool cmp(exam a,exam b)
{
	return a.cess<b.cess;
}
exam A[100000];
int main()
{
	long long N,maxScore,least;
	cin >> N >> maxScore >> least;
	least *= N;
	long long cur = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i].grade >> A[i].cess;
		cur += A[i].grade;
	}
	sort(A,A+N,cmp);
	long long tot = 0;
	int i = 0;
	while(cur < least)
	{
		if((least-cur)>(maxScore-A[i].grade))
		{
			tot += (maxScore-A[i].grade)*A[i].cess;
			cur += maxScore-A[i].grade;
		}
		else
		{
			tot += (least-cur)*A[i].cess;
			cur = least;
		}
		i++;
	}
	cout << tot << endl;
}