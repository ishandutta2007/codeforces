#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mole
{
	long long x,y,a,b;
};

void rotate(mole &m)
{
	long long dx = m.x-m.a;
	long long dy = m.y-m.b;
	m.x = m.a-dy;
	m.y = m.b+dx;
}

long long dist(mole m1,mole m2)
{
	return (m1.x-m2.x)*(m1.x-m2.x)+(m1.y-m2.y)*(m1.y-m2.y);
}

bool works(mole m[4])
{
	vector<long long> d;
	for(int i=0;i<4;i++)
		for(int j=(i+1);j<4;j++)
			d.push_back(dist(m[i],m[j]));
	sort(d.begin(),d.end());
	return ((d[0]==d[1])&&(d[0]==d[2])&&(d[0]==d[3])&&(2*d[0]==d[4])&&(d[4]==d[5])&&(d[0]!=0));
}

int getbest(mole m[4])
{
	int best = 1000;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<4;l++)
				{
					if(works(m))
						best = min(best,i+j+k+l);
					rotate(m[3]);
				}
				rotate(m[2]);
			}
			rotate(m[1]);
		}
		rotate(m[0]);
	}
	if(best==1000)
		return -1;
	return best;
}
mole A[400];
int main()
{
	int N;
	cin >> N;
	for(int i=0;i<4*N;i++)
		cin >> A[i].x >> A[i].y >> A[i].a >> A[i].b;
	for(int i=0;i<4*N;i+=4)
		cout << getbest(A+i) << endl;
	return 0;
}