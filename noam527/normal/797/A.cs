using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace K_Factorization
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int orign = int.Parse(input[0]), k = int.Parse(input[1]);
            int n = orign;
            int sum = 0, index = 2, mult = 1;
            string answer = "";
            while (sum + 1 < k && index <= Math.Sqrt(n))
            {
                if (n % index == 0 && IsPrime(index))
                {
                    while (n % index == 0 && sum + 1 < k)
                    {
                        answer += index + " ";
                        n /= index;
                        sum++;
                        mult *= index;
                    }
                }
                index++;
            }
            if (sum + 1 < k || mult == orign)
            {
                Console.WriteLine("-1");
                return;
            }
            answer += orign / mult;
            Console.WriteLine(answer);
        }
        static bool IsPrime(int x)
        {
            for (int i = 2; i <= Math.Sqrt(x); i++)
                if (x % i == 0)
                    return false;
            return true;
        }
    }
}