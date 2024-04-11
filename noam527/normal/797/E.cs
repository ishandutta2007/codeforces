using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Array_Queries
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = new int[n];
            string[] input = Console.ReadLine().Split(' ');
            arr = input.Select(x => int.Parse(x)).ToArray();
            int[,] dp = new int[(int)Math.Ceiling(Math.Sqrt(n)), n];
            for (int i = 0; i < dp.GetLength(0); i++)
                for (int j = n - 1; j >= 0; j--)
                    if (j + 1 + arr[j] + i + 1 > n)
                        dp[i, j] = 1;
                    else
                        dp[i, j] = dp[i, j + 1 + arr[j] + i] + 1;
            int q = int.Parse(Console.ReadLine()), p, k, operations;
            for (int i = 0; i < q; i++)
            {
                input = Console.ReadLine().Split(' ');
                p = int.Parse(input[0]); k = int.Parse(input[1]);
                if ((long)k * k <= n)
                    Console.WriteLine(dp[k - 1, p - 1]);
                else
                {
                    operations = 0;
                    while (p <= n)
                    {
                        p += k + arr[p - 1];
                        operations++;
                    }
                    Console.WriteLine(operations);
                }
            }
        }
        static void ShowArray(int[] a)
        {
            for (int i = 0; i < a.Length; i++)
                Console.Write(a[i] + " ");
            Console.WriteLine();
        }
    }
}