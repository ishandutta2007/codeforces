#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
	long long x,y;
	int cid;
	bool okay;
};

bool cmp(Point &a,Point &b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x>b.x;
}

bool getCross(Point &O,Point &A,Point &B)
{
	return (O.x-A.x)*(O.y-B.y)*A.y*B.x < (O.x-B.x)*(O.y-A.y)*A.x*B.y;
}

Point A[200000];
vector<int> hull;
int lower[200000];
int upper[200000];
bool winner[200000];
int equaltonext[200000];
int N;

void getHull()
{
	if(N==1)
	{
		hull.push_back(0);
		return;
	}
	sort(A,A+N,cmp);
	int c = 0;
	for(int i=0;i<N;i++)
	{
		if((i<(N-1))&&(A[i].x==A[i+1].x)&&(A[i].y<A[i+1].y)) continue;
		if((i<(N-1))&&(A[i].x==A[i+1].x)&&(A[i].y==A[i+1].y)){equaltonext[i]=1;continue;}
		while((c>=2)&&(getCross(A[lower[c-2]],A[lower[c-1]],A[i])))
			c--;
		lower[c++] = i;
	}
	A[lower[0]].okay = 1;
	for(int i=1;i<c;i++)
	{
		A[lower[i]].okay = (A[lower[i]].y > A[lower[i-1]].y);
	}
	for(int i=(N-1);i>=0;i--)
		A[i].okay = (A[i].okay || (equaltonext[i]&&A[i+1].okay));
	for(int i=0;i<N;i++)
		winner[A[i].cid] = A[i].okay;
}

int main()
{
	cin >> N;
	int a,b;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		A[i].x = a;
		A[i].y = b;
		A[i].cid = i;
		equaltonext[i] = 0;
	}
	if(N==1)
	{
		cout << 1 << "\n";
		return 0;
	}
	getHull();
	for(int i=0;i<N;i++)
		if(winner[i]) cout << i+1 << " ";
	cout << "\n";
	return 0;
}