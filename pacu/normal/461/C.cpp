#include <iostream>
#include <deque>
using namespace std;
#define MAXN 100001
int N,Q;
int T[MAXN];

int getSum(int i)
{
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}
void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

int main()
{
	int frontSide = 1;	//1 -> left side, -1 -> right side
	int vals[100000];
	int start = 0;
	cin >> N >> Q;
	int tot = N;
	int end = N-1;
	init();
	for(int i=0;i<N;i++)
		set(i,1);
	for(int i=0;i<Q;i++)
	{
		int tp;
		cin >> tp;
		if(tp==1)
		{
			int fold;
			cin >> fold;
			if((2*fold)>N)
			{
				int tmp;
				tmp = start;
				start = end;
				end = tmp;
				frontSide = -frontSide;
				fold = N-fold;
			}
			if(1)
			{
				if(frontSide==1)
					vals[0] = getSum(start);
				else
					vals[0] = tot-getSum(start-1);
				set(start,-vals[0]);
				set(start+frontSide*(-1+2*fold),vals[0]);
				for(int j=1;j<fold;j++)
				{
					vals[j] = getSum(start+frontSide*j)-getSum(start+frontSide*j-1);
					set(start+frontSide*j,-vals[j]);
					set(start+frontSide*(-1+2*fold-j),vals[j]);
				}
				N -= fold;
				start += frontSide*fold;
			}
		}
		else
		{
			int l,r;
			cin >> l >> r;
			if(frontSide==1)
				cout << getSum(start+frontSide*(r-1))-getSum(start+frontSide*(l-1)) << endl;
			else
				cout << getSum(start-l)-getSum(start-r) << endl;
		}
	}
}