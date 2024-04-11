#include <iostream>
#include <vector>

using namespace std;

int getEnd(bool** matrix)
{
   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         if (matrix[i][j])
            return j;
   return -1;
}

int next(bool*** dp, int finger, int note)
{
   for (int i = 0; i < 5; i++)
   {
      if (dp[note][i][finger])
         return i;
   }
}

int main()
{
   int n;
   cin >> n;
   int* notes = new int[n];
   for (int i = 0; i < n; i++)
   {
      cin >> notes[i];
   }

   bool*** dp = new bool**[n];
   for (int i = 0; i < n; i++)
   {
      dp[i] = new bool*[5];
      for (int j = 0; j < 5; j++)
      {
         dp[i][j] = new bool[5];
         fill(dp[i][j], dp[i][j] + 5, true);
      }
   }

   for (int i = 1; i < n; i++)
   {
      for (int lastFinger = 0; lastFinger < 5; lastFinger++)
      {
         for (int curFinger = 0; curFinger < 5; curFinger++)
         {
            if (notes[i] > notes[i-1])
            {
               dp[i][lastFinger][curFinger] = false;
               if (curFinger > lastFinger)
               {
                  for (int j = 0; j < 5; j++)
                     if (dp[i-1][j][lastFinger])
                        dp[i][lastFinger][curFinger] = true;
               }
            }
            else if (notes[i] < notes[i-1])
            {
               dp[i][lastFinger][curFinger] = false;
               if (curFinger < lastFinger)
               {
                  for (int j = 0; j < 5; j++)
                     if (dp[i-1][j][lastFinger])
                        dp[i][lastFinger][curFinger] = true;
               }
            }
            else
            {
               dp[i][lastFinger][curFinger] = false;
               if (curFinger != lastFinger)
               {
                  for (int j = 0; j < 5; j++)
                     if (dp[i-1][j][lastFinger])
                        dp[i][lastFinger][curFinger] = true;
               }
            }
         }
      }
   }

   int finger = getEnd(dp[n-1]);
   if (finger == -1)
   {
      cout << -1;
   }
   else
   {
      vector<int> stack;

      stack.push_back(finger);
      for (int i = n-1; i >= 1; i--)
      {
         finger = next(dp, finger, i);
         stack.push_back(finger);
      }

      while (!stack.empty())
      {
         cout << stack.back() + 1 << " ";
         stack.pop_back();
      }
   }

   return 0;
}