import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		Arrays.sort(a);
		int pos = 0;
		while(pos < n && a[pos]==a[0]) pos++;
		
		if(pos==n)
			pw.println("NO");
		else pw.println(a[pos]);
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}