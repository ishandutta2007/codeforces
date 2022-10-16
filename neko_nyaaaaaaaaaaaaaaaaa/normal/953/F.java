import java.util.Scanner;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner r = new Scanner(System.in);
    	long n = r.nextLong(), p = r.nextLong(), m = r.nextLong();
    	long ans = 0;
    	long last = 1, balance = 0;
    	while (n-- > 0) {
    	    long d = r.nextLong(), t = r.nextLong();
    	    long nonDepositDays = d - last;
    	    long keepNonPositive = balance / p;
    	    if (balance < 0) keepNonPositive = 0;
    	    if (nonDepositDays > keepNonPositive) ans += (nonDepositDays - keepNonPositive);
    	    balance -= p * nonDepositDays;
    	    balance += t; balance -= p;
    	    if (balance < 0) ans++;
    	    last = d + 1;
    	}
    	long nonDepositDays = m+1 - last;
	    long keepNonPositive = balance / p;
	    if (balance < 0) keepNonPositive = 0;
	    if (nonDepositDays > keepNonPositive) ans += (nonDepositDays - keepNonPositive);
	    balance -= p * nonDepositDays;
	    System.out.println(ans);
	}
}