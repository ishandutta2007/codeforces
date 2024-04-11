import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
			
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            
            int x1 = in.nextInt(); int x2 = in.nextInt(); int x3 = in.nextInt();
            int y1 = in.nextInt(); int y2 = in.nextInt(); int y3 = in.nextInt();
            
            int x = (x1-y1)*(x1-y1)+(x2-y2)*(x2-y2)+(x3-y3)*(x3-y3);
            pw.println(x<=2?"YES":"NO");
            
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}