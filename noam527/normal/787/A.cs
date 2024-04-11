using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Monster
{
    class Program
    {
        static void Main(string[] args)
        {
            int s1, f1, s2, f2;
            string[] input = Console.ReadLine().Split(' ');
            f1 = Convert.ToInt32(input[0]); // a
            s1 = Convert.ToInt32(input[1]); // b
            input = Console.ReadLine().Split(' ');
            f2 = Convert.ToInt32(input[0]); // c
            s2 = Convert.ToInt32(input[1]); // d
            int curr = s2 - s1, y = 0;
            while (curr + f2 * y < 0)
                y++;
            while (y < f1 && (curr + f2 * y) % f1 != 0)
                y++;
            if ((curr + f2 * y) % f1 != 0)
                Console.WriteLine("-1");
            else
                Console.WriteLine(s2 + f2 * y);
        }
    }
}