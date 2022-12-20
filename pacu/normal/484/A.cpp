#include <iostream>
#include <vector>
using namespace std;

long long pw(long long n,long long p)
{
	if(p==0)
		return 1;
	return n*pw(n,p-1);
}

long long getbest(long long L,long long R)
{
	vector<bool> bL,bR;
	while(L>0)
	{
		bL.push_back(L%2);
		L /= 2;
	}
	int cntR = 0;
	while(R>0)
	{
		if(R%2)
			cntR++;
		bR.push_back(R%2);
		R /= 2;
	}
	while(bL.size()<bR.size())
		bL.push_back(0);
	while(bR.size()<bL.size())
		bR.push_back(0);
	long long i = bL.size()-1;
	long long cnt = 0;
	for(;i>=0;i--)
	{
		if(bL[i]==bR[i])
		{
			cnt *= 2;
			cnt += bL[i];
		}
		else
		{
			if(cntR==(i+1))
			{
				cnt <<= i+1;
				cnt += pw(2,i+1)-1;
			}
			else
			{
				cnt <<= i+1;
				cnt += pw(2,i)-1;
			}
			break;
		}
		if(bR[i])
			cntR--;
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;
	long long l,r;
	for(int i=0;i<N;i++)
	{
		cin >> l >> r;
		if(r==0)
			cout << 0 << endl;
		else
			cout << getbest(l,r) << endl;
	}
}