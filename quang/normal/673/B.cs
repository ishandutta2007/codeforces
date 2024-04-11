using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Codeforces
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] tmp = Console.ReadLine().Split(' ');
            int n = int.Parse(tmp[0]), m = int.Parse(tmp[1]);
            int l = 1, r = n;
            for (int i = 0; i < m; i++)
            {
                tmp = Console.ReadLine().Split(' ');
                int u = int.Parse(tmp[0]);
                int v = int.Parse(tmp[1]);
                if (u > v)
                {
                    int foo = u;
                    u = v;
                    v = foo;
                }
                l = Math.Max(l, u);
                r = Math.Min(r, v);
            }
            Console.WriteLine(Math.Max(0, r - l));
            //Console.ReadKey();
        }
    }
}