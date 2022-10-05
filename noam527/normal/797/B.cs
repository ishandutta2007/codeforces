using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odd_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] num = new int[n];
            num = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            /*
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (num[i] % 2 == 0 && num[i] > 0)
                    ans += num[i];
            int cnt = 0, min = 10001;
            for (int i = 0; i < n; i++)
                if (num[i] % 2 == 1 && num[i] > 0)
                {
                    cnt++;
                    ans += num[i];
                    min = Math.Min(min, num[i]);
                }
            if (cnt > 0)
            {
                if (ans % 2 == 0)

                return;
            }
            */
            int[,] max = new int[2, n];
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < n; j++)
                    max[i, j] = -10001;
            max[Math.Abs(num[0]) % 2, 0] = num[0];
            for (int i = 1; i < n; i++)
            {
                //ShowArray(max);
                //Console.WriteLine();
                max[0, i] = max[0, i - 1];
                max[1, i] = max[1, i - 1];
                if (num[i] % 2 == 0)
                {
                    max[0, i] = Math.Max(num[i], max[0, i]);
                    if (max[0, i - 1] != -10001)
                        max[0, i] = Math.Max(Math.Max(max[0, i], max[0, i - 1] + num[i]), max[0, i - 1]);
                    if (max[1, i - 1] != -10001)
                        max[1, i] = Math.Max(Math.Max(max[1, i], max[1, i - 1] + num[i]), max[1, i - 1]);
                }
                else
                {
                    max[1, i] = Math.Max(num[i], max[1, i]);
                    if (max[1, i - 1] != -10001)
                        max[0, i] = Math.Max(Math.Max(max[0, i], max[1, i - 1] + num[i]), max[0, i - 1]);
                    if (max[0, i - 1] != -10001)
                        max[1, i] = Math.Max(Math.Max(max[1, i], max[0, i - 1] + num[i]), max[1, i - 1]);
                }
            }
            //ShowArray(max);
            Console.WriteLine(max[1, n - 1]);
        }
        static void ShowArray(int[,] a)
        {
            for (int i = 0; i < a.GetLength(0); i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                    Console.Write(a[i, j] + " ");
                Console.WriteLine();
            }
        }
    }
}