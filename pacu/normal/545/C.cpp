#include <iostream>
using namespace std;

int x[100000];
int h[100000];
int ml[100000],mr[100000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> h[i];
		ml[i] = mr[i] = 0;
	}
	ml[0] = mr[0] = 1;
	for(int i=1;i<N;i++)
	{
		if((x[i]-h[i])>x[i-1])
			ml[i] = max(ml[i],ml[i-1]+1);
		if((x[i]-h[i])>(x[i-1]+h[i-1]))
			ml[i] = max(ml[i],mr[i-1]+1);
		if(x[i]>x[i-1])
		{
			ml[i] = max(ml[i],ml[i-1]);
			mr[i] = max(mr[i],ml[i-1]+1);
		}
		if(x[i]>(x[i-1]+h[i-1]))
		{
			ml[i] = max(ml[i],mr[i-1]);
			mr[i] = max(mr[i],mr[i-1]+1);
		}
	}
	cout << mr[N-1] << endl;
}