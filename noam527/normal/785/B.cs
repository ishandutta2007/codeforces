using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Anton_and_Classes
{
    class Program
    {
        static void Main(string[] args)
        {
            int max1, min1, max2, min2;
            int n = int.Parse(Console.ReadLine());
            string input = Console.ReadLine();
            min1 = Convert.ToInt32(input.Split(' ')[1]);
            max1 = Convert.ToInt32(input.Split(' ')[0]);
            for (int i = 0; i < n - 1; i++)
            {
                input = Console.ReadLine();
                min1 = Math.Min(min1, Convert.ToInt32(input.Split(' ')[1]));
                max1 = Math.Max(max1, Convert.ToInt32(input.Split(' ')[0]));
            }
            int m = int.Parse(Console.ReadLine());
            input = Console.ReadLine();
            min2 = Convert.ToInt32(input.Split(' ')[1]);
            max2 = Convert.ToInt32(input.Split(' ')[0]);
            for (int i = 0; i < m - 1; i++)
            {
                input = Console.ReadLine();
                min2 = Math.Min(min2, Convert.ToInt32(input.Split(' ')[1]));
                max2 = Math.Max(max2, Convert.ToInt32(input.Split(' ')[0]));
            }
            Console.WriteLine(Math.Max(max1 - min2, Math.Max(0, max2 - min1)));
        }
    }
}