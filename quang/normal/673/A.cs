using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _673A
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] t = new int[n + 2];
            string[] a = Console.ReadLine().Split(' ');
            for (int i = 1; i <= n; i++)
            {
                t[i] = int.Parse(a[i - 1]);
            }
            t[0] = 0;
            t[n + 1] = 90;
            int res = 90;
            for (int i = 1; i <= n + 1; i++)
            {
                if (t[i] > t[i - 1] + 15)
                {
                    res = t[i - 1] + 15;
                    break;
                }
            }
            Console.WriteLine(Math.Min(res, 90));
            //Console.ReadKey();
        }
    }
}