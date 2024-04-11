#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, z, len, a[20], b[20], d[20], Z, ten[10];
vector <int> e;

int foo (int k)
{
	int ans = 0;
	while (k != 0)
	{
		d[ans] = k % 10;
		k /= 10;
		ans++;
	}
	return ans;
}

void gen(int z1, int z2, int used)
{       
	//if (used < len)
	//	Z++;
	/*if (used == len - 1)
	{
		if (used == used1)
		{
			printf("z1 = %d z2 = %d 1 %d\n", z1, z2, gen(z1, z2, used + 1, used1, used2 + 1));
			int ans2 = 0;                                    
			b[used] = z2;
			ans2 += gen(z1, z2, used + 1, used1, used2 + 1); 
			return ans2;
		}
		else
		if (used == used2)
		{
			printf("z1 = %d z2 = %d 2 %d\n", z1, z2, gen(z1, z2, used + 1, used1 + 1, used2));
			int ans2 = 0;                                                           
			b[used] = z1;
			ans2 += gen(z1, z2, used + 1, used1 + 1, used2);
			return ans2;
		}
	} */

	//if (z1 == 1 && z2 == 4)
	//	printf("z1 = %d z2 = %d used = %d b[0] = %d b[1] = %d b[2] = %d\n", z1, z2, used, b[0], b[1], b[2]);
	if (used == len)
	{
		//if (z1 == 1 && z2 == 4)
		//	printf("z1 = %d z2 = %d used = %d b[0] = %d b[1] = %d b[2] = %d\n", z1, z2, used, b[0], b[1], b[2]);
		//printf("%d\n", e.size());
		for (int i = 0; i < len; i++)
		{
			if (b[i] < d[len - i - 1])
			{
				int m = 0;
				for (int i = 0; i < len; i++)
				{
					m += b[i] * ten[len - i - 1];
					//printf("%d", b[i]);
				}
				//puts("");                
				//printf("%d\n", e.size());
				e.push_back(m);
				return;

		  }
		  if (b[i] > d[len - i - 1])
		  	return;
		}
		int m = 0;
		for (int i = 0; i < len; i++)
		{
			m += b[i] * ten[len - i - 1];
			//printf("%d", b[i]);
		}
		//puts("");                
		//printf("%d\n", e.size());
		e.push_back(m);
		return;
	}
	b[used] = z1;
	gen(z1, z2, used + 1);
	b[used] = z2;
	gen(z1, z2, used + 1); 
}                   

void gen2(int z3, int used)
{
	//if (used < len)
	//	Z++;
	if (used == len)
	{
		for (int i = 0; i < len; i++)
		{
			if (b[i] < d[len - i - 1])
			{
				int m = 0;
				for (int i = 0; i < len; i++)
				{
					m += b[i] * ten[len - i - 1];
					//printf("%d", b[i]);
				}
				//puts("");                
				//printf("%d\n", e.size());
				e.push_back(m);
				return;

		  }
		  if (b[i] > d[len - i - 1])
		  	return;
		}
		int m = 0;
		for (int i = 0; i < len; i++)
		{
			m += b[i] * ten[len - i - 1];
			//printf("%d", b[i]);
		}
		//puts("");                
		//printf("%d\n", e.size());
		e.push_back(m);
		return;
	}
	b[used] = z3;
	gen2(z3, used + 1);
	b[used] = 0;
	gen2(z3, used + 1); 
}                   

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	a[0] = 1;
	ten[0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		a[i] = a[i - 1] * 2;
		ten[i] = ten[i - 1] * 10;
	}

	len = foo(n);
	for (int i = 1; i < 10; i++)
		for (int j = i + 1; j < 10; j++)
		{
			gen(i, j, 0);
			//printf("%d %d %d\n", i, j, gen(i, j, 0, 0, 0));
		}

	for (int i = 1; i < 10; i++)
	{
		b[0] = i;   
		gen2(i, 1); 
	}
	sort(e.begin(), e.end());
	z = 1;
	for (int i = 1; i < (int) e.size(); i++)
	{
		if (e[i] != e[i - 1])
			z++;
  }   
	for (int i = 1; i < len; i++)
	{
		if (i == 1)
			z += 9;	
		else
			z += 36 * (a[i] - 2) + a[i - 1] * 9;	
	}
	printf("%d\n", z);
	return 0;
}