 import java.math.BigInteger;
import java.util.*;

public class ASD {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = sc.nextBigInteger();
        if(a.compareTo(BigInteger.valueOf(-128)) >= 0 && a.compareTo(BigInteger.valueOf(127)) <= 0)
            System.out.println("byte");
        else if(a.compareTo(BigInteger.valueOf(-32768)) >= 0 && a.compareTo(BigInteger.valueOf(32767)) <= 0)
            System.out.println("short");
        else if(a.compareTo(BigInteger.valueOf(-2147483648)) >= 0 && a.compareTo(BigInteger.valueOf(2147483647)) <= 0)
            System.out.println("int");
        else if(a.compareTo(BigInteger.valueOf(-9223372036854775808L)) >= 0 && a.compareTo(BigInteger.valueOf(9223372036854775807L)) <= 0)
            System.out.println("long");
        else System.out.println("BigInteger "); 
    }
}