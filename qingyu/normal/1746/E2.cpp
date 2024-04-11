
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#ifdef He_Ren

int askcnt = 0;
mt19937 gen((unsigned long long)new char ^ time(0));
bool ask(vector<int>)
{
	++askcnt;
	return gen() % 2;
}

void answer(int x)
{
	printf("answer! x = %d, askcnt = %d\n",x,askcnt);
}

#else

bool ask(vector<int> s)
{
	if(!s.size()) return 0;
	printf("? %d ",(int)s.size());
	for(int t: s)
		printf("%d ",t);
	printf("\n");
	fflush(stdout);
	
	static char ans[10];
	scanf("%s",ans);
	return ans[0] == 'Y';
}

void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	
	static char ans[10];
	scanf("%s",ans);
	if(ans[1] == ')') exit(0);
}

#endif

void split(const vector<int> &A,vector<int> &L,vector<int> &R,int k)
{
	L = R = vector<int>();
	L = vector<int>(A.begin(), A.begin() + k);
	if (A.size() > k) R = vector<int>(A.begin() + k, A.end());
}
void merge(vector<int> &A,const vector<int> &R)
{
	A.insert(A.end(), R.begin(), R.end());
}

ostream& operator<<(ostream& f, vector<int> &vec) {
	f << "(" << vec.size() << "){ ";
	for (auto x : vec)
		f << x << " ";
	f << " }";
	return f;
}

int main(void)
{
	int n;
#ifdef He_Ren
	n = 1e5;
#else
	scanf("%d",&n);
#endif
	
	vector<int> A(n), B;
	iota(A.begin(), A.end(), 1);
	
	while(A.size() + B.size() >= 4 || (A.size() + B.size() >= 3 && B.size() != 1))
	{
		//cerr << "A = " << A << ", B = " << B << "\n";
	
		vector<int> LA, RA, LB, RB;
		split(B, LB, RB, (B.size() + 1) / 2);
		int offset = 1;
		if (A.size() == 0 || A.size() % 2 == 1 || B.size() % 2 == 0)
			offset = 0;
		split(A, LA, RA, A.size() / 2 - offset);
		//cerr << "LA = " << LA << ", RA = " << RA << "\n";	
		vector<int> tmp;
		merge(tmp = LA, LB);
		
		if(!ask(tmp)) swap(LA, RA), swap(LB, RB);
		
		B = RA;
		A = LA;
		merge(A, LB);
	}
	
	merge(A, B);
	
//	while(A.size() >= 4)
//	{
//		vector<int> L,R;
//		split(A, L, R, A.size() / 2);
//		
//		if(!ask(L)) swap(L, R);
//		
//		vector<int> x, y;
//		split(R, x, y, R.size() / 2);
//		
//		if(!ask(x)) swap(x, y);
//		
//		A = L;
//		A.insert(A.end(), x.begin(), x.end());
//	}
	
	if(A.size() == 1)
	{
		answer(A[0]);
	}
	else if(A.size() == 2)
	{
		answer(A[0]);
		answer(A[1]);
	}
	else
	{
		if(ask({A[2]}))
		{
			answer(A[2]);
			if(ask({A[0]}))
				answer(A[0]);
			else
				answer(A[1]);
			return 0;
		}
		answer(A[1]);
		answer(A[2]);
	}
	return 0;
}