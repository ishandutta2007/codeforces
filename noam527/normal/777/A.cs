using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shell_Game
{
    class Program
    {
        static void Main(string[] args)
        {
            int switches = int.Parse(Console.ReadLine()) % 6;
            int loc = int.Parse(Console.ReadLine());
            if (switches % 2 == 1 && loc < 2)
                loc = 1 - loc;
            switches = switches / 2 * 2;
            while (switches > 0)
            {
                loc = (loc + 1) % 3;
                switches -= 2;
            }
            Console.WriteLine(loc);

        }
    }
}