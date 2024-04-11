#include <cstdio>
#include <iostream>
using namespace std;
#define BSIZE 317

int aPar[100000];
int aNecJumps[100000];	//number of jumps needed to move to new block
int aFinDest[100000];	//first hole reached in a different block
int N;

int block(int i)
{
	if(i==-1)
		return -1;
	return i/BSIZE;
}

void setPower(int iHole,int iPow)
{
	int iNext = iHole + iPow;

	if(iNext >= N)
		iNext = -1;

	aPar[iHole] = iNext;
	aFinDest[iHole] = iNext;
	aNecJumps[iHole] = 1;

	if(block(iHole)==block(iNext))
	{
		aFinDest[iHole] = aFinDest[iNext];
		aNecJumps[iHole] = aNecJumps[iNext]+1;
	}

	for(int i=min(N-1,((BSIZE*(1+block(iHole)))-1));(block(i)==block(iHole))&&(i>=0);i--)
	{
		if(aNecJumps[i]>1)
		{
			aFinDest[i] = aFinDest[aPar[i]];
			aNecJumps[i] = aNecJumps[aPar[i]]+1;
		}
	}
}

void gett(int iHole,int &last,int &njumps)
{
	last = iHole;
	njumps = 0;
	while(aFinDest[last]!=-1)
	{
		njumps += aNecJumps[last];
		last = aFinDest[last];
	}
	while(last!=-1)
	{
		njumps++;
		if(aPar[last]==-1)
			break;
		last = aPar[last];
	}
}

int main()
{
	int M;
	int pw;
	//cin >> N >> M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		aPar[i] = -1;
		aNecJumps[i] = 1;
		aFinDest[i] = -1;
	}
	for(int i=0;i<N;i++)
	{
		//cin >> pw;
		scanf("%d",&pw);
		setPower(i,pw);
	}
	for(int i=0;i<M;i++)
	{
		int tp,a,b;
		//cin >> tp >> a;
		scanf("%d %d",&tp,&a);
		a--;
		if(tp==1)
		{
			int last,njumps;
			gett(a,last,njumps);
			//cout << last+1 << " " << njumps << endl;
			printf("%d %d\n",last+1,njumps);
		}
		else
		{
			//cin >> b;
			scanf("%d",&b);
			setPower(a,b);
		}
	}
}