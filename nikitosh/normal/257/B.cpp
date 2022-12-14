#include<cstdio>
#include<algorithm>

using namespace std;

int N, M, a[300000], ans1, ans2, ans3, ans4, size, n, m, boo;

int main()
{
	scanf("%d%d", &N, &M);
	n = N;
	m = M;
	a[0] = 1;
	size = 1;
	n--;
	boo = 2;
	while (n != 0 || m != 0)
	{
		if (n == 0 && m == 0)
			break;
		if (n == 0)
		{
			m--;
			a[size++] = 2;
			continue;
		}
		if (m == 0)
		{
			n--;
			a[size++] = 1;
			continue;
		}
		if (boo == 1)
		{          
			a[size] = a[size - 1];
			if (a[size] == 1)
				n--;
			else
				m--;
			size++;
		}
		if (boo == 2)           
		{          
			a[size] = 3 - a[size - 1];
			if (a[size] == 1)
				n--;
			else
				m--;
			size++;
		}
		boo = 3 - boo;
	}
  for (int i = 1; i < size; i++)
	{
		if (a[i] == a[i - 1])
			ans1++;
		else
			ans2++;
	}
	n = N;
	m = M;
	a[0] = 2;
	size = 1;
	m--;
	boo = 2;                 
	while (n != 0 || m != 0)
	{
		if (n == 0 && m == 0)
			break;
		if (n == 0)
		{
			m--;
			a[size++] = 2;
			continue;
		}
		if (m == 0)
		{
			n--;
			a[size++] = 1;
			continue;
		}
		if (boo == 1)
		{          
			a[size] = a[size - 1];
			if (a[size] == 1)
				n--;
			else
				m--;
			size++;
		}
		if (boo == 2)           
		{          
			a[size] = 3 - a[size - 1];
			if (a[size] == 1)
				n--;
			else
				m--;
			size++;
		}
		boo = 3 - boo;
	}
	for (int i = 1; i < size; i++)
	{
		if (a[i] == a[i - 1])
			ans3++;
		else
			ans4++;
	}
	printf("%d %d\n", max(ans1, ans3), min(ans2, ans4));
	return 0;
}