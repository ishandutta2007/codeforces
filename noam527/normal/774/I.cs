using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Composing_of_String
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] builders = new string[n];
            for (int i = 0; i < n; i++)
                builders[i] = Console.ReadLine();
            string s = Console.ReadLine();
            int bynow = 0, max = 1, next, operations = 0, j;
            while (bynow < s.Length && max > 0)
            {
                max = 0;
                for (int i = 0; i < builders.Length; i++)
                {
                    next = bynow;
                    j = 0;
                    while (j < builders[i].Length && next < s.Length)
                    {
                        if (builders[i][j] == s[next])
                            next++;
                        j++;
                    }
                    max = Math.Max(max, next - bynow);
                }
                bynow += max;
                operations++;
            }
            if (bynow < s.Length)
            {
                Console.WriteLine("-1");
                return;
            }
            Console.WriteLine(operations);
        }
    }
}