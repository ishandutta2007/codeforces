using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Colored_Balls
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()), min = (int)1e9 + 1;
            int[] box = new int[n];
            string[] input = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                box[i] = Convert.ToInt32(input[i]);
                min = Math.Min(min, box[i]);
            }
            List<int> mindivs = new List<int>();
            for (int i = 1; i <= Math.Sqrt(min); i++)
                mindivs.Add(i);
            for (int i = mindivs.Count; i > 0; i--)
            {
                if (min % i == 0)
                    mindivs.Add(min / i);
                mindivs.Add(min / i + 1);
            }
            int k, l = mindivs.Count - 1;
            bool found = false;
            while (!found)
            {
                found = true;
                k = 0;
                while (found && k < box.Length)
                {
                    if (!IsPossible(mindivs[l], box[k]))
                        found = false;
                    k++;
                }
                l--;
            }
            l++;
            long total = 0;
            for (int i = 0; i < box.Length; i++)
                total += Sets((int)mindivs[l], box[i]);
            Console.WriteLine(total);
        }
        static int Sets(int x, int n) { return (((x - n % x) % x) + (n - ((x - n % x) % x) * (x - 1)) / x); }
        static bool IsPossible(long x, int n) { return (n / x != n / (x - 1) || n % x == 0); }
    }
}