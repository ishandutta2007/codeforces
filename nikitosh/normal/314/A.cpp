#include<cstdio>
#include<vector>

using namespace std;
                                          
long long n, k, a[300000], ans = 0, sz = 1, cnt = 0;
vector <long long> b, c;
int boo;

int main()
{            	
	scanf("%I64d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	b.push_back(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (boo == 1)
			ans += b[sz - 1] * (sz - 1);
		boo = 0;
		if ((ans - k) / a[i] >= (n - cnt - sz - 1) * sz)
		{
			if (ans - k >= a[i] * (n - cnt - sz - 1) * sz)
			{
    	    	b.push_back(a[i]);
        		sz++;
        		boo = 1;
	        }
        }
        else
        {
        	c.push_back(i + 1);
        	cnt++;
        }
        //printf("%I64d\n", sz);
	}
	for (int i = 0; i < (int) c.size(); i++)
		printf("%I64d\n", c[i]);
	return 0;
}