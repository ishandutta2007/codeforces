#include <iostream>
#include <algorithm>
using namespace std;

struct queen
{
	int x,y;
	int attack;
};

bool cmpHoriz(queen a,queen b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

bool cmpVert(queen a,queen b)
{
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}

bool cmpDiag1(queen a,queen b)
{
	if((a.y-a.x)==(b.y-b.x))
		return (a.y+a.x)<(b.y+b.x);
	return (a.y-a.x)<(b.y-b.x);
}

bool cmpDiag2(queen a,queen b)
{
	if((a.y+a.x)==(b.y+b.x))
		return (a.y-a.x)<(b.y-b.x);
	return (a.y+a.x)<(b.y+b.x);
}

queen A[100000];
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> A[i].x >> A[i].y;
		A[i].attack = 0;
	}

	sort(A,A+M,cmpHoriz);
	for(int i=0;i<M;i++)
	{
		if((i>0)&&(A[i].x==A[i-1].x))
			A[i].attack++;
		if((i<(M-1))&&(A[i].x==A[i+1].x))
			A[i].attack++;
	}
	sort(A,A+M,cmpVert);
	for(int i=0;i<M;i++)
	{
		if((i>0)&&(A[i].y==A[i-1].y))
			A[i].attack++;
		if((i<(M-1))&&(A[i].y==A[i+1].y))
			A[i].attack++;
	}
	sort(A,A+M,cmpDiag1);
	for(int i=0;i<M;i++)
	{
		if((i>0)&&((A[i].y-A[i].x)==(A[i-1].y-A[i-1].x)))
			A[i].attack++;
		if((i<(M-1))&&((A[i].y-A[i].x)==(A[i+1].y-A[i+1].x)))
			A[i].attack++;
	}
	sort(A,A+M,cmpDiag2);
	for(int i=0;i<M;i++)
	{
		if((i>0)&&((A[i].y+A[i].x)==(A[i-1].y+A[i-1].x)))
			A[i].attack++;
		if((i<(M-1))&&((A[i].y+A[i].x)==(A[i+1].y+A[i+1].x)))
			A[i].attack++;
	}
	int num[9];
	for(int i=0;i<=8;i++)
		num[i] = 0;
	for(int i=0;i<M;i++)
		num[A[i].attack]++;
	for(int i=0;i<=8;i++)
		cout << num[i] << " ";
	return 0;
}