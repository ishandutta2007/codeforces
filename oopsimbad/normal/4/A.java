import java.util.*;
public class A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        if(n == 2 || n%2 == 1)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}