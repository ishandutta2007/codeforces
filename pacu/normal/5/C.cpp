#include <iostream>
#include <string>
using namespace std;
#define OSET 1000001

string A;
int first[2000011];
int last[2000011];

int main()
{
	cin >> A;
	for(int i=-1000001;i<=1000001;i++)
		first[i+OSET] = last[i+OSET] = -1;
	int d = 0;
	int bestlen = 0;
	int bestnum = 1;
	int curlen;
	first[0+OSET] = last[0+OSET] = 0;
	for(int i=0;i<A.size();i++)
	{
		if(A[i] == '(') d++;
		else d--;
		if(first[d+OSET] != -1)
		{
			if(last[d-1+OSET] == -1)
				curlen = i-first[d+OSET]+1;
			else
				curlen = i-last[d-1+OSET];
			if(curlen==bestlen)
				bestnum++;
			if(curlen>bestlen)
			{
				bestlen = curlen;
				bestnum = 1;
			}
		}
		else
			first[d+OSET] = i+1;
		last[d+OSET] = i+1;
	}
	if(bestlen == 0)
		bestnum = 1;
	cout << bestlen << " " << bestnum << endl;
}