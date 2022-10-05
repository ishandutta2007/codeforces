using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Divisible_by_10_to_K
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] stringArray = input.Split(' ');
            int n = Convert.ToInt32(stringArray[0]), k = Convert.ToInt32(stringArray[1]), cnt1 = 0, cnt2 = 0;
            while (n > 0 && cnt2 < k) {
                cnt1++;
                if (n % 10 == 0)
                    cnt2++;
                n /= 10;
            }
            if (cnt2 < k && cnt1 > 0)
                Console.WriteLine(cnt1 - 1);
            else if (cnt1 == 0)
                Console.WriteLine("0");
            else
                Console.WriteLine(cnt1 - cnt2);
        }
    }
}