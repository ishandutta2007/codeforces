#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
  int n, m, count=0;
  cin >> n >> m;
  int file1[n];
  int file2[m];

  for (int i = 0; i < n; i++)
    {
      cin >> file1[i];
    }
  for (int i = 0; i < m; i++)
    {
      cin >> file2[i];
    }
  long sum1 = file1[0], sum2 = file2[0];
  int j = 1, k = 1;
  while (j != n || k != m)
    {
      if (sum1 == sum2)
	{
	  count++;
	  sum2 += file2[k];
	  k++;
	  sum1 += file1[j];
	  j++;
	}
      else if (sum1 > sum2)
	{
	  sum2 += file2[k];
	  k++;
	}
      else
	{
	  sum1 += file1[j];
	  j++;
	}
    }
    cout<<count+1<<endl;
  return 0;
}