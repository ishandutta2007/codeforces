using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Paths_in_Binary_Tree
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int q = Convert.ToInt32(input[1]);
            long n = Convert.ToInt64(input[0]);
            long v;
            string command;
            int height;
            long place;
            for (int i = 0; i < q; i++)
            {
                v = long.Parse(Console.ReadLine());
                command = Console.ReadLine();
                height = FindHeight(v);
                for (int j = 0; j < command.Length; j++)
                {
                    if (command[j] == 'U' && v == (n + 1) / 2) continue;
                    if (command[j] != 'U' && height == 1) continue;

                    if (command[j] == 'U')
                    {
                        place = (v / ((long)1 << (height - 1)) + 1) / 2;
                        if (place % 2 == 1) // left inner node
                            v += ((long)1 << (height - 1));
                        else
                            v -= ((long)1 << (height - 1));
                        height++;
                    }
                    else if (command[j] == 'L')
                    {
                        v -= ((long)1 << (height - 2));
                        height--;
                    }
                    else
                    {
                        v += ((long)1 << (height - 2));
                        height--;
                    }
                }
                Console.WriteLine(v);
            }
        }
        static int FindHeight(long v)
        {
            long i = 2; int h = 1;
            while (v % i == 0)
            {
                h++;
                i *= 2;
            }
            return h;
        }
    }
}