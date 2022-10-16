using System;

class Program
{
    static void Main()
    {
            int n = Convert.ToInt32(Console.ReadLine());
            // Console.WriteLine(n.ToString());
            int cur, tmp;
            int[] t = new int[123];
            for (int i = 0; i < n; i++) {
                t[i] = 0;
                for(int j = 0; j < 2; j++) {
                    tmp = Console.Read() - 48;
                    // Console.WriteLine(tmp.ToString());
                    t[i] *= 10;
                    t[i] += tmp;
                }
                t[i] *= 60;
                cur = 0;
                tmp = Console.Read();
                for(int j = 0; j < 2; j++) {
                    tmp = Console.Read() - 48;
                    // Console.WriteLine(tmp.ToString());
                    cur *= 10;
                    cur += tmp;
                }
                Console.ReadLine();
                t[i] += cur;
            }
            for (int i = n; i < 123; i++) {
                t[i] = 10000;
            }
            Array.Sort(t);
            t[n] = t[0] + 24 * 60;
            cur = 0;
            String ans;
            for (int i = 1; i <= n; i++)
                if (cur < t[i] - t[i - 1] - 1)
                    cur = t[i] - t[i - 1] - 1;
            int a = cur /60, b = cur % 60;
            if(a < 10 && b < 10){
                ans = "0" + a.ToString() + ":0" + b.ToString();
            }else if(a < 10){
                ans = "0" + a.ToString() + ":" + b.ToString();
            }else if(b < 10){
                ans = a.ToString() + ":0" + b.ToString();
            }else{
                ans = a.ToString() + ":" + b.ToString();
            }
            Console.WriteLine(ans);
    }
}