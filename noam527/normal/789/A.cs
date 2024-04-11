using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pebbles
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(input[0]), p = Convert.ToInt32(input[1]);
            int total = n; // amount of stacks
            input = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
                total += (Convert.ToInt32(input[i]) - 1) / p;
            Console.WriteLine((total + 1) / 2);
        }
    }
}