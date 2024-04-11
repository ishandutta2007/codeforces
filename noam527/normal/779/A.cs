using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Student_Exchange
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()), i;
            string s1 = Console.ReadLine(), s2 = Console.ReadLine();
            string[] s3 = s1.Split(' '), s4 = s2.Split(' ');
            int[] A = new int[s3.Length], B = new int[s4.Length], C = new int[10];
            for (i = 0; i < s3.Length; i++)
            {
                A[i] = Convert.ToInt32(s3[i]);
                B[i] = Convert.ToInt32(s4[i]);
                C[A[i] - 1]++;
                C[B[i] + 4]++;
            }
            i = 0;
            int total = 0;
            bool ok = true;
            while (i < 5 && ok)
            {
                if ((C[i] + C[i + 5]) % 2 == 1)
                    ok = false;
                total += Math.Abs(C[i] - C[i + 5]);
                i++;
            }
            if (!ok)
                Console.WriteLine("-1");
            else
                Console.WriteLine(total / 4);
        }
    }
}