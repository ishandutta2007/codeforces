import java.util.Scanner;
public class project{
    public static void main(String[]args){
	Scanner s = new Scanner(System.in);
	int n =s.nextInt();
	if(n % 2 == 1){
	    n -= 3;
	    System.out.print('7');
	}
	while(n > 0){
	    System.out.print('1');
	    n -= 2;
	}
	System.out.println();
    }
}