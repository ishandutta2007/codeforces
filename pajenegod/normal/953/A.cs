using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;



class Solution {


    static void Main(String[] args) {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int l = Convert.ToInt32(tokens_n[0]);
        int r = Convert.ToInt32(tokens_n[1]);
       
        int count = 0;
        long twos = 1;
        while (twos<=r)
        {
            long trees = 1;
            while (twos*trees<l) trees*=3;
            while (twos*trees<=r)
            {
                trees*=3;
                ++count;
            }
            twos*=2;
        }


        Console.WriteLine(count);
    }
}