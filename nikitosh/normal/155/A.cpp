#include<cstdio>

int a[1000], N, max1, min1, z;

int main()
{                     
    scanf("%d", &N);
    scanf("%d", &a[0]);
    max1 = a[0];
    min1 = a[0];
    for (int i = 1; i < N; i++)
    {
    	scanf("%d", &a[i]);
   	    if (a[i] > max1)
   	    {
   	    	max1 = a[i];
   	    	z++;
   	    }
   	    if (a[i] < min1)
   	    {
   	    	min1 = a[i];
   	    	z++;
   	    }

	}
	printf("%d\n", z);
	return 0;
}