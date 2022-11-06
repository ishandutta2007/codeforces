#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int n, k;
   scanf("%d %d", &n, &k);
   int* arr = new int[101];
   fill(arr, arr + 101, 0);
   int utensils = 0;
   for (int i = 0; i < n; i++)
   {
      int type;
      scanf("%d", &type);
      arr[type]++;
      if (arr[type] == 1)
         utensils++;
   }

   int dishes = 1;
   for (int i = 1; i <= 100; i++)
   {
      if (ceil(arr[i] / static_cast<double>(k)) > dishes)
      {
         dishes = ceil(arr[i] / static_cast<double>(k));
      }
   }

   printf("%d", k * dishes * utensils - n);



   return 0;
}