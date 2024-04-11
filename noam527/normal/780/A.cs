using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Socks_On_Table
{
    class Program
    {
        static void Main(string[] args)
        {
            int onTable = 0, max = -1;
            bool[] state = new bool[int.Parse(Console.ReadLine())];
            string[] s = Console.ReadLine().Split(' ');
            for (int i = 0; i < s.Length; i++)
            {
                state[Convert.ToInt32(s[i]) - 1] = !state[Convert.ToInt32(s[i]) - 1];
                if (state[Convert.ToInt32(s[i]) - 1])
                {
                    onTable++;
                    max = Math.Max(max, onTable);
                }
                else
                    onTable--;
            }
            Console.WriteLine(max);
        }
    }
}