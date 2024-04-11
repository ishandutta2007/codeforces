#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station
{
	long long x;
	int id;
};

bool operator<(Station a,Station b)
{
	return a.x<b.x;
}

vector<Station> A;
unsigned long long N,K;
long long xsum;
unsigned long long totdist;

void shift(int i)	//goes now from i, i+1, i+2, ... i+k-1
{					//after shift: i+1, i+2, i+3, ... i+k
	//remove i
	xsum -= A[i].x;
	totdist -= (xsum - (K-1)*A[i].x);
	//add i+k
	totdist += (K-1)*A[i+K].x - xsum;
	xsum += A[i+K].x;
}

void add(int i)	//add 0...i-1 to i
{
	totdist += i*A[i].x - xsum;
	xsum += A[i].x;
}

int main()
{
	int i;
	Station s;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> s.x;
		s.id = i+1;
		A.push_back(s);
	}
	sort(A.begin(),A.end());
	cin >> K;
	xsum = 0;
	totdist = 0;
	for(i=0;i<K;i++)
		add(i);
	unsigned long long dist = totdist;
	int j = 0;
	for(i=0;i<(N-K);i++)
	{
		shift(i);
		if(dist>totdist)
		{
			dist = totdist;
			j = i+1;
		}
	}
	for(i=0;i<K;i++,j++)
		cout << A[j].id << " ";
}