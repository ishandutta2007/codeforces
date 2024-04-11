#include <iostream>
using namespace std;

int N,M;
long long heads[100000];
long long tracks[100000];

bool check(long long ctime)
{
	int nxtTrack = 0;
	for(int cur=0;cur<N;cur++)
	{
		long long cpos = heads[cur];
		if(ctime < (cpos-tracks[nxtTrack]))
			return 0;
		if(tracks[nxtTrack] < cpos)
			cpos += max(ctime-2*(cpos-tracks[nxtTrack]),(ctime-(cpos-tracks[nxtTrack]))/2);
		else
			cpos += ctime;
		for(;nxtTrack<M;nxtTrack++)
			if(tracks[nxtTrack] > cpos)
				break;
		if(nxtTrack==M)
			return 1;
	}
	return 0;
}

long long binSearch(long long low,long long high)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(check(low)) return low;
		return high;
	}
	long long mid = (low+high)/2;
	if(check(mid)) return binSearch(low,mid);
	else return binSearch(mid+1,high);
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> heads[i];
	for(int j=0;j<M;j++)
		cin >> tracks[j];
	cout << binSearch(0,20000000000L) << endl;
}