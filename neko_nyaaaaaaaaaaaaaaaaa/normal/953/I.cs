using System;
using System.Collections.Generic;
 
public class Test
{
	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		List<int> Time = new List<int>();
		for (int i=0; i<n; i++) {
		    string Alarm = Console.ReadLine();
		    int Hour = int.Parse(Alarm.Substring(0, 2));
		    int Minute = int.Parse(Alarm.Substring(3, 2));
		    Time.Add(Hour*60+Minute);
		    Time.Add(Hour*60+Minute-1440);
		    Time.Add(Hour*60+Minute+1440);
		}
		int ans = 0;
		Time.Sort();
		for (int i=1; i<Time.Count-1; i++) {
		    if (ans < Time[i] - Time[i-1] - 1) {
		        ans = Time[i] - Time[i-1] - 1;
		    }
		}
		String z1 = (ans / 60).ToString(); if (z1.Length == 1) z1 = z1.Insert(0, "0");
		String z2 = (ans % 60).ToString(); if (z2.Length == 1) z2 = z2.Insert(0, "0");
		Console.WriteLine("{0}:{1}", z1, z2);
	}
}